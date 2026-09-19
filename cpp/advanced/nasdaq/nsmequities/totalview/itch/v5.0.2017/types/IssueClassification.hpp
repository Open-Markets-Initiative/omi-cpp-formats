#pragma once

#include <cstddef>
#include <algorithm>
#include <array>
#include <optional>
#include <string_view>
#include "../cache/Required.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0_2017 {

// issue_classification
struct issue_classification {

    enum class enum_type : char {
        american_depositary_share = 'A',
        bond = 'B',
        common = 'C',
        depository = 'F',
        sec_144_a = 'I',
        limited = 'L',
        notes = 'N',
        ordinary_share = 'O',
        preferred = 'P',
        other = 'Q',
        right = 'R',
        shares = 'S',
        convertible = 'T',
        unit = 'U',
        units_benif_int = 'V',
        warrant = 'W'
    };

    static constexpr std::array<std::pair<std::string_view, enum_type>, 16> from_string_map = {{
        {"American Depositary Share", enum_type::american_depositary_share},
        {"Bond", enum_type::bond},
        {"Common", enum_type::common},
        {"Convertible", enum_type::convertible},
        {"Depository", enum_type::depository},
        {"Limited", enum_type::limited},
        {"Notes", enum_type::notes},
        {"Ordinary Share", enum_type::ordinary_share},
        {"Other", enum_type::other},
        {"Preferred", enum_type::preferred},
        {"Right", enum_type::right},
        {"Sec 144 A", enum_type::sec_144_a},
        {"Shares", enum_type::shares},
        {"Unit", enum_type::unit},
        {"Units Benif Int", enum_type::units_benif_int},
        {"Warrant", enum_type::warrant}
    }};

    static constexpr std::string_view to_string(enum_type value) {
        switch (value) {
            case enum_type::american_depositary_share: return "American Depositary Share";
            case enum_type::bond: return "Bond";
            case enum_type::common: return "Common";
            case enum_type::depository: return "Depository";
            case enum_type::sec_144_a: return "Sec 144 A";
            case enum_type::limited: return "Limited";
            case enum_type::notes: return "Notes";
            case enum_type::ordinary_share: return "Ordinary Share";
            case enum_type::preferred: return "Preferred";
            case enum_type::other: return "Other";
            case enum_type::right: return "Right";
            case enum_type::shares: return "Shares";
            case enum_type::convertible: return "Convertible";
            case enum_type::unit: return "Unit";
            case enum_type::units_benif_int: return "Units Benif Int";
            case enum_type::warrant: return "Warrant";
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

    static constexpr const char* name = "issue_classification";
    static constexpr std::size_t size = 1;
    static constexpr bool is_optional = false;

    using result_type = required<issue_classification::enum_type>;
    using storage_type = result_type;

    constexpr issue_classification()
     : value{ enum_type::american_depositary_share } {}

    constexpr issue_classification(enum_type v)
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
            set(enum_type::warrant);
    }

  protected:
    enum_type value;
};
}
