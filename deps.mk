CFLAGS += -Wall -Wextra -pedantic -std=c89
CFLAGS += -Wpadded -Wsign-conversion -Wwrite-strings

VPATH = ..

all: test

test: crc32.o
crc32.o: crc32.h
test.o: crc32.h
