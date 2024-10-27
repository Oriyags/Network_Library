#include "ip.h"
#include "tcp.h" 
#include "udp.h"
#include <netinet/ether.h>
#include <stdio.h>
#include <arpa/inet.h>

// Function to parse the IP header from the captured packet buffer
void parse_ip_header(const unsigned char *buffer, int size) {
    // Cast the buffer to an IP header structure, offsetting by the size of the Ethernet header
    struct ip_header *ip = (struct ip_header *)(buffer + sizeof(struct ethhdr));

    // Print the IP header details
    printf("IP Header\n");
    printf("   |-IP Version        : %u\n", ip->version);                                  // Print the IP version
    printf("   |-IP Header Length  : %u\n", ip->ihl * 4);                                  // Print the header length in bytes
    printf("   |-Type of Service   : %u\n", ip->tos);                                      // Print the Type of Service field
    printf("   |-Total Length      : %u\n", ntohs(ip->total_length));                      // Print the total length of the IP packet
    printf("   |-Identification    : %u\n", ntohs(ip->id));                                // Print the Identification field
    printf("   |-TTL               : %u\n", ip->ttl);                                      // Print the Time to Live value
    printf("   |-Protocol          : %u\n", ip->protocol);                                 // Print the protocol type (TCP/UDP/ICMP)
    printf("   |-Checksum          : %u\n", ntohs(ip->checksum));                          // Print the IP header checksum
    printf("   |-Source IP         : %s\n", inet_ntoa(*(struct in_addr *)&ip->source_ip)); // Print the source IP address
    printf("   |-Destination IP    : %s\n", inet_ntoa(*(struct in_addr *)&ip->dest_ip));   // Print the destination IP address

    // Check if the protocol is TCP (protocol number 6)
    if (ip->protocol == 6) { // TCP
        // Call the function to parse the TCP header, adjusting the buffer to point to the TCP header
        parse_tcp_header(buffer + ip->ihl * 4 + sizeof(struct ethhdr), size - ip->ihl * 4 - sizeof(struct ethhdr));
    } 
    // Check if the protocol is UDP (protocol number 17)
    else if (ip->protocol == 17) { // UDP
        // Call the function to parse the UDP header, adjusting the buffer to point to the UDP header
        parse_udp_header(buffer + ip->ihl * 4 + sizeof(struct ethhdr), size - ip->ihl * 4 - sizeof(struct ethhdr));
    }
}
