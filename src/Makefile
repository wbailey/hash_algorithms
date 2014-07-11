CC = gcc
CFLAGS = -Wall
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

.PHONY: clean
.SILENT: clean

all: $(OBJS)
	@echo Source algorithms have been compiled

.c.o:
	$(CC) -c $< -o $@

clean:
	rm *.o
