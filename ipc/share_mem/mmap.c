#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char **argv){
    void* pmap;
    struct stat mystat;
    int fd;
    fd=open("test.txt",O_RDWR);
    if(fstat(fd,&mystat)<0){
        perror("fstat");
        exit(EXIT_FAILURE);
    }
    pmap=mmap(0,mystat.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(pmap==MAP_FAILED){
        perror("mmap");
        close(fd);
        exit(EXIT_FAILURE);
    }   
    strncpy(pmap,"hello",5);
    close(fd);
    munmap(pmap,mystat.st_size);
    return 0;
}