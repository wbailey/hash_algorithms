CC = gcc
CFLAGS = -Wall
TARGET = hashes
#SRCS = add_hash.c xor_hash.c rotating.c djb_hash.c hash_algos.c
SRCS = src/*.c
OBJS = $(SRCS:.c=.o)

.PHONY = clean

all: $(TARGET)
	@echo Hash algorithms has been compiled

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.c.o:
	$(CC) -c $<
clean:
	rm *.o $(TARGET)
