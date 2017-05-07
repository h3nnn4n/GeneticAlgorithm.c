CC=gcc
override CFLAGS+=-lm -Wall -Wextra -pedantic --std=gnu99 -O3

SOURCES=utils.c		\
		mutation.c

SOURCE_BIN=main.c

EXECUTABLE=main

OBJECTS=$(SOURCES:.c=.o)
OBJECTS_BIN=$(SOURCE_BIN:.c=.o)

all: $(SOURCES) $(SOURCE_BIN) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(OBJECTS_BIN)
	$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTS_BIN) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	$(RM) $(OBJECTS_BIN) $(OBJECTS) $(EXECUTABLE)
