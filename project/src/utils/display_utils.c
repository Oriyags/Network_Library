#include "display_utils.h"
#include <stdio.h>
#include <ctype.h>

// Function to print a hex dump of a packet buffer for debugging and analysis.
void print_hex(const unsigned char *buffer, int size) {
    int i, j;
    for (i = 0; i < size; i += 16) {
        printf("%04X  ", i); // Print the offset at the start of each line.

        // Print each byte in hex format.
        for (j = 0; j < 16; j++) {
            if (i + j < size)
                printf("%02X ", buffer[i + j]);
            else
                printf("   "); // Print spaces for alignment if fewer than 16 bytes remain.
        }

        printf(" "); // Spacer between hex and ASCII display.

        // Print ASCII characters for each byte (or a dot for non-printable characters).
        for (j = 0; j < 16; j++) {
            if (i + j < size) {
                unsigned char ch = buffer[i + j];
                printf("%c", isprint(ch) ? ch : '.');
            }
        }

        printf("\n"); // New line after each 16 bytes.
    }
}

// Function to print a line separator for readability between packet headers or sections.
void print_separator() {
    printf("----------------------------------------------------------\n");
}
