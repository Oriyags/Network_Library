# Define compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Define sources and objects
SOURCES = \
    src/main.c \
    src/capture.c \
    src/protocols/arp.c \
    src/protocols/ethernet.c \
    src/protocols/ip.c \
    src/protocols/tcp.c \
    src/protocols/udp.c \
    src/utils/display_utils.c \
    src/utils/endian_utils.c \
    src/filters/packet_filter.c

OBJECTS = $(SOURCES:.c=.o)

# Define the target executable
TARGET = packet_analyzer

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile each source file into an object file, supporting nested directories
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)
