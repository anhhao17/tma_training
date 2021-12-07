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
    if(key==(-1))
        perror("ftok");
    int shmid=shmget(key,1024,IPC_CREAT|0666);
    str=shmat(shmid,NULL,0);
    printf("Enter data: ");
    fgets(str,64,stdin);
    shmdt(str);
    return 0;

}