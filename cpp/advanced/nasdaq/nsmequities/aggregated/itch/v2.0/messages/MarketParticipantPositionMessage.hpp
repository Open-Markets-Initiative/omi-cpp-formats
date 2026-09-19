#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Mpid.hpp"
#include "../types/Stock.hpp"
#include "../types/PrimaryMarketMaker.hpp"
#include "../types/MarketMakerMode.hpp"
#include "../types/MarketParticipantState.hpp"

namespace nasdaq::nsmequities::aggregated::itch::v2_0 {

namespace itch_aggregated = ::nasdaq::nsmequities::aggregated::itch::v2_0;

#pragma pack(push, 1)

// Market Participant Position Message
struct market_participant_position_message {

    struct fields_type {
        itch_aggregated::tracking_number tracking_number;
        itch_aggregated::timestamp timestamp;
        itch_aggregated::mpid mpid;
        itch_aggregated::stock stock;
        itch_aggregated::primary_market_maker primary_market_maker;
        itch_aggregated::market_maker_mode market_maker_mode;
        itch_aggregated::market_participant_state market_participant_state;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::market_participant_position_message};

    fields_type fields;

    // parse method
    static market_participant_position_message* parse(std::byte* buffer) {
        return reinterpret_cast<market_participant_position_message*>(buffer);
    }

    // parse method const
    static const market_participant_position_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const market_participant_position_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(market_participant_position_message::fields_type, tracking_number) == 0, "unexpected offset of market_participant_position_message::fields_type::tracking_number");
static_assert(offsetof(market_participant_position_message::fields_type, timestamp) == 2, "unexpected offset of market_participant_position_message::fields_type::timestamp");
static_assert(offsetof(market_participant_position_message::fields_type, mpid) == 8, "unexpected offset of market_participant_position_message::fields_type::mpid");
static_assert(offsetof(market_participant_position_message::fields_type, stock) == 12, "unexpected offset of market_participant_position_message::fields_type::stock");
static_assert(offsetof(market_participant_position_message::fields_type, primary_market_maker) == 20, "unexpected offset of market_participant_position_message::fields_type::primary_market_maker");
static_assert(offsetof(market_participant_position_message::fields_type, market_maker_mode) == 21, "unexpected offset of market_participant_position_message::fields_type::market_maker_mode");
static_assert(offsetof(market_participant_position_message::fields_type, market_participant_state) == 22, "unexpected offset of market_participant_position_message::fields_type::market_participant_state");
static_assert(sizeof(market_participant_position_message::fields_type) == 23, "unexpected sizeof market_participant_position_message::fields_type");
static_assert(sizeof(market_participant_position_message) == sizeof(message_header) + 23, "unexpected sizeof market_participant_position_message");

#pragma pack(pop)
}
