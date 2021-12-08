CC=gcc
CFLAGS=-g -Wall

TARGET=read write 
lib=libshare_mem.so
#LIBS= -lpthread
all: $(lib) $(TARGET)
//%.o: libshare_mem.h
$(TARGET): %:%.c 
	$(CC) $(CFLAGS) -o $@ $^ -L. -lshare_mem
$(lib): libshare_mem.c libshare_mem.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $< -lc
clean:
	rm -f $(TARGET) *.o