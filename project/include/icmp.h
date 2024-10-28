#ifndef ICMP_H
#define ICMP_H

#include <stdint.h>

// Define the ICMP header structure
struct icmp_header {
    uint8_t type;         // Type of ICMP message
    uint8_t code;         // ICMP code for the message
    uint16_t checksum;    // Checksum of the ICMP header and data

    // Union to handle different types of ICMP messages
    union {
        struct {
            uint16_t id;      // Identifier (used in echo request/reply)
            uint16_t sequence; // Sequence number (used in echo request/reply)
        } echo; // for echo requests and replies (ping)
        uint32_t gateway;     // Gateway address (used in redirect messages)
        struct {
            uint16_t unused;
            uint16_t mtu;      // Path MTU (used in fragmentation needed messages)
        } frag; // for fragmentation needed messages
    } un;
};

#endif
