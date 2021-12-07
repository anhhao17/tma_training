CC=gcc
CFLAGS=-g -Wall
TARGET=intro
LIBS= -lpthread
all: clean $(TARGET)
$(TARGET):
	$(CC) $(CFLAGS) -o $@ $@.c $(LIBS)
clean:
	rm -f $(TARGET)