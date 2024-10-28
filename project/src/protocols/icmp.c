#include "icmp.h"
#include <stdio.h>
#include <arpa/inet.h>

void parse_icmp_header(const unsigned char *buffer, int size) {
    struct icmp_header *icmp = (struct icmp_header *)buffer;

    printf("ICMP Header\n");
    printf("   |-Type      : %u\n", icmp->type);
    printf("   |-Code      : %u\n", icmp->code);
    printf("   |-Checksum  : %u\n", ntohs(icmp->checksum));

    // Specific fields based on ICMP Type
    if (icmp->type == 0 || icmp->type == 8) {  // Echo reply (0) and request (8)
        printf("   |-Identifier  : %u\n", ntohs(icmp->un.echo.id));
        printf("   |-Sequence    : %u\n", ntohs(icmp->un.echo.sequence));
    }
    // Additional ICMP-specific fields can be parsed
}
