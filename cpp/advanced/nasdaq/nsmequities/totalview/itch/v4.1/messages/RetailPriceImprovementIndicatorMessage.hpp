#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/Nanoseconds.hpp"
#include "../types/Stock.hpp"
#include "../types/InterestFlag.hpp"

namespace nasdaq::nsmequities::totalview::itch::v4_1 {

namespace itch_totalview = ::nasdaq::nsmequities::totalview::itch::v4_1;

#pragma pack(push, 1)

// Retail Price Improvement Indicator Message
struct retail_price_improvement_indicator_message {

    struct fields_type {
        itch_totalview::nanoseconds nanoseconds;
        itch_totalview::stock stock;
        itch_totalview::interest_flag interest_flag;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::retail_price_improvement_indicator_message};

    fields_type fields;

    // parse method
    static retail_price_improvement_indicator_message* parse(std::byte* buffer) {
        return reinterpret_cast<retail_price_improvement_indicator_message*>(buffer);
    }

    // parse method const
    static const retail_price_improvement_indicator_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const retail_price_improvement_indicator_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(retail_price_improvement_indicator_message::fields_type, nanoseconds) == 0, "unexpected offset of retail_price_improvement_indicator_message::fields_type::nanoseconds");
static_assert(offsetof(retail_price_improvement_indicator_message::fields_type, stock) == 4, "unexpected offset of retail_price_improvement_indicator_message::fields_type::stock");
static_assert(offsetof(retail_price_improvement_indicator_message::fields_type, interest_flag) == 12, "unexpected offset of retail_price_improvement_indicator_message::fields_type::interest_flag");
static_assert(sizeof(retail_price_improvement_indicator_message::fields_type) == 13, "unexpected sizeof retail_price_improvement_indicator_message::fields_type");
static_assert(sizeof(retail_price_improvement_indicator_message) == sizeof(message_header) + 13, "unexpected sizeof retail_price_improvement_indicator_message");

#pragma pack(pop)
}
