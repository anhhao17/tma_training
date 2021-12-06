CC=gcc
CFLAGS=-g -Wall -Werror
OBJ=ser_thread sock_cli sock_ser server_tcp client_tcp
LIBS=-lpthread 
all: clean $(OBJ)
$(OBJ): 
	$(CC) $(CFLAGS) -o $@  $@.c $(LIBS)
clean:
	rm -f $(OBJ)