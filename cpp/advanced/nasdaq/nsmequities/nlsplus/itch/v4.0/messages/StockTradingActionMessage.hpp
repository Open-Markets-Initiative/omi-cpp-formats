#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/IssueSymbol.hpp"
#include "../types/SecurityClass.hpp"
#include "../types/CurrentTradingState.hpp"
#include "../types/Reason.hpp"

namespace nasdaq::nsmequities::nlsplus::itch::v4_0 {

namespace itch_nlsplus = ::nasdaq::nsmequities::nlsplus::itch::v4_0;

#pragma pack(push, 1)

// Stock Trading Action Message
struct stock_trading_action_message {

    struct fields_type {
        itch_nlsplus::tracking_number tracking_number;
        itch_nlsplus::timestamp timestamp;
        itch_nlsplus::issue_symbol issue_symbol;
        itch_nlsplus::security_class security_class;
        itch_nlsplus::current_trading_state current_trading_state;
        itch_nlsplus::reason reason;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::stock_trading_action_message};

    fields_type fields;

    // parse method
    static stock_trading_action_message* parse(std::byte* buffer) {
        return reinterpret_cast<stock_trading_action_message*>(buffer);
    }

    // parse method const
    static const stock_trading_action_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const stock_trading_action_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(stock_trading_action_message::fields_type, tracking_number) == 0, "unexpected offset of stock_trading_action_message::fields_type::tracking_number");
static_assert(offsetof(stock_trading_action_message::fields_type, timestamp) == 2, "unexpected offset of stock_trading_action_message::fields_type::timestamp");
static_assert(offsetof(stock_trading_action_message::fields_type, issue_symbol) == 8, "unexpected offset of stock_trading_action_message::fields_type::issue_symbol");
static_assert(offsetof(stock_trading_action_message::fields_type, security_class) == 16, "unexpected offset of stock_trading_action_message::fields_type::security_class");
static_assert(offsetof(stock_trading_action_message::fields_type, current_trading_state) == 17, "unexpected offset of stock_trading_action_message::fields_type::current_trading_state");
static_assert(offsetof(stock_trading_action_message::fields_type, reason) == 18, "unexpected offset of stock_trading_action_message::fields_type::reason");
static_assert(sizeof(stock_trading_action_message::fields_type) == 22, "unexpected sizeof stock_trading_action_message::fields_type");
static_assert(sizeof(stock_trading_action_message) == sizeof(message_header) + 22, "unexpected sizeof stock_trading_action_message");

#pragma pack(pop)
}
