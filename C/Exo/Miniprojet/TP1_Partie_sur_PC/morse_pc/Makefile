# Program Output
NAME = morse
BINDIR = bin
TARGET = $(BINDIR)/$(NAME)

# Includes
INC += 	includes/

# Sources
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.c)

# Objects
OBJDIR = $(BINDIR)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

# Toolchain
CC = gcc
CFLAGS = -Wall -Wextra -I $(INC)

#######################
#     Compilation     #
#######################

# All (default)
all: clean $(TARGET) run

# Compile
$(OBJ) : $(SRC)
	@echo "\n***** Compile program *****"
	@mkdir -p bin
	$(CC) $(CFLAGS) -o $@ -c $< 
	$(CC) $(CFLAGS) -o $(BINDIR)/main.o -c main.c

# Link
$(TARGET) : $(OBJ)
	@echo "\n***** Create executable *****"
	$(CC) $(CFLAGS) -o $@ $(BINDIR)/main.o $^

# Clean objects
clean:
	@echo "\n***** Cleaning objects *****"
	rm -rf bin/*.o

# Run executable
run:
	@echo "\n***** Run executable *****"
	./$(TARGET)

uninstall:
	@echo "\n***** Uninstall *****"
	rm -rf bin