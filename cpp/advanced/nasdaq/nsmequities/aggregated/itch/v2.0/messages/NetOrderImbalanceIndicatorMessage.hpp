#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/PairedShares.hpp"
#include "../types/ImbalanceShares.hpp"
#include "../types/ImbalanceDirection.hpp"
#include "../types/Stock.hpp"
#include "../types/FarPrice.hpp"
#include "../types/NearPrice.hpp"
#include "../types/CurrentReferencePrice.hpp"
#include "../types/CrossType.hpp"
#include "../types/PriceVariationIndicator.hpp"

namespace nasdaq::nsmequities::aggregated::itch::v2_0 {

namespace itch_aggregated = ::nasdaq::nsmequities::aggregated::itch::v2_0;

#pragma pack(push, 1)

// Net Order Imbalance Indicator Message
struct net_order_imbalance_indicator_message {

    struct fields_type {
        itch_aggregated::tracking_number tracking_number;
        itch_aggregated::timestamp timestamp;
        itch_aggregated::paired_shares paired_shares;
        itch_aggregated::imbalance_shares imbalance_shares;
        itch_aggregated::imbalance_direction imbalance_direction;
        itch_aggregated::stock stock;
        itch_aggregated::far_price far_price;
        itch_aggregated::near_price near_price;
        itch_aggregated::current_reference_price current_reference_price;
        itch_aggregated::cross_type cross_type;
        itch_aggregated::price_variation_indicator price_variation_indicator;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::net_order_imbalance_indicator_message};

    fields_type fields;

    // parse method
    static net_order_imbalance_indicator_message* parse(std::byte* buffer) {
        return reinterpret_cast<net_order_imbalance_indicator_message*>(buffer);
    }

    // parse method const
    static const net_order_imbalance_indicator_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const net_order_imbalance_indicator_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, tracking_number) == 0, "unexpected offset of net_order_imbalance_indicator_message::fields_type::tracking_number");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, timestamp) == 2, "unexpected offset of net_order_imbalance_indicator_message::fields_type::timestamp");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, paired_shares) == 8, "unexpected offset of net_order_imbalance_indicator_message::fields_type::paired_shares");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, imbalance_shares) == 16, "unexpected offset of net_order_imbalance_indicator_message::fields_type::imbalance_shares");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, imbalance_direction) == 24, "unexpected offset of net_order_imbalance_indicator_message::fields_type::imbalance_direction");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, stock) == 25, "unexpected offset of net_order_imbalance_indicator_message::fields_type::stock");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, far_price) == 33, "unexpected offset of net_order_imbalance_indicator_message::fields_type::far_price");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, near_price) == 37, "unexpected offset of net_order_imbalance_indicator_message::fields_type::near_price");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, current_reference_price) == 41, "unexpected offset of net_order_imbalance_indicator_message::fields_type::current_reference_price");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, cross_type) == 45, "unexpected offset of net_order_imbalance_indicator_message::fields_type::cross_type");
static_assert(offsetof(net_order_imbalance_indicator_message::fields_type, price_variation_indicator) == 46, "unexpected offset of net_order_imbalance_indicator_message::fields_type::price_variation_indicator");
static_assert(sizeof(net_order_imbalance_indicator_message::fields_type) == 47, "unexpected sizeof net_order_imbalance_indicator_message::fields_type");
static_assert(sizeof(net_order_imbalance_indicator_message) == sizeof(message_header) + 47, "unexpected sizeof net_order_imbalance_indicator_message");

#pragma pack(pop)
}
