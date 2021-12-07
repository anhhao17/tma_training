CC=gcc
CFLAGS=-g -Wall
OBJ=share_mem.o
TARGET=read write
#LIBS= -lpthread
all: clean $(TARGET)
$(TARGET): %:%.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f $(TARGET) *.o