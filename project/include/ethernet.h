#ifndef ETHERNET_H
#define ETHERNET_H

#include <net/ethernet.h>

void parse_ethernet_frame(const unsigned char *buffer);

#endif
