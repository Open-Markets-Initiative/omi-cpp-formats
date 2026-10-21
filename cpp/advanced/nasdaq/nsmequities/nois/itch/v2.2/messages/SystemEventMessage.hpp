#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/EventCode.hpp"
#include "../types/MessageLength.hpp"

namespace nasdaq::nsmequities::nois::itch::v2_2 {

namespace itch_nois = ::nasdaq::nsmequities::nois::itch::v2_2;

#pragma pack(push, 1)

// System Event Message
struct system_event_message {

    struct fields_type {
        itch_nois::event_code event_code;
    };

    // Transport framing: message size precedes the SBE header on the wire
    itch_nois::message_length message_length;
    itch_nois::message_header header = {{}, message_type::enum_type::system_event_message};

    fields_type fields;

    // parse method
    static system_event_message* parse(std::byte* buffer) {
        return reinterpret_cast<system_event_message*>(buffer);
    }

    // parse method const
    static const system_event_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const system_event_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(system_event_message::fields_type, event_code) == 0, "unexpected offset of system_event_message::fields_type::event_code");
static_assert(sizeof(system_event_message::fields_type) == 1, "unexpected sizeof system_event_message::fields_type");
static_assert(sizeof(system_event_message) == sizeof(itch_nois::message_length) + sizeof(itch_nois::message_header) + 1, "unexpected sizeof system_event_message");

#pragma pack(pop)
}
