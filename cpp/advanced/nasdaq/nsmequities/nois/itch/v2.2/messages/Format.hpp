#pragma once

#include <ostream>
#include <string_view>

#include "SystemEventMessage.hpp"
#include "StockDirectory.hpp"
#include "StockTradingAction.hpp"
#include "NoisMessage.hpp"

namespace nasdaq::nsmequities::nois::itch::v2_2 {

namespace itch_nois = ::nasdaq::nsmequities::nois::itch::v2_2;

inline std::ostream& operator<<(std::ostream& os, const packet_header& value) {
    os << "session=\"" << value.session.get_trimmed().value() << '"'
       << ",sequence_number=" << value.sequence_number.get().value()
       << ",message_count=" << value.message_count.get().value()
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const message_header& value) {
    os << "timestamp=" << value.timestamp.get().value()
       << ",message_type=\"" << itch_nois::message_type::to_string(value.message_type.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const system_event_message& msg) {
    os << "event_code=\"" << itch_nois::event_code::to_string(msg.fields.event_code.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const stock_directory& msg) {
    os << "symbol=\"" << msg.fields.symbol.get_trimmed().value() << '"'
       << ",market_category=\"" << itch_nois::market_category::to_string(msg.fields.market_category.get().value()) << '"'
       << ",rfu=\"" << msg.fields.rfu.get().value() << '"'
       << ",round_lot_size=\"" << msg.fields.round_lot_size.get_trimmed().value() << '"'
       << ",round_lots_only=\"" << itch_nois::round_lots_only::to_string(msg.fields.round_lots_only.get().value()) << '"'
       << ",issue_classification=\"" << itch_nois::issue_classification::to_string(msg.fields.issue_classification.get().value()) << '"'
       << ",issue_sub_type=\"" << msg.fields.issue_sub_type.get_trimmed().value() << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const stock_trading_action& msg) {
    os << "symbol=\"" << msg.fields.symbol.get_trimmed().value() << '"'
       << ",trading_state=\"" << itch_nois::trading_state::to_string(msg.fields.trading_state.get().value()) << '"'
       << ",reason=\"" << msg.fields.reason.get().value() << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const nois_message& msg) {
    os << "imbalance_shares=\"" << msg.fields.imbalance_shares.get_trimmed().value() << '"'
       << ",imbalance_direction=\"" << itch_nois::imbalance_direction::to_string(msg.fields.imbalance_direction.get().value()) << '"'
       << ",symbol=\"" << msg.fields.symbol.get_trimmed().value() << '"'
       << ",near_price=\"" << msg.fields.near_price.get_trimmed().value() << '"'
       << ",current_reference_price=\"" << msg.fields.current_reference_price.get_trimmed().value() << '"'
       << ",cross_type=\"" << itch_nois::cross_type::to_string(msg.fields.cross_type.get().value()) << '"'
       ;
    return os;
}

}
