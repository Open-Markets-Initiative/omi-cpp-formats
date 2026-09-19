#pragma once

#include <cstdint>
#include <cstddef>

#include "Definitions.hpp"
#include "../structs/MessageHeader.hpp"
#include "../structs/PacketHeader.hpp"

namespace nasdaq::nsmequities::level2::itch::v2_0 {

// Template-based message dispatch
// Handler must implement on_message() for each message type

template<typename Handler>
void dispatch(Handler& handler, const std::byte* buffer, std::size_t length, std::uint64_t packet_receive_time, const packet_header& transport) {
    (void)length;
    const auto* header = message_header::parse(buffer);

    switch (header->message_type.get().value()) {
        case message_type::enum_type::system_event_message:
            handler.on_message(*system_event_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::stock_directory_message:
            handler.on_message(*stock_directory_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::stock_trading_action_message:
            handler.on_message(*stock_trading_action_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::reg_sho_short_sale_price_test_restricted_indicator_message:
            handler.on_message(*reg_sho_short_sale_price_test_restricted_indicator_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::market_participant_position_message:
            handler.on_message(*market_participant_position_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::operational_halt_message:
            handler.on_message(*operational_halt_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::market_participant_bid_ask_update_message:
            handler.on_message(*market_participant_bid_ask_update_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::retail_price_interest_indicator_message:
            handler.on_message(*retail_price_interest_indicator_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::market_wide_circuit_breaker_decline_level_message:
            handler.on_message(*market_wide_circuit_breaker_decline_level_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::market_wide_circuit_breaker_status_message:
            handler.on_message(*market_wide_circuit_breaker_status_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::ipo_quoting_period_update_message:
            handler.on_message(*ipo_quoting_period_update_message::parse(buffer), packet_receive_time, transport);
            break;
        default:
            // Unknown message type - handler should implement on_unknown if needed
            break;
    }
}

}
