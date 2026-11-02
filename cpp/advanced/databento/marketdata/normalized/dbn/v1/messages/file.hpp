#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <initializer_list>
#include <stdexcept>
#include <vector>

#include "../structs/Record.hpp"
#include "dispatch.hpp"

namespace databento::marketdata::normalized::dbn::v1 {

// Read a file of records: what it opens with (Metadata), once, then every
// record to its end, each framed by its Record Length
// Handler must implement:
// on_message(const <message_type>&, std::uint64_t packet_receive_time, const record&)  - called per record (via dispatch); a file has no receive time, so it is 0
// Reader: std::size_t reader(std::byte* into, std::size_t most)  - the file's next bytes, decompressed; 0 at its end

namespace file_layer {

// an unsigned number of the width given, in the byte order given
inline std::uint64_t unsigned_at(const std::byte* at, const std::size_t width, const bool big) {
    std::uint64_t value = 0;
    for (std::size_t index = 0; index < width; ++index) {
        std::size_t position = width - 1 - index;
        if (big) {
            position = index;
        }
        value = (value << 8) | std::to_integer<std::uint64_t>(at[position]);
    }
    return value;
}

// do the bytes at a place hold the ones given
inline bool holds(const std::byte* at, const std::initializer_list<std::uint8_t> bytes) {
    for (const auto byte : bytes) {
        if (std::to_integer<std::uint8_t>(*at++) != byte) {
            return false;
        }
    }
    return true;
}

// is the file one of this model's: Magic DBN at 0, Version 1 at 3
inline bool recognised(const std::byte* data, const std::size_t length) {
    if (length < 4) {
        return false;
    }
    // Magic at 0: DBN
    if (!holds(data + 0, { 0x44, 0x42, 0x4E })) {
        return false;
    }
    // Version at 3: 1
    if (!holds(data + 3, { 0x01 })) {
        return false;
    }
    return true;
}

// the bytes what the file opens with spans: false while the bytes given do not reach a length it is read from
inline bool opening(const std::byte* data, const std::size_t length, std::size_t& bytes) {
    bytes = 0;
    // Metadata
    if (length < bytes + 8) {
        return false;
    }
    bytes += static_cast<std::size_t>(unsigned_at(data + bytes + 4, 4, false) + 8);
    return true;
}

// the bytes a record's length and type are read from
inline constexpr std::size_t header = 2;

// the bytes a record spans, read from its Record Length
inline std::size_t framed(const std::byte* record) {
    return static_cast<std::size_t>(unsigned_at(record + 0, 1, false) * 4);
}

}

// Read every record of a file through the reader, a run of bytes at a time, and dispatch each
// into the handler. Throws when the file is not one of this model's, or ends inside a record.
// Returns the records read.
template<typename Handler, typename Reader>
std::uint64_t process_file(Handler& handler, Reader&& reader) {
    std::vector<std::byte> buffer(std::size_t{ 1 } << 20);
    std::size_t filled = 0;
    bool ended = false;

    // read after the bytes held until the buffer is full or the file ends
    const auto fill = [&]() {
        while (!ended && filled < buffer.size()) {
            const std::size_t read = reader(buffer.data() + filled, buffer.size() - filled);
            ended = read == 0;
            filled += read;
        }
    };

    fill();

    if (!file_layer::recognised(buffer.data(), filled)) {
        throw std::runtime_error("not a Databento.MarketData.Normalized.Dbn.v1 file: Magic DBN at 0, Version 1 at 3");
    }

    // what the file opens with, stepped over once: the buffer grows until it holds all of it
    std::size_t start = 0;

    while (!file_layer::opening(buffer.data(), filled, start) || start > filled) {
        if (ended) {
            throw std::runtime_error("the file ends inside what it opens with");
        }

        buffer.resize(buffer.size() * 2);
        fill();
    }

    std::uint64_t records = 0;

    for (;;) {
        // every whole record the buffer holds
        while (filled - start >= file_layer::header) {
            const std::byte* at = buffer.data() + start;
            const std::size_t total = file_layer::framed(at);

            if (total < file_layer::header) {
                throw std::runtime_error("a record frames fewer bytes than its length and type");
            }

            if (total > filled - start) {
                break;
            }

            dispatch(handler, at, total, 0, *record::parse(at));
            start += total;
            ++records;
        }

        if (ended) {
            if (start != filled) {
                throw std::runtime_error("the file ends inside a record");
            }

            return records;
        }

        // keep the record the buffer ends inside at its front, growing the buffer for one that outgrows it
        std::memmove(buffer.data(), buffer.data() + start, filled - start);
        filled -= start;
        start = 0;

        if (filled == buffer.size()) {
            buffer.resize(buffer.size() * 2);
        }

        fill();
    }
}

}
