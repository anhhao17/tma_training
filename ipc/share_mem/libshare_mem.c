#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <stdbool.h>

#include "libshare_mem.h"
static int get_shared_block(char *filename,int size){
    key_t key;
    int shmid;
    void *result;
    key=ftok("filename",17);
        
    shmid=shmget(key,size,IPC_CREAT|0666);
    if(shmid==-1){
        perror("shmid");
        return -1;
    }
    return shmid;
}
char  *get_attack(char *filename,int size){
    int shmid=get_shared_block(filename,size);
    if(shmid==-1){
        perror("get attack");
        return NULL;
    }
    void* result=shmat(shmid,NULL,0);
    if(result==(void*)-1)
        return NULL;
    return result;

}
bool get_detech(char *block){
    return (shmdt(block)!=-1);
}
bool destroy(char *filename){
    int shmid=get_shared_block(filename,0);
    if(shmid==-1){
        return NULL;
    }
    return (shmctl(shmid,IPC_RMID,NULL)!=-1);
}
