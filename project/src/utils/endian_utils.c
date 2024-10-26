#include "endian_utils.h"
#include <stdint.h>

uint16_t to_host_order_16(uint16_t net_value) {
    return (net_value >> 8) | (net_value << 8);
}

uint32_t to_host_order_32(uint32_t net_value) {
    return ((net_value >> 24) & 0xff) | ((net_value << 8) & 0xff0000) |
           ((net_value >> 8) & 0xff00) | ((net_value << 24) & 0xff000000);
}
