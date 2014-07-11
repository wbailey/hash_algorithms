CC = gcc
CFLAGS = -Wall
TARGET = hashes
INCLUDE = include
SRC = src

.PHONY: clean $(SRC)
.SILENT: clean

build: $(TARGET)
	@echo Hash algorithms has been compiled

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $(TARGET) $(wildcard $(SRC)/*.o) hash_algos.c

$(SRC):
	$(MAKE) -C $@ all

clean:
	$(MAKE) -is -C $(SRC) clean
	- rm $(TARGET)
	@echo All temporary files have been removed
