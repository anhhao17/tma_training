#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>

#include "share_mem.h"


int main(int argc,char **argv){

    if(argc!=2){
        printf("using %s to write\n",argv[0]);
        return -1;
    }    
    void *block=get_attack(FILE_NAME,BLOCK_SIZE);
    if(block==NULL){
        printf("Couldn't get block\n");
        return -1;
    }
    printf("Writing\n");
    strncpy(block,argv[1],BLOCK_SIZE);
    get_detech(block);
    

    return 0;
}