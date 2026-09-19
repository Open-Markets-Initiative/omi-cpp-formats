#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/AuctionCollarReferencePrice.hpp"
#include "../types/UpperAuctionCollarPrice.hpp"
#include "../types/LowerAuctionCollarPrice.hpp"
#include "../types/AuctionCollarExtension.hpp"

namespace nasdaq::nsmequities::aggregated::itch::v2_0 {

namespace itch_aggregated = ::nasdaq::nsmequities::aggregated::itch::v2_0;

#pragma pack(push, 1)

// Luld Auction Collar Message
struct luld_auction_collar_message {

    struct fields_type {
        itch_aggregated::tracking_number tracking_number;
        itch_aggregated::timestamp timestamp;
        itch_aggregated::stock stock;
        itch_aggregated::auction_collar_reference_price auction_collar_reference_price;
        itch_aggregated::upper_auction_collar_price upper_auction_collar_price;
        itch_aggregated::lower_auction_collar_price lower_auction_collar_price;
        itch_aggregated::auction_collar_extension auction_collar_extension;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::luld_auction_collar_message};

    fields_type fields;

    // parse method
    static luld_auction_collar_message* parse(std::byte* buffer) {
        return reinterpret_cast<luld_auction_collar_message*>(buffer);
    }

    // parse method const
    static const luld_auction_collar_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const luld_auction_collar_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(luld_auction_collar_message::fields_type, tracking_number) == 0, "unexpected offset of luld_auction_collar_message::fields_type::tracking_number");
static_assert(offsetof(luld_auction_collar_message::fields_type, timestamp) == 2, "unexpected offset of luld_auction_collar_message::fields_type::timestamp");
static_assert(offsetof(luld_auction_collar_message::fields_type, stock) == 8, "unexpected offset of luld_auction_collar_message::fields_type::stock");
static_assert(offsetof(luld_auction_collar_message::fields_type, auction_collar_reference_price) == 16, "unexpected offset of luld_auction_collar_message::fields_type::auction_collar_reference_price");
static_assert(offsetof(luld_auction_collar_message::fields_type, upper_auction_collar_price) == 20, "unexpected offset of luld_auction_collar_message::fields_type::upper_auction_collar_price");
static_assert(offsetof(luld_auction_collar_message::fields_type, lower_auction_collar_price) == 24, "unexpected offset of luld_auction_collar_message::fields_type::lower_auction_collar_price");
static_assert(offsetof(luld_auction_collar_message::fields_type, auction_collar_extension) == 28, "unexpected offset of luld_auction_collar_message::fields_type::auction_collar_extension");
static_assert(sizeof(luld_auction_collar_message::fields_type) == 32, "unexpected sizeof luld_auction_collar_message::fields_type");
static_assert(sizeof(luld_auction_collar_message) == sizeof(message_header) + 32, "unexpected sizeof luld_auction_collar_message");

#pragma pack(pop)
}
