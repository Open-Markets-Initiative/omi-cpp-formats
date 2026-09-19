#pragma once

#include <ostream>
#include <string_view>

#include "SystemEventMessage.hpp"
#include "StockDirectoryMessage.hpp"
#include "StockTradingActionMessage.hpp"
#include "RegShoShortSalePriceTestRestrictedIndicatorMessage.hpp"
#include "MarketParticipantPositionMessage.hpp"
#include "OperationalHaltMessage.hpp"
#include "MarketParticipantBidAskUpdateMessage.hpp"
#include "RetailPriceInterestIndicatorMessage.hpp"
#include "MarketWideCircuitBreakerDeclineLevelMessage.hpp"
#include "MarketWideCircuitBreakerStatusMessage.hpp"
#include "IpoQuotingPeriodUpdateMessage.hpp"

namespace nasdaq::nsmequities::level2::itch::v2_0 {

namespace itch_level2 = ::nasdaq::nsmequities::level2::itch::v2_0;

inline std::ostream& operator<<(std::ostream& os, const packet_header& value) {
    os << "session=\"" << value.session.get_trimmed().value() << '"'
       << ",sequence_number=" << value.sequence_number.get().value()
       << ",message_count=" << value.message_count.get().value()
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const message_header& value) {
    os << "message_length=" << value.message_length.get().value()
       << ",message_type=\"" << itch_level2::message_type::to_string(value.message_type.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const system_event_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",event_code=\"" << itch_level2::event_code::to_string(msg.fields.event_code.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const stock_directory_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",market_category=\"" << itch_level2::market_category::to_string(msg.fields.market_category.get().value()) << '"'
       << ",financial_status_indicator=\"" << itch_level2::financial_status_indicator::to_string(msg.fields.financial_status_indicator.get().value()) << '"'
       << ",round_lot_size=" << msg.fields.round_lot_size.get().value()
       << ",round_lots_only=\"" << itch_level2::round_lots_only::to_string(msg.fields.round_lots_only.get().value()) << '"'
       << ",issue_classification=\"" << itch_level2::issue_classification::to_string(msg.fields.issue_classification.get().value()) << '"'
       << ",issue_subtype=\"" << msg.fields.issue_subtype.get_trimmed().value() << '"'
       << ",authenticity=\"" << itch_level2::authenticity::to_string(msg.fields.authenticity.get().value()) << '"'
       << ",short_sale_threshold_indicator=\"" << itch_level2::short_sale_threshold_indicator::to_string(msg.fields.short_sale_threshold_indicator.get().value()) << '"'
       << ",ipo_flag=\"" << itch_level2::ipo_flag::to_string(msg.fields.ipo_flag.get().value()) << '"'
       << ",luld_reference_price_tier=\"" << itch_level2::luld_reference_price_tier::to_string(msg.fields.luld_reference_price_tier.get().value()) << '"'
       << ",etp_flag=\"" << itch_level2::etp_flag::to_string(msg.fields.etp_flag.get().value()) << '"'
       << ",etp_leverage_factor=" << msg.fields.etp_leverage_factor.get().value()
       << ",inverse_indicator=\"" << itch_level2::inverse_indicator::to_string(msg.fields.inverse_indicator.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const stock_trading_action_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",current_trading_state=\"" << itch_level2::current_trading_state::to_string(msg.fields.current_trading_state.get().value()) << '"'
       << ",reason=\"" << msg.fields.reason.get_trimmed().value() << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const reg_sho_short_sale_price_test_restricted_indicator_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",reg_sho_action=\"" << itch_level2::reg_sho_action::to_string(msg.fields.reg_sho_action.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const market_participant_position_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",mpid=\"" << msg.fields.mpid.get_trimmed().value() << '"'
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",primary_market_maker=\"" << itch_level2::primary_market_maker::to_string(msg.fields.primary_market_maker.get().value()) << '"'
       << ",market_maker_mode=\"" << itch_level2::market_maker_mode::to_string(msg.fields.market_maker_mode.get().value()) << '"'
       << ",market_participant_state=\"" << itch_level2::market_participant_state::to_string(msg.fields.market_participant_state.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const operational_halt_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",market_code=\"" << itch_level2::market_code::to_string(msg.fields.market_code.get().value()) << '"'
       << ",operational_halt_action=\"" << itch_level2::operational_halt_action::to_string(msg.fields.operational_halt_action.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const market_participant_bid_ask_update_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",market_side=\"" << itch_level2::market_side::to_string(msg.fields.market_side.get().value()) << '"'
       << ",participant_shares=" << msg.fields.participant_shares.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",price=" << msg.fields.price.get().value()
       << ",mpid=\"" << msg.fields.mpid.get_trimmed().value() << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const retail_price_interest_indicator_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",interest_flag=\"" << itch_level2::interest_flag::to_string(msg.fields.interest_flag.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const market_wide_circuit_breaker_decline_level_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",level_1=" << msg.fields.level_1.get().value()
       << ",level_2=" << msg.fields.level_2.get().value()
       << ",level_3=" << msg.fields.level_3.get().value()
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const market_wide_circuit_breaker_status_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",breached_level=\"" << itch_level2::breached_level::to_string(msg.fields.breached_level.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const ipo_quoting_period_update_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",ipo_quotation_release_time=" << msg.fields.ipo_quotation_release_time.get().value()
       << ",ipo_quotation_release_qualifier=\"" << itch_level2::ipo_quotation_release_qualifier::to_string(msg.fields.ipo_quotation_release_qualifier.get().value()) << '"'
       << ",ipo_price=" << msg.fields.ipo_price.get().value()
       ;
    return os;
}

}
