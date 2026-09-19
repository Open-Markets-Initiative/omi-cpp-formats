#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/IssueSymbol.hpp"
#include "../types/SecurityClass.hpp"
#include "../types/AdjustedClosingPrice.hpp"

namespace nasdaq::nsmequities::nlsplus::itch::v4_0 {

namespace itch_nlsplus = ::nasdaq::nsmequities::nlsplus::itch::v4_0;

#pragma pack(push, 1)

// Adjusted Closing Price Message
struct adjusted_closing_price_message {

    struct fields_type {
        itch_nlsplus::tracking_number tracking_number;
        itch_nlsplus::timestamp timestamp;
        itch_nlsplus::issue_symbol issue_symbol;
        itch_nlsplus::security_class security_class;
        itch_nlsplus::adjusted_closing_price adjusted_closing_price;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::adjusted_closing_price_message};

    fields_type fields;

    // parse method
    static adjusted_closing_price_message* parse(std::byte* buffer) {
        return reinterpret_cast<adjusted_closing_price_message*>(buffer);
    }

    // parse method const
    static const adjusted_closing_price_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const adjusted_closing_price_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(adjusted_closing_price_message::fields_type, tracking_number) == 0, "unexpected offset of adjusted_closing_price_message::fields_type::tracking_number");
static_assert(offsetof(adjusted_closing_price_message::fields_type, timestamp) == 2, "unexpected offset of adjusted_closing_price_message::fields_type::timestamp");
static_assert(offsetof(adjusted_closing_price_message::fields_type, issue_symbol) == 8, "unexpected offset of adjusted_closing_price_message::fields_type::issue_symbol");
static_assert(offsetof(adjusted_closing_price_message::fields_type, security_class) == 16, "unexpected offset of adjusted_closing_price_message::fields_type::security_class");
static_assert(offsetof(adjusted_closing_price_message::fields_type, adjusted_closing_price) == 17, "unexpected offset of adjusted_closing_price_message::fields_type::adjusted_closing_price");
static_assert(sizeof(adjusted_closing_price_message::fields_type) == 25, "unexpected sizeof adjusted_closing_price_message::fields_type");
static_assert(sizeof(adjusted_closing_price_message) == sizeof(message_header) + 25, "unexpected sizeof adjusted_closing_price_message");

#pragma pack(pop)
}
