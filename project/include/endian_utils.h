#ifndef ENDIAN_UTILS_H
#define ENDIAN_UTILS_H

#include <stdint.h>

uint16_t to_host_order_16(uint16_t net_value);
uint32_t to_host_order_32(uint32_t net_value);

#endif
