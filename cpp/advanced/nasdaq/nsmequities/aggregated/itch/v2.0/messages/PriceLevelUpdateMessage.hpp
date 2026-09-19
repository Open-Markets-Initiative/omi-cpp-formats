#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/MarketSide.hpp"
#include "../types/ParticipantShares.hpp"
#include "../types/AggregateShares.hpp"
#include "../types/Stock.hpp"
#include "../types/Price.hpp"
#include "../types/Mpid.hpp"

namespace nasdaq::nsmequities::aggregated::itch::v2_0 {

namespace itch_aggregated = ::nasdaq::nsmequities::aggregated::itch::v2_0;

#pragma pack(push, 1)

// Price Level Update Message
struct price_level_update_message {

    struct fields_type {
        itch_aggregated::tracking_number tracking_number;
        itch_aggregated::timestamp timestamp;
        itch_aggregated::market_side market_side;
        itch_aggregated::participant_shares participant_shares;
        itch_aggregated::aggregate_shares aggregate_shares;
        itch_aggregated::stock stock;
        itch_aggregated::price price;
        itch_aggregated::mpid mpid;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::price_level_update_message};

    fields_type fields;

    // parse method
    static price_level_update_message* parse(std::byte* buffer) {
        return reinterpret_cast<price_level_update_message*>(buffer);
    }

    // parse method const
    static const price_level_update_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const price_level_update_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(price_level_update_message::fields_type, tracking_number) == 0, "unexpected offset of price_level_update_message::fields_type::tracking_number");
static_assert(offsetof(price_level_update_message::fields_type, timestamp) == 2, "unexpected offset of price_level_update_message::fields_type::timestamp");
static_assert(offsetof(price_level_update_message::fields_type, market_side) == 8, "unexpected offset of price_level_update_message::fields_type::market_side");
static_assert(offsetof(price_level_update_message::fields_type, participant_shares) == 9, "unexpected offset of price_level_update_message::fields_type::participant_shares");
static_assert(offsetof(price_level_update_message::fields_type, aggregate_shares) == 13, "unexpected offset of price_level_update_message::fields_type::aggregate_shares");
static_assert(offsetof(price_level_update_message::fields_type, stock) == 17, "unexpected offset of price_level_update_message::fields_type::stock");
static_assert(offsetof(price_level_update_message::fields_type, price) == 25, "unexpected offset of price_level_update_message::fields_type::price");
static_assert(offsetof(price_level_update_message::fields_type, mpid) == 29, "unexpected offset of price_level_update_message::fields_type::mpid");
static_assert(sizeof(price_level_update_message::fields_type) == 33, "unexpected sizeof price_level_update_message::fields_type");
static_assert(sizeof(price_level_update_message) == sizeof(message_header) + 33, "unexpected sizeof price_level_update_message");

#pragma pack(pop)
}
