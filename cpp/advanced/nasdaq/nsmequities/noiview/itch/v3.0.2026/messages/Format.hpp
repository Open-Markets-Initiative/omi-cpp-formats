#pragma once

#include <ostream>
#include <string_view>

#include "SystemEvent.hpp"
#include "StockDirectoryMessage.hpp"
#include "StockTradingActionMessage.hpp"
#include "RegShoShortSalePriceTestRestrictedIndicatorMessage.hpp"
#include "NetOrderImbalanceIndicatorMessage.hpp"
#include "CrossTradeMessage.hpp"
#include "IpoQuotingPeriodUpdateMessage.hpp"
#include "DirectListingWithCapitalRaisePriceDiscoveryMessage.hpp"

namespace nasdaq::nsmequities::noiview::itch::v3_0_2026 {

namespace itch_noiview = ::nasdaq::nsmequities::noiview::itch::v3_0_2026;

inline std::ostream& operator<<(std::ostream& os, const packet_header& value) {
    os << "session=\"" << value.session.get_trimmed().value() << '"'
       << ",sequence_number=" << value.sequence_number.get().value()
       << ",message_count=" << value.message_count.get().value()
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const message_header& value) {
    os << "message_length=" << value.message_length.get().value()
       << ",message_type=\"" << itch_noiview::message_type::to_string(value.message_type.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const system_event& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",event_code=\"" << msg.fields.event_code.get().value() << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const stock_directory_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",market_category=\"" << itch_noiview::market_category::to_string(msg.fields.market_category.get().value()) << '"'
       << ",financial_status_indicator=\"" << itch_noiview::financial_status_indicator::to_string(msg.fields.financial_status_indicator.get().value()) << '"'
       << ",round_lot_size=" << msg.fields.round_lot_size.get().value()
       << ",round_lots_only=\"" << itch_noiview::round_lots_only::to_string(msg.fields.round_lots_only.get().value()) << '"'
       << ",issue_classification=\"" << itch_noiview::issue_classification::to_string(msg.fields.issue_classification.get().value()) << '"'
       << ",issue_sub_type=\"" << msg.fields.issue_sub_type.get_trimmed().value() << '"'
       << ",authenticity=\"" << itch_noiview::authenticity::to_string(msg.fields.authenticity.get().value()) << '"'
       << ",short_sale_threshold_indicator=\"" << itch_noiview::short_sale_threshold_indicator::to_string(msg.fields.short_sale_threshold_indicator.get().value()) << '"'
       << ",ipo_flag=\"" << itch_noiview::ipo_flag::to_string(msg.fields.ipo_flag.get().value()) << '"'
       << ",luld_reference_price_tier=\"" << itch_noiview::luld_reference_price_tier::to_string(msg.fields.luld_reference_price_tier.get().value()) << '"'
       << ",etp_flag=\"" << itch_noiview::etp_flag::to_string(msg.fields.etp_flag.get().value()) << '"'
       << ",etp_leverage_factor=" << msg.fields.etp_leverage_factor.get().value()
       << ",inverse_indicator=\"" << itch_noiview::inverse_indicator::to_string(msg.fields.inverse_indicator.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const stock_trading_action_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",current_trading_state=\"" << itch_noiview::current_trading_state::to_string(msg.fields.current_trading_state.get().value()) << '"'
       << ",reason=\"" << msg.fields.reason.get_trimmed().value() << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const reg_sho_short_sale_price_test_restricted_indicator_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",reg_sho_action=\"" << itch_noiview::reg_sho_action::to_string(msg.fields.reg_sho_action.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const net_order_imbalance_indicator_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",paired_shares=" << msg.fields.paired_shares.get().value()
       << ",imbalance_shares=" << msg.fields.imbalance_shares.get().value()
       << ",imbalance_direction=\"" << itch_noiview::imbalance_direction::to_string(msg.fields.imbalance_direction.get().value()) << '"'
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",far_price=" << msg.fields.far_price.get().value()
       << ",near_price=" << msg.fields.near_price.get().value()
       << ",current_reference_price=" << msg.fields.current_reference_price.get().value()
       << ",cross_type=\"" << itch_noiview::cross_type::to_string(msg.fields.cross_type.get().value()) << '"'
       << ",price_variation_indicator=\"" << itch_noiview::price_variation_indicator::to_string(msg.fields.price_variation_indicator.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const cross_trade_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",shares=" << msg.fields.shares.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",cross_price=" << msg.fields.cross_price.get().value()
       << ",match_number=" << msg.fields.match_number.get().value()
       << ",cross_type=\"" << itch_noiview::cross_type::to_string(msg.fields.cross_type.get().value()) << '"'
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const ipo_quoting_period_update_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",ipo_quotation_release_time=" << msg.fields.ipo_quotation_release_time.get().value()
       << ",ipo_quotation_release_qualifier=\"" << itch_noiview::ipo_quotation_release_qualifier::to_string(msg.fields.ipo_quotation_release_qualifier.get().value()) << '"'
       << ",ipo_price=" << msg.fields.ipo_price.get().value()
       ;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const direct_listing_with_capital_raise_price_discovery_message& msg) {
    os << "tracking_number=" << msg.fields.tracking_number.get().value()
       << ",timestamp=" << msg.fields.timestamp.get().value()
       << ",stock=\"" << msg.fields.stock.get_trimmed().value() << '"'
       << ",open_eligibility_status=\"" << msg.fields.open_eligibility_status.get().value() << '"'
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
