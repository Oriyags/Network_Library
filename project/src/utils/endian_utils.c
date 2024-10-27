#include "endian_utils.h"
#include <stdint.h>

// Convert a 16-bit network byte order value to host byte order.
uint16_t to_host_order_16(uint16_t net_value) {
    // Swap the bytes by shifting right by 8 bits and left by 8 bits, combining the two parts.
    return (net_value >> 8) | (net_value << 8);
}

// Convert a 32-bit network byte order value to host byte order.
uint32_t to_host_order_32(uint32_t net_value) {
    // Swap the bytes by combining parts:
    // 1. Shift right by 24 bits to move the highest byte to the lowest byte position.
    // 2. Shift left by 8 bits to move the second-highest byte to the second-lowest byte position.
    // 3. Shift right by 8 bits to move the second-lowest byte to the second-highest byte position.
    // 4. Shift left by 24 bits to move the lowest byte to the highest byte position.
    return ((net_value >> 24) & 0xff) |       // Extract the highest byte and move it to the lowest position.
           ((net_value << 8) & 0xff0000) |    // Move the second-highest byte to the second-lowest position.
           ((net_value >> 8) & 0xff00) |      // Move the second-lowest byte to the second-highest position.
           ((net_value << 24) & 0xff000000);  // Move the lowest byte to the highest position.
}
