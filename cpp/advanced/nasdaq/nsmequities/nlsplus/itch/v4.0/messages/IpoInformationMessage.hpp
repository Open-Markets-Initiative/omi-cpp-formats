#pragma once

#include <cstddef>
#include "../structs/MessageHeader.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/IssueSymbol.hpp"
#include "../types/SecurityClass.hpp"
#include "../types/ReferenceForNetChange.hpp"
#include "../types/ReferencePrice.hpp"

namespace nasdaq::nsmequities::nlsplus::itch::v4_0 {

namespace itch_nlsplus = ::nasdaq::nsmequities::nlsplus::itch::v4_0;

#pragma pack(push, 1)

// Ipo Information Message
struct ipo_information_message {

    struct fields_type {
        itch_nlsplus::tracking_number tracking_number;
        itch_nlsplus::timestamp timestamp;
        itch_nlsplus::issue_symbol issue_symbol;
        itch_nlsplus::security_class security_class;
        itch_nlsplus::reference_for_net_change reference_for_net_change;
        itch_nlsplus::reference_price reference_price;
    };

    message_header header = {std::uint16_t(sizeof(message_header) + sizeof(fields_type) - 2), message_type::enum_type::ipo_information_message};

    fields_type fields;

    // parse method
    static ipo_information_message* parse(std::byte* buffer) {
        return reinterpret_cast<ipo_information_message*>(buffer);
    }

    // parse method const
    static const ipo_information_message* parse(const std::byte* buffer) {
        return reinterpret_cast<const ipo_information_message*>(buffer);
    }

};

// layout verification
static_assert(offsetof(ipo_information_message::fields_type, tracking_number) == 0, "unexpected offset of ipo_information_message::fields_type::tracking_number");
static_assert(offsetof(ipo_information_message::fields_type, timestamp) == 2, "unexpected offset of ipo_information_message::fields_type::timestamp");
static_assert(offsetof(ipo_information_message::fields_type, issue_symbol) == 8, "unexpected offset of ipo_information_message::fields_type::issue_symbol");
static_assert(offsetof(ipo_information_message::fields_type, security_class) == 16, "unexpected offset of ipo_information_message::fields_type::security_class");
static_assert(offsetof(ipo_information_message::fields_type, reference_for_net_change) == 17, "unexpected offset of ipo_information_message::fields_type::reference_for_net_change");
static_assert(offsetof(ipo_information_message::fields_type, reference_price) == 18, "unexpected offset of ipo_information_message::fields_type::reference_price");
static_assert(sizeof(ipo_information_message::fields_type) == 26, "unexpected sizeof ipo_information_message::fields_type");
static_assert(sizeof(ipo_information_message) == sizeof(message_header) + 26, "unexpected sizeof ipo_information_message");

#pragma pack(pop)
}
