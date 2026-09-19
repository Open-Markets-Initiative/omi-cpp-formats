#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/Nanoseconds.hpp"
#include "../types/Stock.hpp"
#include "../types/RegShoAction.hpp"

namespace nasdaq::nsmequities::totalview::itch::v4_1 {

namespace itch_totalview = ::nasdaq::nsmequities::totalview::itch::v4_1;

#pragma pack(push, 1)

// Reg Sho Short Sale Price Test Restricted Indicator Message
struct reg_sho_short_sale_price_test_restricted_indicator_message {

    struct fields_type {
        itch_totalview::nanoseconds nanoseconds;
        itch_totalview::stock stock;
        itch_totalview::reg_sho_action reg_sho_action;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::reg_sho_short_sale_price_test_restricted_indicator_message};

    fields_type fields;

    // parse method
    static reg_sho_short_sale_price_test_restricted_indicator_message* parse(std::byte* buffer) {
        return reinterpret_cast<reg_sho_short_sale_price_test_restricted_indicator_message*>(buffer);
    }

    // parse method const
    static const reg_sho_short_sale_price_test_restricted_indicator_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const reg_sho_short_sale_price_test_restricted_indicator_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(reg_sho_short_sale_price_test_restricted_indicator_message::fields_type, nanoseconds) == 0, "unexpected offset of reg_sho_short_sale_price_test_restricted_indicator_message::fields_type::nanoseconds");
static_assert(offsetof(reg_sho_short_sale_price_test_restricted_indicator_message::fields_type, stock) == 4, "unexpected offset of reg_sho_short_sale_price_test_restricted_indicator_message::fields_type::stock");
static_assert(offsetof(reg_sho_short_sale_price_test_restricted_indicator_message::fields_type, reg_sho_action) == 12, "unexpected offset of reg_sho_short_sale_price_test_restricted_indicator_message::fields_type::reg_sho_action");
static_assert(sizeof(reg_sho_short_sale_price_test_restricted_indicator_message::fields_type) == 13, "unexpected sizeof reg_sho_short_sale_price_test_restricted_indicator_message::fields_type");
static_assert(sizeof(reg_sho_short_sale_price_test_restricted_indicator_message) == sizeof(message_header) + 13, "unexpected sizeof reg_sho_short_sale_price_test_restricted_indicator_message");

#pragma pack(pop)
}
