
TARGET=thread wait_thread

CROSS_TOOL=
CC=${CROSS_TOOL}gcc
CFLAGS= -Wall -g -Werror 
LIBS=-lpthread
all: clean $(TARGET)
$(TARGET):
	$(CC) $(CFLAGS) $@.c -o $@ $(LIBS)
clean:
	rm -f $(TARGET) 
