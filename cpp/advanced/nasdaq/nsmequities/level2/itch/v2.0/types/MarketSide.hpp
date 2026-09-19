#pragma once

#include <cstddef>
#include <algorithm>
#include <array>
#include <optional>
#include <string_view>
#include "../cache/Required.hpp"

namespace nasdaq::nsmequities::level2::itch::v2_0 {

// market_side
struct market_side {

    enum class enum_type : char {
        bid_update = 'B',
        offer_ask_update = 'S'
    };

    static constexpr std::array<std::pair<std::string_view, enum_type>, 2> from_string_map = {{
        {"Bid Update", enum_type::bid_update},
        {"Offer Ask Update", enum_type::offer_ask_update}
    }};

    static constexpr std::string_view to_string(enum_type value) {
        switch (value) {
            case enum_type::bid_update: return "Bid Update";
            case enum_type::offer_ask_update: return "Offer Ask Update";
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

    static constexpr const char* name = "market_side";
    static constexpr std::size_t size = 1;
    static constexpr bool is_optional = false;

    using result_type = required<market_side::enum_type>;
    using storage_type = result_type;

    constexpr market_side()
     : value{ enum_type::bid_update } {}

    constexpr market_side(enum_type v)
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
            set(enum_type::offer_ask_update);
    }

  protected:
    enum_type value;
};
}
