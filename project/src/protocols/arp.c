#include "arp.h"
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <linux/if_ether.h>

void parse_arp_header(const unsigned char *buffer) {
    struct ethhdr *eth = (struct ethhdr *)buffer;  // Get Ethernet header
    struct arp_header *arp = (struct arp_header *)(buffer + sizeof(struct ethhdr));

    printf("Ethernet Header\n");
    printf("   |-Destination MAC Address : %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
           eth->h_dest[0], eth->h_dest[1], eth->h_dest[2],
           eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);
    printf("   |-Source MAC Address      : %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
           eth->h_source[0], eth->h_source[1], eth->h_source[2],
           eth->h_source[3], eth->h_source[4], eth->h_source[5]);
    printf("   |-Protocol Type           : 0x%04X\n", ntohs(eth->h_proto));

    printf("ARP Header\n");
    printf("   |-Hardware Type           : %u\n", ntohs(arp->htype));
    printf("   |-Protocol Type           : %u\n", ntohs(arp->ptype));
    printf("   |-Hardware Address Length : %u\n", arp->hlen);
    printf("   |-Protocol Address Length : %u\n", arp->plen);
    printf("   |-Operation               : %u\n", ntohs(arp->opcode));
    
    printf("   |-Sender MAC Address      : %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
           arp->sender_mac[0], arp->sender_mac[1], arp->sender_mac[2],
           arp->sender_mac[3], arp->sender_mac[4], arp->sender_mac[5]);
    printf("   |-Sender IP Address       : %s\n", inet_ntoa(*(struct in_addr *)&arp->sender_ip));
    printf("   |-Target MAC Address      : %.2X:%.2X:%.2X:%.2X:%.2X:%.2X\n",
           arp->target_mac[0], arp->target_mac[1], arp->target_mac[2],
           arp->target_mac[3], arp->target_mac[4], arp->target_mac[5]);
    printf("   |-Target IP Address       : %s\n", inet_ntoa(*(struct in_addr *)&arp->target_ip));
}
