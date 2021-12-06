CC=gcc
CFLAGS=-g -Wall
TARGET=pipe
all: clean $(TARGET)
$(TARGET):
	$(CC) $(CFLAGS) -o $@ $@.c 
clean:
	rm -f $(TARGET)