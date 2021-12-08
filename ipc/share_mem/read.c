#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>

#include "libshare_mem.h"


int main(int argc,char **argv){

       
    void *block=get_attack(FILE_NAME,BLOCK_SIZE);
    if(block==NULL){
        printf("Couldn't get block\n");
        return -1;
    }
    printf("Reading %s \n",(char *)block);
    
    get_detech(block);
    if(destroy(FILE_NAME)){
        printf("destroy block\n");
    }
    else{
        printf("Couldn't destroy\n");
    }
    return 0;
}