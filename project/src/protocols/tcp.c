#include "tcp.h"
#include <stdio.h>
#include <arpa/inet.h>

void parse_tcp_header(const unsigned char *buffer, int size) {  // Function to parse TCP header from the given buffer.
    struct tcp_header *tcp = (struct tcp_header *)buffer;      // Cast the buffer to a tcp_header struct pointer.

    printf("TCP Header\n");                                      // Print the header title.
    printf("   |-Source Port      : %u\n", ntohs(tcp->source_port)); // Print the source port number in host byte order.
    printf("   |-Destination Port : %u\n", ntohs(tcp->dest_port));   // Print the destination port number in host byte order.
    printf("   |-Sequence Number  : %u\n", ntohl(tcp->sequence));    // Print the sequence number in host byte order.
    printf("   |-Acknowledge Number: %u\n", ntohl(tcp->acknowledgment)); // Print the acknowledgment number in host byte order.
    printf("   |-Data Offset      : %u\n", (tcp->data_offset >> 4) * 4); // Calculate and print the data offset (in bytes).
    printf("   |-Flags            : %u\n", tcp->flags);                // Print the TCP flags.
    printf("   |-Window           : %u\n", ntohs(tcp->window));        // Print the window size in host byte order.
    printf("   |-Checksum         : %u\n", ntohs(tcp->checksum));      // Print the checksum in host byte order.
    printf("   |-Urgent Pointer   : %u\n", tcp->urgent_pointer);       // Print the urgent pointer value.
}
