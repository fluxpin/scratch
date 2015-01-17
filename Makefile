CC = gcc
CFLAGS = -O2 -march=native
CFLAGS += -Wall -Wextra -pedantic -std=c89
CFLAGS += -Wpadded -Wwrite-strings
OBJECTS = fizzbuzz.o

.PHONY: all
all: fizzbuzz

fizzbuzz: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f fizzbuzz $(OBJECTS)
