#pragma once

#include <cstddef>
#include <algorithm>
#include <array>
#include <optional>
#include <string_view>
#include "../cache/Required.hpp"

namespace nasdaq::nsmequities::totalview::itch::v4_1 {

// interest_flag
struct interest_flag {

    enum class enum_type : char {
        rpi_buy = 'B',
        rpi_sell = 'S',
        rpi_both = 'A',
        no_rpi = 'N'
    };

    static constexpr std::array<std::pair<std::string_view, enum_type>, 4> from_string_map = {{
        {"No Rpi", enum_type::no_rpi},
        {"Rpi Both", enum_type::rpi_both},
        {"Rpi Buy", enum_type::rpi_buy},
        {"Rpi Sell", enum_type::rpi_sell}
    }};

    static constexpr std::string_view to_string(enum_type value) {
        switch (value) {
            case enum_type::rpi_buy: return "Rpi Buy";
            case enum_type::rpi_sell: return "Rpi Sell";
            case enum_type::rpi_both: return "Rpi Both";
            case enum_type::no_rpi: return "No Rpi";
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

    static constexpr const char* name = "interest_flag";
    static constexpr std::size_t size = 1;
    static constexpr bool is_optional = false;

    using result_type = required<interest_flag::enum_type>;
    using storage_type = result_type;

    constexpr interest_flag()
     : value{ enum_type::rpi_buy } {}

    constexpr interest_flag(enum_type v)
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
            set(enum_type::no_rpi);
    }

  protected:
    enum_type value;
};
}
