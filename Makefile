include defs.mk

CFLAGS += -fpic
CFLAGS += -Wall -Wextra -std=c89 # -pedantic
CFLAGS += -Wpadded -Wwrite-strings
LDFLAGS += -ldl -shared
OBJECTS = getpwuid.o

.PHONY: all
all: getpwuid.so

getpwuid.so: $(OBJECTS)

-include $(OBJECTS:.o=.d)

.PHONY: clean
clean:
	rm -f getpwuid.so $(OBJECTS) $(OBJECTS:.o=.d)
