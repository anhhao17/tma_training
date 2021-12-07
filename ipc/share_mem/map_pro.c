#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(int argc,char **argv){
    u_int8_t * pmap;

    pmap=mmap(0,sizeof(u_int8_t),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,0,0);
    if(pmap==MAP_FAILED){
        perror("mmap");
        
        exit(EXIT_FAILURE);
    }
    *pmap=2;
    printf("before = %d\n",*pmap);
    if(fork()==0){
        //child
        *pmap=10;
    }
    else
        wait(NULL);
    
    printf("After = %d\n",*pmap);

    munmap(pmap,sizeof(u_int8_t));
    return 0;
}