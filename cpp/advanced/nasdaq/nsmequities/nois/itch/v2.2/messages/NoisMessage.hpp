#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/ImbalanceShares.hpp"
#include "../types/ImbalanceDirection.hpp"
#include "../types/Symbol.hpp"
#include "../types/NearPrice.hpp"
#include "../types/CurrentReferencePrice.hpp"
#include "../types/CrossType.hpp"
#include "../types/MessageLength.hpp"

namespace nasdaq::nsmequities::nois::itch::v2_2 {

namespace itch_nois = ::nasdaq::nsmequities::nois::itch::v2_2;

#pragma pack(push, 1)

// Nois Message
struct nois_message {

    struct fields_type {
        itch_nois::imbalance_shares imbalance_shares;
        itch_nois::imbalance_direction imbalance_direction;
        itch_nois::symbol symbol;
        itch_nois::near_price near_price;
        itch_nois::current_reference_price current_reference_price;
        itch_nois::cross_type cross_type;
    };

    // Transport framing: message size precedes the SBE header on the wire
    itch_nois::message_length message_length;
    itch_nois::message_header header = {{}, message_type::enum_type::nois_message};

    fields_type fields;

    // parse method
    static nois_message* parse(std::byte* buffer) {
        return reinterpret_cast<nois_message*>(buffer);
    }

    // parse method const
    static const nois_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const nois_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(nois_message::fields_type, imbalance_shares) == 0, "unexpected offset of nois_message::fields_type::imbalance_shares");
static_assert(offsetof(nois_message::fields_type, imbalance_direction) == 9, "unexpected offset of nois_message::fields_type::imbalance_direction");
static_assert(offsetof(nois_message::fields_type, symbol) == 10, "unexpected offset of nois_message::fields_type::symbol");
static_assert(offsetof(nois_message::fields_type, near_price) == 18, "unexpected offset of nois_message::fields_type::near_price");
static_assert(offsetof(nois_message::fields_type, current_reference_price) == 28, "unexpected offset of nois_message::fields_type::current_reference_price");
static_assert(offsetof(nois_message::fields_type, cross_type) == 38, "unexpected offset of nois_message::fields_type::cross_type");
static_assert(sizeof(nois_message::fields_type) == 39, "unexpected sizeof nois_message::fields_type");
static_assert(sizeof(nois_message) == sizeof(itch_nois::message_length) + sizeof(itch_nois::message_header) + 39, "unexpected sizeof nois_message");

#pragma pack(pop)
}
