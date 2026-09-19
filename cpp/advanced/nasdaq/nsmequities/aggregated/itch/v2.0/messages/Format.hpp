#pragma once

#include <ostream>
#include <string_view>

#include "SystemEventMessage.hpp"
#include "StockDirectoryMessage.hpp"
#include "StockTradingActionMessage.hpp"
#include "RegShoShortSalePriceTestRestrictedIndicatorMessage.hpp"
#include "MarketParticipantPositionMessage.hpp"
#include "MwcbDeclineLevelMessage.hpp"
#include "MwcbStatusMessage.hpp"
#include "IpoQuotingPeriodUpdateMessage.hpp"
#include "LuldAuctionCollarMessage.hpp"
#include "OperationalHaltMessage.hpp"
#include "PriceLevelUpdateMessage.hpp"
#include "NetOrderImbalanceIndicatorMessage.hpp"
#include "RetailPriceImprovementIndicatorMessage.hpp"
#include "DirectListingWithCapitalRaisePriceDiscoveryMessage.hpp"

namespace nasdaq::nsmequities::aggregated::itch::v2_0 {

namespace itch_aggregated = ::nasdaq::nsmequities::aggregated::itch::v2_0;

inline std::ostream& operator<<(std::ostream& os, const packet_header& value) {
    os << "session=\"" << value.session.get_trimmed().value() << '"'
       << ",sequence_number=" << value.sequence_number.get().value()
       << ",message_count=" << value.message_count.get().value()
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const message_header& value) {
    os << "message_length=" << value.message_length.get().value()
       << ",message_type=\"" << itch_aggregated::message_type::to_string(value.message_type.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const system_event_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",event_code=\"" << itch_aggregated::event_code::to_string(msg.fields.event_code.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const stock_directory_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",market_category=\"" << itch_aggregated::market_category::to_string(msg.fields.market_category.get().value()) << '"'
       << ",financial_status_indicator=\"" << itch_aggregated::financial_status_indicator::to_string(msg.fields.financial_status_indicator.get().value()) << '"'
       << ",round_lot_size=" << msg.fields.round_lot_size.get().value()
       << ",round_lots_only=\"" << itch_aggregated::round_lots_only::to_string(msg.fields.round_lots_only.get().value()) << '"'
       << ",issue_classification=\"" << itch_aggregated::issue_classification::to_string(msg.fields.issue_classification.get().value()) << '"'
       << ",issue_sub_type=\"" << msg.fields.issue_sub_type.get_trimmed().value() << '"'
       << ",authenticity=\"" << itch_aggregated::authenticity::to_string(msg.fields.authenticity.get().value()) << '"'
       << ",short_sale_threshold_indicator=\"" << itch_aggregated::short_sale_threshold_indicator::to_string(msg.fields.short_sale_threshold_indicator.get().value()) << '"'
       << ",ipo_flag=\"" << itch_aggregated::ipo_flag::to_string(msg.fields.ipo_flag.get().value()) << '"'
       << ",luld_reference_price_tier=\"" << itch_aggregated::luld_reference_price_tier::to_string(msg.fields.luld_reference_price_tier.get().value()) << '"'
       << ",etp_flag=\"" << itch_aggregated::etp_flag::to_string(msg.fields.etp_flag.get().value()) << '"'
       << ",etp_leverage_factor=" << msg.fields.etp_leverage_factor.get().value()
       << ",inverse_indicator=\"" << itch_aggregated::inverse_indicator::to_string(msg.fields.inverse_indicator.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const stock_trading_action_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",trading_state=\"" << itch_aggregated::trading_state::to_string(msg.fields.trading_state.get().value()) << '"'
       << ",reason=\"" << msg.fields.reason.get_trimmed().value() << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const reg_sho_short_sale_price_test_restricted_indicator_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",reg_sho_action=\"" << itch_aggregated::reg_sho_action::to_string(msg.fields.reg_sho_action.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const market_participant_position_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",mpid=\"" << msg.fields.mpid.get_trimmed().value() << '"'
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",primary_market_maker=\"" << itch_aggregated::primary_market_maker::to_string(msg.fields.primary_market_maker.get().value()) << '"'
       << ",market_maker_mode=\"" << itch_aggregated::market_maker_mode::to_string(msg.fields.market_maker_mode.get().value()) << '"'
       << ",market_participant_state=\"" << itch_aggregated::market_participant_state::to_string(msg.fields.market_participant_state.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const mwcb_decline_level_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",level_1=" << msg.fields.level_1.get().value()
       << ",level_2=" << msg.fields.level_2.get().value()
       << ",level_3=" << msg.fields.level_3.get().value()
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const mwcb_status_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",breached_level=\"" << itch_aggregated::breached_level::to_string(msg.fields.breached_level.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const ipo_quoting_period_update_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",ipo_quotation_release_time=" << msg.fields.ipo_quotation_release_time.get().value()
       << ",ipo_quotation_release_qualifier=\"" << itch_aggregated::ipo_quotation_release_qualifier::to_string(msg.fields.ipo_quotation_release_qualifier.get().value()) << '"'
       << ",ipo_price=" << msg.fields.ipo_price.get().value()
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const luld_auction_collar_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",auction_collar_reference_price=" << msg.fields.auction_collar_reference_price.get().value()
       << ",upper_auction_collar_price=" << msg.fields.upper_auction_collar_price.get().value()
       << ",lower_auction_collar_price=" << msg.fields.lower_auction_collar_price.get().value()
       << ",auction_collar_extension=" << msg.fields.auction_collar_extension.get().value()
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const operational_halt_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",market_code=\"" << itch_aggregated::market_code::to_string(msg.fields.market_code.get().value()) << '"'
       << ",operational_halt_action=\"" << itch_aggregated::operational_halt_action::to_string(msg.fields.operational_halt_action.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const price_level_update_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",market_side=\"" << itch_aggregated::market_side::to_string(msg.fields.market_side.get().value()) << '"'
       << ",participant_shares=" << msg.fields.participant_shares.get().value()
       << ",aggregate_shares=" << msg.fields.aggregate_shares.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",price=" << msg.fields.price.get().value()
       << ",mpid=\"" << msg.fields.mpid.get_trimmed().value() << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const net_order_imbalance_indicator_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",paired_shares=" << msg.fields.paired_shares.get().value()
       << ",imbalance_shares=" << msg.fields.imbalance_shares.get().value()
       << ",imbalance_direction=\"" << itch_aggregated::imbalance_direction::to_string(msg.fields.imbalance_direction.get().value()) << '"'
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",far_price=" << msg.fields.far_price.get().value()
       << ",near_price=" << msg.fields.near_price.get().value()
       << ",current_reference_price=" << msg.fields.current_reference_price.get().value()
       << ",cross_type=\"" << itch_aggregated::cross_type::to_string(msg.fields.cross_type.get().value()) << '"'
       << ",price_variation_indicator=\"" << itch_aggregated::price_variation_indicator::to_string(msg.fields.price_variation_indicator.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const retail_price_improvement_indicator_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",interest_flag=\"" << itch_aggregated::interest_flag::to_string(msg.fields.interest_flag.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const direct_listing_with_capital_raise_price_discovery_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",open_eligibility_status=\"" << itch_aggregated::open_eligibility_status::to_string(msg.fields.open_eligibility_status.get().value()) << '"'
       << ",minimum_allowable_price=" << msg.fields.minimum_allowable_price.get().value()
       << ",maximum_allowable_price=" << msg.fields.maximum_allowable_price.get().value()
       << ",near_execution_price=" << msg.fields.near_execution_price.get().value()
       << ",near_execution_time=" << msg.fields.near_execution_time.get().value()
       << ",lower_price_range_collar=" << msg.fields.lower_price_range_collar.get().value()
       << ",upper_price_range_collar=" << msg.fields.upper_price_range_collar.get().value()
       ;
    return os;
}

}
