# Simple Makefile for explorer core (Buildroot cross-compile friendly)
CC ?= gcc
CFLAGS ?= -O2 -Wall
LDFLAGS ?=

SRC = explorer.c explorer_manager.c prompt_variations.c
OBJ = $(SRC:.c=.o)
TARGET = explorer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean