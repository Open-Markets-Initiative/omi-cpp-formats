#pragma once

#include <cstddef>
#include <algorithm>
#include <array>
#include <optional>
#include <string_view>
#include "../cache/Required.hpp"

namespace nasdaq::nsmequities::nlsplus::itch::v4_0 {

// message_type
struct message_type {

    enum class enum_type : char {
        system_event_message = 'S',
        trade_report_message = 'e',
        trade_cancel_error_message = 'o',
        trade_correction_message = 'b',
        stock_trading_action_message = 'H',
        reg_sho_short_sale_price_test_restricted_indicator_message = 'Y',
        stock_directory_message = 'R',
        adjusted_closing_price_message = 'g',
        end_of_day_trade_summary_message = 'p',
        ipo_information_message = 'i',
        mwcb_decline_level_message = 'V',
        mwcb_status_message = 'W',
        ipo_quoting_period_update_message = 'k',
        operational_halt_message = 'h'
    };

    static constexpr std::array<std::pair<std::string_view, enum_type>, 14> from_string_map = {{
        {"Adjusted Closing Price Message", enum_type::adjusted_closing_price_message},
        {"End Of Day Trade Summary Message", enum_type::end_of_day_trade_summary_message},
        {"Ipo Information Message", enum_type::ipo_information_message},
        {"Ipo Quoting Period Update Message", enum_type::ipo_quoting_period_update_message},
        {"Mwcb Decline Level Message", enum_type::mwcb_decline_level_message},
        {"Mwcb Status Message", enum_type::mwcb_status_message},
        {"Operational Halt Message", enum_type::operational_halt_message},
        {"Reg Sho Short Sale Price Test Restricted Indicator Message", enum_type::reg_sho_short_sale_price_test_restricted_indicator_message},
        {"Stock Directory Message", enum_type::stock_directory_message},
        {"Stock Trading Action Message", enum_type::stock_trading_action_message},
        {"System Event Message", enum_type::system_event_message},
        {"Trade Cancel Error Message", enum_type::trade_cancel_error_message},
        {"Trade Correction Message", enum_type::trade_correction_message},
        {"Trade Report Message", enum_type::trade_report_message}
    }};

    static constexpr std::string_view to_string(enum_type value) {
        switch (value) {
            case enum_type::system_event_message: return "System Event Message";
            case enum_type::trade_report_message: return "Trade Report Message";
            case enum_type::trade_cancel_error_message: return "Trade Cancel Error Message";
            case enum_type::trade_correction_message: return "Trade Correction Message";
            case enum_type::stock_trading_action_message: return "Stock Trading Action Message";
            case enum_type::reg_sho_short_sale_price_test_restricted_indicator_message: return "Reg Sho Short Sale Price Test Restricted Indicator Message";
            case enum_type::stock_directory_message: return "Stock Directory Message";
            case enum_type::adjusted_closing_price_message: return "Adjusted Closing Price Message";
            case enum_type::end_of_day_trade_summary_message: return "End Of Day Trade Summary Message";
            case enum_type::ipo_information_message: return "Ipo Information Message";
            case enum_type::mwcb_decline_level_message: return "Mwcb Decline Level Message";
            case enum_type::mwcb_status_message: return "Mwcb Status Message";
            case enum_type::ipo_quoting_period_update_message: return "Ipo Quoting Period Update Message";
            case enum_type::operational_halt_message: return "Operational Halt Message";
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
            set(enum_type::operational_halt_message);
    }

  protected:
    enum_type value;
};
}
