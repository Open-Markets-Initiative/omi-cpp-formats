#pragma once

#include <cstddef>
#include <algorithm>
#include <array>
#include <optional>
#include <string_view>
#include "../cache/Required.hpp"

namespace nasdaq::nsmequities::noiview::itch::v3_0_2026 {

// cross_type
struct cross_type {

    enum class enum_type : char {
        open_cross = 'O',
        close_cross = 'C',
        intraday_opening_cross_for_ipo_and_halted_paused_securities = 'H',
        extended_trading_close = 'A'
    };

    static constexpr std::array<std::pair<std::string_view, enum_type>, 4> from_string_map = {{
        {"Close Cross", enum_type::close_cross},
        {"Extended Trading Close", enum_type::extended_trading_close},
        {"Intraday Opening Cross For Ipo And Halted Paused Securities", enum_type::intraday_opening_cross_for_ipo_and_halted_paused_securities},
        {"Open Cross", enum_type::open_cross}
    }};

    static constexpr std::string_view to_string(enum_type value) {
        switch (value) {
            case enum_type::open_cross: return "Open Cross";
            case enum_type::close_cross: return "Close Cross";
            case enum_type::intraday_opening_cross_for_ipo_and_halted_paused_securities: return "Intraday Opening Cross For Ipo And Halted Paused Securities";
            case enum_type::extended_trading_close: return "Extended Trading Close";
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

    static constexpr const char* name = "cross_type";
    static constexpr std::size_t size = 1;
    static constexpr bool is_optional = false;

    using result_type = required<cross_type::enum_type>;
    using storage_type = result_type;

    constexpr cross_type()
     : value{ enum_type::open_cross } {}

    constexpr cross_type(enum_type v)
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
            set(enum_type::extended_trading_close);
    }

  protected:
    enum_type value;
};
}
