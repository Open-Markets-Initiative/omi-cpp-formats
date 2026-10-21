#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/Symbol.hpp"
#include "../types/MarketCategory.hpp"
#include "../types/Rfu.hpp"
#include "../types/RoundLotSize.hpp"
#include "../types/RoundLotsOnly.hpp"
#include "../types/IssueClassification.hpp"
#include "../types/IssueSubType.hpp"
#include "../types/MessageLength.hpp"

namespace nasdaq::nsmequities::nois::itch::v2_2 {

namespace itch_nois = ::nasdaq::nsmequities::nois::itch::v2_2;

#pragma pack(push, 1)

// Stock Directory
struct stock_directory {

    struct fields_type {
        itch_nois::symbol symbol;
        itch_nois::market_category market_category;
        itch_nois::rfu rfu;
        itch_nois::round_lot_size round_lot_size;
        itch_nois::round_lots_only round_lots_only;
        itch_nois::issue_classification issue_classification;
        itch_nois::issue_sub_type issue_sub_type;
    };

    // Transport framing: message size precedes the SBE header on the wire
    itch_nois::message_length message_length;
    itch_nois::message_header header = {{}, message_type::enum_type::stock_directory};

    fields_type fields;

    // parse method
    static stock_directory* parse(std::byte* buffer) {
        return reinterpret_cast<stock_directory*>(buffer);
    }

    // parse method const
    static const stock_directory* parse(const std::byte* buffer) {
        return reinterpret_cast<const stock_directory*>(buffer);
    }

};

// layout verification
static_assert(offsetof(stock_directory::fields_type, symbol) == 0, "unexpected offset of stock_directory::fields_type::symbol");
static_assert(offsetof(stock_directory::fields_type, market_category) == 8, "unexpected offset of stock_directory::fields_type::market_category");
static_assert(offsetof(stock_directory::fields_type, rfu) == 9, "unexpected offset of stock_directory::fields_type::rfu");
static_assert(offsetof(stock_directory::fields_type, round_lot_size) == 10, "unexpected offset of stock_directory::fields_type::round_lot_size");
static_assert(offsetof(stock_directory::fields_type, round_lots_only) == 16, "unexpected offset of stock_directory::fields_type::round_lots_only");
static_assert(offsetof(stock_directory::fields_type, issue_classification) == 17, "unexpected offset of stock_directory::fields_type::issue_classification");
static_assert(offsetof(stock_directory::fields_type, issue_sub_type) == 18, "unexpected offset of stock_directory::fields_type::issue_sub_type");
static_assert(sizeof(stock_directory::fields_type) == 20, "unexpected sizeof stock_directory::fields_type");
static_assert(sizeof(stock_directory) == sizeof(itch_nois::message_length) + sizeof(itch_nois::message_header) + 20, "unexpected sizeof stock_directory");

#pragma pack(pop)
}
