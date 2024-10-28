#ifndef ARP_H
#define ARP_H

#include <stdint.h>
#include <netinet/in.h> 

#define ARP_HARDWARE_TYPE 1
#define ARP_PROTOCOL_TYPE 0x0800  // IPv4

struct arp_header {
    uint16_t htype;      // Hardware Type
    uint16_t ptype;      // Protocol Type
    uint8_t hlen;        // Hardware Address Length
    uint8_t plen;        // Protocol Address Length
    uint16_t opcode;     // Operation
    uint8_t sender_mac[6]; // Sender MAC Address
    struct in_addr sender_ip; // Sender IP Address
    uint8_t target_mac[6]; // Target MAC Address
    struct in_addr target_ip; // Target IP Address
};

void parse_arp_header(const unsigned char *buffer);

#endif
