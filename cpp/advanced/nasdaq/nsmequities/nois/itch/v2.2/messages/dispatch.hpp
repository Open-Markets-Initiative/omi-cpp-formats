#pragma once

#include <cstdint>
#include <cstddef>

#include "Definitions.hpp"
#include "../structs/MessageHeader.hpp"
#include "../structs/PacketHeader.hpp"
#include "../types/MessageLength.hpp"

namespace nasdaq::nsmequities::nois::itch::v2_2 {

// Template-based message dispatch
// Handler must implement on_message() for each message type

template<typename Handler>
void dispatch(Handler& handler, const std::byte* buffer, std::size_t length, std::uint64_t packet_receive_time, const packet_header& transport) {
    (void)length;

    switch (system_event_message::parse(buffer)->header.message_type.get().value()) {
        case message_type::enum_type::system_event_message:
            handler.on_message(*system_event_message::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::stock_directory:
            handler.on_message(*stock_directory::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::stock_trading_action:
            handler.on_message(*stock_trading_action::parse(buffer), packet_receive_time, transport);
            break;
        case message_type::enum_type::nois_message:
            handler.on_message(*nois_message::parse(buffer), packet_receive_time, transport);
            break;
        default:
            // a code none of the messages answer to: the handler is told when it wants to be
            if constexpr (requires { handler.on_unknown(buffer, length, packet_receive_time, transport); }) {
                handler.on_unknown(buffer, length, packet_receive_time, transport);
            }
            break;
    }
}

}
