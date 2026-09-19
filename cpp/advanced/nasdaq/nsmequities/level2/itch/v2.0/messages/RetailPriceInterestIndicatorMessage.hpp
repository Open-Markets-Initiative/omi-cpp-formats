#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/InterestFlag.hpp"

namespace nasdaq::nsmequities::level2::itch::v2_0 {

namespace itch_level2 = ::nasdaq::nsmequities::level2::itch::v2_0;

#pragma pack(push, 1)

// Retail Price Interest Indicator Message
struct retail_price_interest_indicator_message {

    struct fields_type {
        itch_level2::tracking_number tracking_number;
        itch_level2::timestamp timestamp;
        itch_level2::stock stock;
        itch_level2::interest_flag interest_flag;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::retail_price_interest_indicator_message};

    fields_type fields;

    // parse method
    static retail_price_interest_indicator_message* parse(std::byte* buffer) {
        return reinterpret_cast<retail_price_interest_indicator_message*>(buffer);
    }

    // parse method const
    static const retail_price_interest_indicator_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const retail_price_interest_indicator_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(retail_price_interest_indicator_message::fields_type, tracking_number) == 0, "unexpected offset of retail_price_interest_indicator_message::fields_type::tracking_number");
static_assert(offsetof(retail_price_interest_indicator_message::fields_type, timestamp) == 2, "unexpected offset of retail_price_interest_indicator_message::fields_type::timestamp");
static_assert(offsetof(retail_price_interest_indicator_message::fields_type, stock) == 8, "unexpected offset of retail_price_interest_indicator_message::fields_type::stock");
static_assert(offsetof(retail_price_interest_indicator_message::fields_type, interest_flag) == 16, "unexpected offset of retail_price_interest_indicator_message::fields_type::interest_flag");
static_assert(sizeof(retail_price_interest_indicator_message::fields_type) == 17, "unexpected sizeof retail_price_interest_indicator_message::fields_type");
static_assert(sizeof(retail_price_interest_indicator_message) == sizeof(message_header) + 17, "unexpected sizeof retail_price_interest_indicator_message");

#pragma pack(pop)
}
