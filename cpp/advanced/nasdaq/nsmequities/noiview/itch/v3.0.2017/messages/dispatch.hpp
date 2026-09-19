#pragma once

#include <cstdint>
#include <cstddef>

#include "Definitions.hpp"
#include "../structs/MessageHeader.hpp"
#include "../structs/PacketHeader.hpp"

namespace nasdaq::nsmequities::noiview::itch::v3_0_2017 {

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
        case message_type::enum_type::reg_sho_restriction_message:
            handler.on_message(*reg_sho_restriction_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::noii_message:
            handler.on_message(*noii_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::cross_trade_message:
            handler.on_message(*cross_trade_message::parse(buffer), packet_receive_time, transport);
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
