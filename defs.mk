MAKEFLAGS += -Rr

CC = gcc
CFLAGS ?= -O2 -march=native
PREFIX ?= /usr/local

%: %.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

%.so: %.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.d: %.c
	$(CC) $(CLFAGS) -MM -MP $< -MF $@
	sed -i 's/$(@:.d=.o)/& $@/' $@
