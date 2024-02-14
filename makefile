# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = main.c cola.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
TARGET = ejemplo_cola

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
