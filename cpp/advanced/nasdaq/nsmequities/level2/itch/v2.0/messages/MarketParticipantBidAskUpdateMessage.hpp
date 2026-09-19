#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/MarketSide.hpp"
#include "../types/ParticipantShares.hpp"
#include "../types/Stock.hpp"
#include "../types/Price.hpp"
#include "../types/Mpid.hpp"

namespace nasdaq::nsmequities::level2::itch::v2_0 {

namespace itch_level2 = ::nasdaq::nsmequities::level2::itch::v2_0;

#pragma pack(push, 1)

// Market Participant Bid Ask Update Message
struct market_participant_bid_ask_update_message {

    struct fields_type {
        itch_level2::tracking_number tracking_number;
        itch_level2::timestamp timestamp;
        itch_level2::market_side market_side;
        itch_level2::participant_shares participant_shares;
        itch_level2::stock stock;
        itch_level2::price price;
        itch_level2::mpid mpid;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::market_participant_bid_ask_update_message};

    fields_type fields;

    // parse method
    static market_participant_bid_ask_update_message* parse(std::byte* buffer) {
        return reinterpret_cast<market_participant_bid_ask_update_message*>(buffer);
    }

    // parse method const
    static const market_participant_bid_ask_update_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const market_participant_bid_ask_update_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(market_participant_bid_ask_update_message::fields_type, tracking_number) == 0, "unexpected offset of market_participant_bid_ask_update_message::fields_type::tracking_number");
static_assert(offsetof(market_participant_bid_ask_update_message::fields_type, timestamp) == 2, "unexpected offset of market_participant_bid_ask_update_message::fields_type::timestamp");
static_assert(offsetof(market_participant_bid_ask_update_message::fields_type, market_side) == 8, "unexpected offset of market_participant_bid_ask_update_message::fields_type::market_side");
static_assert(offsetof(market_participant_bid_ask_update_message::fields_type, participant_shares) == 9, "unexpected offset of market_participant_bid_ask_update_message::fields_type::participant_shares");
static_assert(offsetof(market_participant_bid_ask_update_message::fields_type, stock) == 13, "unexpected offset of market_participant_bid_ask_update_message::fields_type::stock");
static_assert(offsetof(market_participant_bid_ask_update_message::fields_type, price) == 21, "unexpected offset of market_participant_bid_ask_update_message::fields_type::price");
static_assert(offsetof(market_participant_bid_ask_update_message::fields_type, mpid) == 25, "unexpected offset of market_participant_bid_ask_update_message::fields_type::mpid");
static_assert(sizeof(market_participant_bid_ask_update_message::fields_type) == 29, "unexpected sizeof market_participant_bid_ask_update_message::fields_type");
static_assert(sizeof(market_participant_bid_ask_update_message) == sizeof(message_header) + 29, "unexpected sizeof market_participant_bid_ask_update_message");

#pragma pack(pop)
}
