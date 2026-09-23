#pragma once

#include <cstddef>
#include "../types/UdpSession.hpp"
#include "../types/UdpSequenceNumber.hpp"
#include "../types/MessageCount.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0_2026 {

namespace itch_totalview = ::nasdaq::nsmequities::totalview::itch::v5_0_2026;

#pragma pack(push, 1)

struct udp_packet_header {

    itch_totalview::udp_session udp_session;
    itch_totalview::udp_sequence_number udp_sequence_number;
    itch_totalview::message_count message_count;

    // parse method
    static udp_packet_header* parse(std::byte* buffer) {
        return reinterpret_cast<udp_packet_header*>(buffer);
    }

    // parse method const
    static const udp_packet_header* parse(const std::byte* buffer) {
        return reinterpret_cast<const udp_packet_header*>(buffer);
    }
};

// layout verification
static_assert(offsetof(udp_packet_header, udp_session) == 0, "unexpected offset of udp_packet_header::udp_session");
static_assert(offsetof(udp_packet_header, udp_sequence_number) == 10, "unexpected offset of udp_packet_header::udp_sequence_number");
static_assert(offsetof(udp_packet_header, message_count) == 18, "unexpected offset of udp_packet_header::message_count");
static_assert(sizeof(udp_packet_header) == 20, "unexpected sizeof udp_packet_header");

#pragma pack(pop)
}
