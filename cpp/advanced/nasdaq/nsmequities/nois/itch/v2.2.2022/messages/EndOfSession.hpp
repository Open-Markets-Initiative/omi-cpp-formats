#pragma once

#include <cstdint>

namespace nasdaq::nsmequities::nois::itch::v2_2_2022 {

// End Of Session
struct end_of_session {

    static constexpr auto name = "End Of Session";

    // selected when message_length == 0
    static constexpr auto field = "message_length";
    static constexpr std::uint16_t value = 0;

    // action properties
    static constexpr auto session = "End";
    static constexpr auto origin = "Exchange";
};

}
