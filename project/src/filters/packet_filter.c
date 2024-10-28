#include "packet_filter.h"
#include "ethernet.h"
#include <netinet/ether.h>
#include <arpa/inet.h>
#include <stdio.h>

int filter_by_protocol(const unsigned char *buffer, int protocol) {
    struct ethhdr *eth = (struct ethhdr *)buffer;

    if (ntohs(eth->h_proto) == protocol) {
        return 1;  // Protocol matches
    }
    return 0;  // Protocol does not match
}
