#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/Symbol.hpp"
#include "../types/TradingState.hpp"
#include "../types/Reason.hpp"
#include "../types/MessageLength.hpp"

namespace nasdaq::nsmequities::nois::itch::v2_2 {

namespace itch_nois = ::nasdaq::nsmequities::nois::itch::v2_2;

#pragma pack(push, 1)

// Stock Trading Action
struct stock_trading_action {

    struct fields_type {
        itch_nois::symbol symbol;
        itch_nois::trading_state trading_state;
        itch_nois::reason reason;
    };

    // Transport framing: message size precedes the SBE header on the wire
    itch_nois::message_length message_length;
    itch_nois::message_header header = {{}, message_type::enum_type::stock_trading_action};

    fields_type fields;

    // parse method
    static stock_trading_action* parse(std::byte* buffer) {
        return reinterpret_cast<stock_trading_action*>(buffer);
    }

    // parse method const
    static const stock_trading_action* parse(const std::byte* buffer) {
        return reinterpret_cast<const stock_trading_action*>(buffer);
    }

};

// layout verification
static_assert(offsetof(stock_trading_action::fields_type, symbol) == 0, "unexpected offset of stock_trading_action::fields_type::symbol");
static_assert(offsetof(stock_trading_action::fields_type, trading_state) == 8, "unexpected offset of stock_trading_action::fields_type::trading_state");
static_assert(offsetof(stock_trading_action::fields_type, reason) == 9, "unexpected offset of stock_trading_action::fields_type::reason");
static_assert(sizeof(stock_trading_action::fields_type) == 10, "unexpected sizeof stock_trading_action::fields_type");
static_assert(sizeof(stock_trading_action) == sizeof(itch_nois::message_length) + sizeof(itch_nois::message_header) + 10, "unexpected sizeof stock_trading_action");

#pragma pack(pop)
}
