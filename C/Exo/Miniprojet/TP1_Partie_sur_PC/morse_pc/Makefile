# Program Output
TARGET = bin/morse

# Includes
INC += 	includes/

# Sources
#SRC_DIR = src
SRC = $(wildcard src/*.c)

# Objects
#OBJ = $(SRC:.c=bin:.o)
OBJ_DIR = bin
OBJ = $(patsubst src/%.c,bin/%.o,$(SRC))

# Toolchain
CC = gcc
CFLAGS = -Wall -Wextra -I $(INC)

#######################
#     Compilation     #
#######################

# All (default)
all: $(TARGET) run

# Create objects
$(OBJ) : $(SRC)
	@echo "Create objects"
	$(CC) $(CFLAGS) -o $@ -c $< 

# Create executable
$(TARGET) : $(OBJ)
	@echo "Create executable"
	@mkdir -p bin
	$(CC) $(CFLAGS) -o bin/main.o -c main.c
	$(CC) $(CFLAGS) -o $@ bin/main.o $^

# Clean objects
clean:
	rm -rf $(OBJ)

# Run executable
run:
	./$(TARGET)
