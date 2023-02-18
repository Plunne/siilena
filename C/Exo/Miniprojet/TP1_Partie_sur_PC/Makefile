CC = gcc
TARGET = prog
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

all: $(TARGET) clean run

%.o : %.c
	$(CC) -o $@ -c $<

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ)

run:
	./$(TARGET)