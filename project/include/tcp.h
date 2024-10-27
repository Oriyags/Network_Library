#ifndef TCP_H
#define TCP_H

#include <stdint.h>

struct tcp_header {
    uint16_t source_port;
    uint16_t dest_port;
    uint32_t sequence;
    uint32_t acknowledgment;
    uint8_t data_offset;
    uint8_t flags;
    uint16_t window;
    uint16_t checksum;
    uint16_t urgent_pointer;
};

void parse_tcp_header(const unsigned char *buffer, int size);

#endif
