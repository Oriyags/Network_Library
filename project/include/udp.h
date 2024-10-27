#ifndef UDP_H
#define UDP_H

#include <stdint.h>

struct udp_header {
    uint16_t source_port;
    uint16_t dest_port;
    uint16_t length;
    uint16_t checksum;
};

void parse_udp_header(const unsigned char *buffer, int size);

#endif
