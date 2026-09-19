#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/BreachedLevel.hpp"

namespace nasdaq::nsmequities::level2::itch::v2_0 {

namespace itch_level2 = ::nasdaq::nsmequities::level2::itch::v2_0;

#pragma pack(push, 1)

// Market Wide Circuit Breaker Status Message
struct market_wide_circuit_breaker_status_message {

    struct fields_type {
        itch_level2::tracking_number tracking_number;
        itch_level2::timestamp timestamp;
        itch_level2::breached_level breached_level;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::market_wide_circuit_breaker_status_message};

    fields_type fields;

    // parse method
    static market_wide_circuit_breaker_status_message* parse(std::byte* buffer) {
        return reinterpret_cast<market_wide_circuit_breaker_status_message*>(buffer);
    }

    // parse method const
    static const market_wide_circuit_breaker_status_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const market_wide_circuit_breaker_status_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(market_wide_circuit_breaker_status_message::fields_type, tracking_number) == 0, "unexpected offset of market_wide_circuit_breaker_status_message::fields_type::tracking_number");
static_assert(offsetof(market_wide_circuit_breaker_status_message::fields_type, timestamp) == 2, "unexpected offset of market_wide_circuit_breaker_status_message::fields_type::timestamp");
static_assert(offsetof(market_wide_circuit_breaker_status_message::fields_type, breached_level) == 8, "unexpected offset of market_wide_circuit_breaker_status_message::fields_type::breached_level");
static_assert(sizeof(market_wide_circuit_breaker_status_message::fields_type) == 9, "unexpected sizeof market_wide_circuit_breaker_status_message::fields_type");
static_assert(sizeof(market_wide_circuit_breaker_status_message) == sizeof(message_header) + 9, "unexpected sizeof market_wide_circuit_breaker_status_message");

#pragma pack(pop)
}
