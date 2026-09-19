#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Shares.hpp"
#include "../types/Stock.hpp"
#include "../types/CrossPrice.hpp"
#include "../types/MatchNumber.hpp"
#include "../types/CrossType.hpp"

namespace nasdaq::nsmequities::noiview::itch::v3_0_2026 {

namespace itch_noiview = ::nasdaq::nsmequities::noiview::itch::v3_0_2026;

#pragma pack(push, 1)

// Cross Trade Message
struct cross_trade_message {

    struct fields_type {
        itch_noiview::tracking_number tracking_number;
        itch_noiview::timestamp timestamp;
        itch_noiview::shares shares;
        itch_noiview::stock stock;
        itch_noiview::cross_price cross_price;
        itch_noiview::match_number match_number;
        itch_noiview::cross_type cross_type;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::cross_trade_message};

    fields_type fields;

    // parse method
    static cross_trade_message* parse(std::byte* buffer) {
        return reinterpret_cast<cross_trade_message*>(buffer);
    }

    // parse method const
    static const cross_trade_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const cross_trade_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(cross_trade_message::fields_type, tracking_number) == 0, "unexpected offset of cross_trade_message::fields_type::tracking_number");
static_assert(offsetof(cross_trade_message::fields_type, timestamp) == 2, "unexpected offset of cross_trade_message::fields_type::timestamp");
static_assert(offsetof(cross_trade_message::fields_type, shares) == 8, "unexpected offset of cross_trade_message::fields_type::shares");
static_assert(offsetof(cross_trade_message::fields_type, stock) == 16, "unexpected offset of cross_trade_message::fields_type::stock");
static_assert(offsetof(cross_trade_message::fields_type, cross_price) == 24, "unexpected offset of cross_trade_message::fields_type::cross_price");
static_assert(offsetof(cross_trade_message::fields_type, match_number) == 28, "unexpected offset of cross_trade_message::fields_type::match_number");
static_assert(offsetof(cross_trade_message::fields_type, cross_type) == 36, "unexpected offset of cross_trade_message::fields_type::cross_type");
static_assert(sizeof(cross_trade_message::fields_type) == 37, "unexpected sizeof cross_trade_message::fields_type");
static_assert(sizeof(cross_trade_message) == sizeof(message_header) + 37, "unexpected sizeof cross_trade_message");

#pragma pack(pop)
}
