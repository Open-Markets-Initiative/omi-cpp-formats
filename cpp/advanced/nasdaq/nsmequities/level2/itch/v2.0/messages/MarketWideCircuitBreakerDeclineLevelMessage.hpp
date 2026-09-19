#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Level1.hpp"
#include "../types/Level2.hpp"
#include "../types/Level3.hpp"

namespace nasdaq::nsmequities::level2::itch::v2_0 {

namespace itch_level2 = ::nasdaq::nsmequities::level2::itch::v2_0;

#pragma pack(push, 1)

// Market Wide Circuit Breaker Decline Level Message
struct market_wide_circuit_breaker_decline_level_message {

    struct fields_type {
        itch_level2::tracking_number tracking_number;
        itch_level2::timestamp timestamp;
        itch_level2::level_1 level_1;
        itch_level2::level_2 level_2;
        itch_level2::level_3 level_3;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::market_wide_circuit_breaker_decline_level_message};

    fields_type fields;

    // parse method
    static market_wide_circuit_breaker_decline_level_message* parse(std::byte* buffer) {
        return reinterpret_cast<market_wide_circuit_breaker_decline_level_message*>(buffer);
    }

    // parse method const
    static const market_wide_circuit_breaker_decline_level_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const market_wide_circuit_breaker_decline_level_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(market_wide_circuit_breaker_decline_level_message::fields_type, tracking_number) == 0, "unexpected offset of market_wide_circuit_breaker_decline_level_message::fields_type::tracking_number");
static_assert(offsetof(market_wide_circuit_breaker_decline_level_message::fields_type, timestamp) == 2, "unexpected offset of market_wide_circuit_breaker_decline_level_message::fields_type::timestamp");
static_assert(offsetof(market_wide_circuit_breaker_decline_level_message::fields_type, level_1) == 8, "unexpected offset of market_wide_circuit_breaker_decline_level_message::fields_type::level_1");
static_assert(offsetof(market_wide_circuit_breaker_decline_level_message::fields_type, level_2) == 16, "unexpected offset of market_wide_circuit_breaker_decline_level_message::fields_type::level_2");
static_assert(offsetof(market_wide_circuit_breaker_decline_level_message::fields_type, level_3) == 24, "unexpected offset of market_wide_circuit_breaker_decline_level_message::fields_type::level_3");
static_assert(sizeof(market_wide_circuit_breaker_decline_level_message::fields_type) == 32, "unexpected sizeof market_wide_circuit_breaker_decline_level_message::fields_type");
static_assert(sizeof(market_wide_circuit_breaker_decline_level_message) == sizeof(message_header) + 32, "unexpected sizeof market_wide_circuit_breaker_decline_level_message");

#pragma pack(pop)
}
