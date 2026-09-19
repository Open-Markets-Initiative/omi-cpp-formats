#pragma once

#include <cstddef>
#include <algorithm>
#include <array>
#include <optional>
#include <string_view>
#include "../cache/Required.hpp"

namespace nasdaq::nsmequities::noiview::itch::v3_0_2026 {

// message_type
struct message_type {

    enum class enum_type : char {
        system_event = 'S',
        stock_directory_message = 'R',
        stock_trading_action_message = 'H',
        reg_sho_short_sale_price_test_restricted_indicator_message = 'Y',
        net_order_imbalance_indicator_message = 'I',
        cross_trade_message = 'Q',
        ipo_quoting_period_update_message = 'K',
        direct_listing_with_capital_raise_price_discovery_message = 'O'
    };

    static constexpr std::array<std::pair<std::string_view, enum_type>, 8> from_string_map = {{
        {"Cross Trade Message", enum_type::cross_trade_message},
        {"Direct Listing With Capital Raise Price Discovery Message", enum_type::direct_listing_with_capital_raise_price_discovery_message},
        {"Ipo Quoting Period Update Message", enum_type::ipo_quoting_period_update_message},
        {"Net Order Imbalance Indicator Message", enum_type::net_order_imbalance_indicator_message},
        {"Reg Sho Short Sale Price Test Restricted Indicator Message", enum_type::reg_sho_short_sale_price_test_restricted_indicator_message},
        {"Stock Directory Message", enum_type::stock_directory_message},
        {"Stock Trading Action Message", enum_type::stock_trading_action_message},
        {"System Event", enum_type::system_event}
    }};

    static constexpr std::string_view to_string(enum_type value) {
        switch (value) {
            case enum_type::system_event: return "System Event";
            case enum_type::stock_directory_message: return "Stock Directory Message";
            case enum_type::stock_trading_action_message: return "Stock Trading Action Message";
            case enum_type::reg_sho_short_sale_price_test_restricted_indicator_message: return "Reg Sho Short Sale Price Test Restricted Indicator Message";
            case enum_type::net_order_imbalance_indicator_message: return "Net Order Imbalance Indicator Message";
            case enum_type::cross_trade_message: return "Cross Trade Message";
            case enum_type::ipo_quoting_period_update_message: return "Ipo Quoting Period Update Message";
            case enum_type::direct_listing_with_capital_raise_price_discovery_message: return "Direct Listing With Capital Raise Price Discovery Message";
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
     : value{ enum_type::system_event } {}

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
            set(enum_type::direct_listing_with_capital_raise_price_discovery_message);
    }

  protected:
    enum_type value;
};
}
