#include "ethernet.h"
#include "ip.h"
#include <netinet/in.h>
#include <stdio.h>

void parse_ethernet_frame(const unsigned char *buffer) { // Define a function to parse an Ethernet frame.
    struct ethhdr *eth = (struct ethhdr *)buffer;        // Cast the input buffer to an Ethernet header structure.

    printf("Ethernet Header\n"); // Print the header title for Ethernet information.
    
    // Print the source MAC address in hexadecimal format.
    printf("   |-Source MAC Address      : %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
           eth->h_source[0], eth->h_source[1], eth->h_source[2],
           eth->h_source[3], eth->h_source[4], eth->h_source[5]);
    
    // Print the destination MAC address in hexadecimal format.
    printf("   |-Destination MAC Address : %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
           eth->h_dest[0], eth->h_dest[1], eth->h_dest[2],
           eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);
    
    // Print the protocol field value (h_proto) of the Ethernet header.
    printf("   |-Protocol                : %u\n", (unsigned short)eth->h_proto);

    // Check if the protocol is IP (0x0800)
    if (ntohs(eth->h_proto) == ETH_P_IP) { // Compare the protocol in host byte order with ETH_P_IP.
        parse_ip_header(buffer, ntohs(eth->h_proto)); // Call the IP header parsing function if the protocol is IP.
    }
}
