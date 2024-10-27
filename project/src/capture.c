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

#define BUFFER_SIZE 65536    // Define a buffer size for storing captured packet data

// Function to start capturing packets
void start_capture() {
    // Create a raw socket to capture packets at the data link layer (Ethernet)
    int sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_raw < 0) {      // Check if socket creation was successful
        perror("Socket Error"); // Print error message if socket creation fails
        exit(1);              // Exit program if socket cannot be created
    }

    unsigned char buffer[BUFFER_SIZE]; // Buffer to store packet data
    struct sockaddr saddr;     // Structure to store address of captured packet
    int saddr_len = sizeof(saddr); // Initialize address length

    while (1) {                // Infinite loop to continuously capture packets
        // Receive packets from the socket and store them in the buffer
        int data_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t*)&saddr_len);
        if (data_size < 0) {   // Check if packet reception was successful
            perror("Recvfrom error"); // Print error message if packet reception fails
            break;             // Exit loop on reception error
        }
        // Print the size of the captured packet
        printf("Packet captured! Size: %d bytes\n", data_size);
        
        // Call function to parse the captured Ethernet frame
        parse_ethernet_frame(buffer);
    }

    close(sock_raw);           // Close the socket once capturing is complete
}
