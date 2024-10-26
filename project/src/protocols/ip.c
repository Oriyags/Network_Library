#include "ip.h"
#include <netinet/ether.h>
#include <stdio.h>
#include <arpa/inet.h>

void parse_ip_header(const unsigned char *buffer, int size) {
    struct ip_header *ip = (struct ip_header *)(buffer + sizeof(struct ethhdr)); // Skip Ethernet header

    printf("IP Header\n");
    printf("   |-IP Version        : %u\n", ip->version);
    printf("   |-IP Header Length  : %u\n", ip->ihl * 4);
    printf("   |-Type of Service   : %u\n", ip->tos);
    printf("   |-Total Length      : %u\n", ntohs(ip->total_length));
    printf("   |-Identification     : %u\n", ntohs(ip->id));
    printf("   |-TTL               : %u\n", ip->ttl);
    printf("   |-Protocol          : %u\n", ip->protocol);
    printf("   |-Checksum          : %u\n", ntohs(ip->checksum));
    printf("   |-Source IP        : %s\n", inet_ntoa(*(struct in_addr *)&ip->source_ip));
    printf("   |-Destination IP   : %s\n", inet_ntoa(*(struct in_addr *)&ip->dest_ip));
}
