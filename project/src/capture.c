#include "capture.h"
#include "ethernet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <linux/if_packet.h>
#include <unistd.h>

#define BUFFER_SIZE 65536

void start_capture() {
    int sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_raw < 0) {
        perror("Socket Error");
        exit(1);
    }

    unsigned char buffer[BUFFER_SIZE];
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);

    while (1) {
        int data_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t*)&saddr_len);
        if (data_size < 0) {
            perror("Recvfrom error");
            break;
        }
        printf("Packet captured! Size: %d bytes\n", data_size);
        parse_ethernet_frame(buffer);
    }

    close(sock_raw);
}
