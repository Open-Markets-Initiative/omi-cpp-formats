#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/EventCode.hpp"

namespace nasdaq::nsmequities::noiview::itch::v3_0_2026 {

namespace itch_noiview = ::nasdaq::nsmequities::noiview::itch::v3_0_2026;

#pragma pack(push, 1)

// System Event
struct system_event {

    struct fields_type {
        itch_noiview::tracking_number tracking_number;
        itch_noiview::timestamp timestamp;
        itch_noiview::event_code event_code;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::system_event};

    fields_type fields;

    // parse method
    static system_event* parse(std::byte* buffer) {
        return reinterpret_cast<system_event*>(buffer);
    }

    // parse method const
    static const system_event* parse(const std::byte* buffer) {
        return reinterpret_cast<const system_event*>(buffer);
    }

};

// layout verification
static_assert(offsetof(system_event::fields_type, tracking_number) == 0, "unexpected offset of system_event::fields_type::tracking_number");
static_assert(offsetof(system_event::fields_type, timestamp) == 2, "unexpected offset of system_event::fields_type::timestamp");
static_assert(offsetof(system_event::fields_type, event_code) == 8, "unexpected offset of system_event::fields_type::event_code");
static_assert(sizeof(system_event::fields_type) == 9, "unexpected sizeof system_event::fields_type");
static_assert(sizeof(system_event) == sizeof(message_header) + 9, "unexpected sizeof system_event");

#pragma pack(pop)
}
