#pragma once

#include <cstdint>
#include <cstddef>

#include "Definitions.hpp"
#include "../structs/MessageHeader.hpp"
#include "../structs/PacketHeader.hpp"

namespace nasdaq::nsmequities::totalview::itch::v4_1 {

// Template-based message dispatch
// Handler must implement on_message() for each message type

template<typename Handler>
void dispatch(Handler& handler, const std::byte* buffer, std::size_t length, std::uint64_t packet_receive_time, const packet_header& transport) {
    (void)length;
    const auto* header = message_header::parse(buffer);

    switch (header->message_type.get().value()) {
        case message_type::enum_type::timestamp_message:
            handler.on_message(*timestamp_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::system_event_message:
            handler.on_message(*system_event_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::stock_directory_message:
            handler.on_message(*stock_directory_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::reg_sho_short_sale_price_test_restricted_indicator_message:
            handler.on_message(*reg_sho_short_sale_price_test_restricted_indicator_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::market_participant_position_message:
            handler.on_message(*market_participant_position_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::add_order_message:
            handler.on_message(*add_order_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::add_order_with_mpid_message:
            handler.on_message(*add_order_with_mpid_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::order_executed_message:
            handler.on_message(*order_executed_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::order_executed_with_price_message:
            handler.on_message(*order_executed_with_price_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::order_cancel_message:
            handler.on_message(*order_cancel_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::order_delete_message:
            handler.on_message(*order_delete_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::order_replace_message:
            handler.on_message(*order_replace_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::trade_message:
            handler.on_message(*trade_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::cross_trade_message:
            handler.on_message(*cross_trade_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::broken_trade_message:
            handler.on_message(*broken_trade_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::net_order_imbalance_indicator_message:
            handler.on_message(*net_order_imbalance_indicator_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::retail_price_improvement_indicator_message:
            handler.on_message(*retail_price_improvement_indicator_message::parse(buffer), packet_receive_time, transport);
            break;
        default:
            // Unknown message type - handler should implement on_unknown if needed
            break;
    }
}

}
