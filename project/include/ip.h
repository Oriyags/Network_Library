#ifndef IP_H
#define IP_H

#include <stdint.h>
#include <arpa/inet.h>

struct ip_header {
    unsigned char  ihl:4;      // Internet Header Length
    unsigned char  version:4;  // Version
    unsigned char  tos;         // Type of Service
    uint16_t      total_length; // Total Length
    uint16_t      id;          // Identification
    uint16_t      fragment_offset:13; // Fragment Offset
    unsigned char  ttl;         // Time to Live
    unsigned char  protocol;    // Protocol
    uint16_t      checksum;     // Checksum
    uint32_t      source_ip;    // Source IP
    uint32_t      dest_ip;      // Destination IP
};

void parse_ip_header(const unsigned char *buffer, int size);

#endif
