#pragma once

#include <cstddef>
#include <algorithm>
#include <array>
#include <optional>
#include <string_view>
#include "../cache/Required.hpp"

namespace nasdaq::nsmequities::level2::itch::v2_0 {

// message_type
struct message_type {

    enum class enum_type : char {
        system_event_message = 'S',
        stock_directory_message = 'R',
        stock_trading_action_message = 'H',
        reg_sho_short_sale_price_test_restricted_indicator_message = 'Y',
        market_participant_position_message = 'P',
        operational_halt_message = 'h',
        market_participant_bid_ask_update_message = 'U',
        retail_price_interest_indicator_message = 'N',
        market_wide_circuit_breaker_decline_level_message = 'V',
        market_wide_circuit_breaker_status_message = 'W',
        ipo_quoting_period_update_message = 'K'
    };

    static constexpr std::array<std::pair<std::string_view, enum_type>, 11> from_string_map = {{
        {"Ipo Quoting Period Update Message", enum_type::ipo_quoting_period_update_message},
        {"Market Participant Bid Ask Update Message", enum_type::market_participant_bid_ask_update_message},
        {"Market Participant Position Message", enum_type::market_participant_position_message},
        {"Market Wide Circuit Breaker Decline Level Message", enum_type::market_wide_circuit_breaker_decline_level_message},
        {"Market Wide Circuit Breaker Status Message", enum_type::market_wide_circuit_breaker_status_message},
        {"Operational Halt Message", enum_type::operational_halt_message},
        {"Reg Sho Short Sale Price Test Restricted Indicator Message", enum_type::reg_sho_short_sale_price_test_restricted_indicator_message},
        {"Retail Price Interest Indicator Message", enum_type::retail_price_interest_indicator_message},
        {"Stock Directory Message", enum_type::stock_directory_message},
        {"Stock Trading Action Message", enum_type::stock_trading_action_message},
        {"System Event Message", enum_type::system_event_message}
    }};

    static constexpr std::string_view to_string(enum_type value) {
        switch (value) {
            case enum_type::system_event_message: return "System Event Message";
            case enum_type::stock_directory_message: return "Stock Directory Message";
            case enum_type::stock_trading_action_message: return "Stock Trading Action Message";
            case enum_type::reg_sho_short_sale_price_test_restricted_indicator_message: return "Reg Sho Short Sale Price Test Restricted Indicator Message";
            case enum_type::market_participant_position_message: return "Market Participant Position Message";
            case enum_type::operational_halt_message: return "Operational Halt Message";
            case enum_type::market_participant_bid_ask_update_message: return "Market Participant Bid Ask Update Message";
            case enum_type::retail_price_interest_indicator_message: return "Retail Price Interest Indicator Message";
            case enum_type::market_wide_circuit_breaker_decline_level_message: return "Market Wide Circuit Breaker Decline Level Message";
            case enum_type::market_wide_circuit_breaker_status_message: return "Market Wide Circuit Breaker Status Message";
            case enum_type::ipo_quoting_period_update_message: return "Ipo Quoting Period Update Message";
            default: return "unknown";
        }
    }

    static constexpr std::optional<enum_type> from_string(std::string_view str) {
        auto it = std::lower_bound(
            from_string_map.begin(),
            from_string_map.end(),
            str,
            [](const auto& pair, std::string_view s) { return pair.first < s; }
        );
        if (it != from_string_map.end() && it->first == str) {
            return it->second;
        }
        return std::nullopt;
    }

    static constexpr const char* name = "message_type";
    static constexpr std::size_t size = 1;
    static constexpr bool is_optional = false;

    using result_type = required<message_type::enum_type>;
    using storage_type = result_type;

    constexpr message_type()
     : value{ enum_type::system_event_message } {}

    constexpr message_type(enum_type v)
     : value{ v } {}

    [[nodiscard]] constexpr result_type get() const {
        return result_type{value};
    }

    constexpr void set(enum_type v) {
        value = v;
    }

    constexpr void set(result_type value) {
        if (value.has_value())
            set(value.value());
        else
            set(enum_type::ipo_quoting_period_update_message);
    }

  protected:
    enum_type value;
};
}
