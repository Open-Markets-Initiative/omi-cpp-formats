#pragma once

#include <cstddef>
#include "../types/Timestamp.hpp"
#include "../types/MessageType.hpp"

namespace nasdaq::nsmequities::nois::itch::v2_2 {

namespace itch_nois = ::nasdaq::nsmequities::nois::itch::v2_2;

#pragma pack(push, 1)

struct message_header {

    itch_nois::timestamp timestamp;
    itch_nois::message_type message_type;

    // parse method
    static message_header* parse(std::byte* buffer) {
        return reinterpret_cast<message_header*>(buffer);
    }

    // parse method const
    static const message_header* parse(const std::byte* buffer) {
        return reinterpret_cast<const message_header*>(buffer);
    }
};

// layout verification
static_assert(offsetof(message_header, timestamp) == 0, "unexpected offset of message_header::timestamp");
static_assert(offsetof(message_header, message_type) == 8, "unexpected offset of message_header::message_type");
static_assert(sizeof(message_header) == 9, "unexpected sizeof message_header");

#pragma pack(pop)
}
