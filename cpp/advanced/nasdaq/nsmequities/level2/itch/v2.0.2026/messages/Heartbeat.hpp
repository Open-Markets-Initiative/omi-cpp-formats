// Nasdaq.NsmEquities.Level2.Itch.v2.0.2026: messages/Heartbeat.hpp
#pragma once

#include <cstdint>

namespace nasdaq::nsmequities::level2::itch::v2_0_2026 {

// Heartbeat
struct heartbeat {

    static constexpr auto name = "Heartbeat";

    // selected when message_count == 0
    static constexpr auto field = "message_count";
    static constexpr std::uint16_t value = 0;

    // action properties
    static constexpr auto session = "Heartbeat";
    static constexpr auto origin = "Exchange";
};

}
