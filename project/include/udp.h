#ifndef UDP_H
#define UDP_H

#include <stdint.h>

// Define the structure for the UDP header
struct udp_header {
    uint16_t source_port;  // Source port
    uint16_t dest_port;    // Destination port
    uint16_t length;       // Length of the UDP header and data
    uint16_t checksum;      // Checksum for error-checking
};

// Function prototype for parsing the UDP header
void parse_udp_header(const unsigned char *buffer, int size);

#endif // UDP_H
