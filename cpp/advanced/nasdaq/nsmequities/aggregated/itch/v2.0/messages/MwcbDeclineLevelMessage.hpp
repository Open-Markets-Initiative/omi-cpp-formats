#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Level1.hpp"
#include "../types/Level2.hpp"
#include "../types/Level3.hpp"

namespace nasdaq::nsmequities::aggregated::itch::v2_0 {

namespace itch_aggregated = ::nasdaq::nsmequities::aggregated::itch::v2_0;

#pragma pack(push, 1)

// Mwcb Decline Level Message
struct mwcb_decline_level_message {

    struct fields_type {
        itch_aggregated::tracking_number tracking_number;
        itch_aggregated::timestamp timestamp;
        itch_aggregated::level_1 level_1;
        itch_aggregated::level_2 level_2;
        itch_aggregated::level_3 level_3;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::mwcb_decline_level_message};

    fields_type fields;

    // parse method
    static mwcb_decline_level_message* parse(std::byte* buffer) {
        return reinterpret_cast<mwcb_decline_level_message*>(buffer);
    }

    // parse method const
    static const mwcb_decline_level_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const mwcb_decline_level_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(mwcb_decline_level_message::fields_type, tracking_number) == 0, "unexpected offset of mwcb_decline_level_message::fields_type::tracking_number");
static_assert(offsetof(mwcb_decline_level_message::fields_type, timestamp) == 2, "unexpected offset of mwcb_decline_level_message::fields_type::timestamp");
static_assert(offsetof(mwcb_decline_level_message::fields_type, level_1) == 8, "unexpected offset of mwcb_decline_level_message::fields_type::level_1");
static_assert(offsetof(mwcb_decline_level_message::fields_type, level_2) == 16, "unexpected offset of mwcb_decline_level_message::fields_type::level_2");
static_assert(offsetof(mwcb_decline_level_message::fields_type, level_3) == 24, "unexpected offset of mwcb_decline_level_message::fields_type::level_3");
static_assert(sizeof(mwcb_decline_level_message::fields_type) == 32, "unexpected sizeof mwcb_decline_level_message::fields_type");
static_assert(sizeof(mwcb_decline_level_message) == sizeof(message_header) + 32, "unexpected sizeof mwcb_decline_level_message");

#pragma pack(pop)
}
