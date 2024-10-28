
# Developer Notes

## Overview
This project captures, parses, and analyzes network packets, providing details on Ethernet, IP, TCP, UDP, ICMP, and ARP protocols.

## Components

- **capture.c**: Responsible for initiating packet capture using raw sockets and passing the captured data to parsing functions.
- **ethernet.c**: Parses Ethernet frames and determines if the packet should be passed to IP, ARP, or other protocol-specific parsers.
- **ip.c**: Parses IP headers, identifying the protocol type (TCP, UDP, ICMP) and handing over to the respective protocol parser.
- **tcp.c and udp.c**: Handle parsing of TCP and UDP headers, extracting and displaying essential fields.
- **icmp.c**: Extracts ICMP header information, useful for analyzing ping requests and other ICMP messages.
- **arp.c**: Extracts ARP packet information, including sender and target MAC/IP addresses.
- **packet_filter.c**: Contains filtering functions to allow selective packet capture and analysis based on protocol, IP, MAC, etc.

.
├── src
│   ├── capture.c           # Main packet capture logic
│   ├── main.c              # Main entry point, handles initialization and calls capture
│   ├── protocols
│   │   ├── ethernet.c      # Ethernet frame parsing
│   │   ├── ip.c            # IP header parsing
│   │   ├── tcp.c           # TCP header parsing
│   │   ├── udp.c           # UDP header parsing
│   │   ├── icmp.c          # ICMP header parsing
│   │   └── arp.c           # ARP header parsing (optional, for ARP packet capture)
│   ├── utils
│   │   ├── endian_utils.c  # Functions for endian conversion (e.g., custom ntohs, ntohl)
│   │   └── display_utils.c # Helper functions to format and display parsed data
│   └── filters
│       └── packet_filter.c # Packet filtering functions based on user-defined criteria
│
├── include
│   ├── capture.h           # Capture function declarations and configurations
│   ├── ethernet.h          # Ethernet frame structure definitions
│   ├── ip.h                # IP header structure and parsing functions
│   ├── tcp.h               # TCP header structure and parsing functions
│   ├── udp.h               # UDP header structure and parsing functions
│   ├── icmp.h              # ICMP header structure and parsing functions
│   ├── arp.h               # ARP header structure and parsing functions
│   ├── endian_utils.h      # Endian conversion utility function declarations
│   ├── display_utils.h     # Declarations for display functions
│   └── packet_filter.h     # Filter function declarations
│
├── tests
│   ├── test_capture.c      # Unit tests for packet capturing functions
│   ├── test_ethernet.c     # Unit tests for Ethernet frame parsing
│   ├── test_ip.c           # Unit tests for IP parsing
│   ├── test_tcp.c          # Unit tests for TCP parsing
│   ├── test_udp.c          # Unit tests for UDP parsing
│   ├── test_icmp.c         # Unit tests for ICMP parsing
│   ├── test_arp.c          # Unit tests for ARP parsing
│   └── test_endian_utils.c # Unit tests for endian conversion functions
│
├── Makefile                # Build instructions for the entire project
├── README.md               # Project documentation and setup instructions
└── docs
    ├── protocol_docs       # Protocol details, header descriptions, etc.
    └── developer_notes.md  # Development guidelines and future improvement notes