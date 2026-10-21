#pragma once

#include <cstddef>
#include "../types/Session.hpp"
#include "../types/SequenceNumber.hpp"
#include "../types/MessageCount.hpp"

namespace nasdaq::nsmequities::nois::itch::v2_2 {

namespace itch_nois = ::nasdaq::nsmequities::nois::itch::v2_2;

#pragma pack(push, 1)

struct packet_header {

    itch_nois::session session;
    itch_nois::sequence_number sequence_number;
    itch_nois::message_count message_count;

    // parse method
    static packet_header* parse(std::byte* buffer) {
        return reinterpret_cast<packet_header*>(buffer);
    }

    // parse method const
    static const packet_header* parse(const std::byte* buffer) {
        return reinterpret_cast<const packet_header*>(buffer);
    }
};

// layout verification
static_assert(offsetof(packet_header, session) == 0, "unexpected offset of packet_header::session");
static_assert(offsetof(packet_header, sequence_number) == 10, "unexpected offset of packet_header::sequence_number");
static_assert(offsetof(packet_header, message_count) == 14, "unexpected offset of packet_header::message_count");
static_assert(sizeof(packet_header) == 16, "unexpected sizeof packet_header");

#pragma pack(pop)
}
