CC = gcc
CFLAGS = -Wall -Iinclude

# Source files
SRC = src/main.c src/capture.c src/protocols/ethernet.c src/protocols/ip.c src/utils/endian_utils.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable
TARGET = packet_analyzer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
