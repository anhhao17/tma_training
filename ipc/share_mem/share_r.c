#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>

int main(int argc,char **argv){
    key_t key;

    char *str;

    key=ftok("anhhao",17);
    int shmid=shmget(key,1024,IPC_CREAT|0666);
    str=shmat(shmid,NULL,0);
    printf("Data: %s",str);
    
    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;

}