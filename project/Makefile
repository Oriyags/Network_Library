# Define compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude -Itest -I/usr/include/CUnit
LDFLAGS = -L/usr/lib -lcunit

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

# Define the main target executable
TARGET = packet_analyzer

# Define test sources and objects
TEST_SOURCES = \
    test/test_arp.c \
    test/test_capture.c \
    test/test_endian_utils.c \
    test/test_ethernet.c \
    test/test_icmp.c \
    test/test_ip.c \
    test/test_tcp.c \
    test/test_udp.c

TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
TEST_TARGETS = $(TEST_OBJECTS:.o=)

# Build the main executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Build each test executable
$(TEST_TARGETS): $(TEST_OBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(@:.o=.c) $(LDFLAGS)

# Compile each source file into an object file, supporting nested directories
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files, executables, and test binaries
clean:
	rm -f $(OBJECTS) $(TARGET) $(TEST_OBJECTS) $(TEST_TARGETS)
