#include "udp.h"
#include <netinet/ip.h>   
#include <netinet/udp.h>  
#include <netinet/ether.h>
#include <stdio.h>
#include <arpa/inet.h>

// Function to parse the UDP header from a given buffer and print its details.
// Parameters:
//   buffer - pointer to the buffer containing the UDP packet data.
//   size   - size of the buffer, which can be used to ensure there’s enough data.
void parse_udp_header(const unsigned char *buffer, int size) {
    struct udp_header *udp = (struct udp_header *)buffer;  // Cast the buffer pointer to a UDP header structure.

    printf("UDP Header\n");                               // Print a header for the UDP section.
    printf("   |-Source Port      : %u\n", ntohs(udp->source_port));  // Print the source port, converting from network to host byte order.
    printf("   |-Destination Port : %u\n", ntohs(udp->dest_port));    // Print the destination port, converting from network to host byte order.
    printf("   |-Length           : %u\n", ntohs(udp->length));       // Print the UDP packet length, converting from network to host byte order.
    printf("   |-Checksum         : %u\n", ntohs(udp->checksum));     // Print the UDP checksum, converting from network to host byte order.
}
