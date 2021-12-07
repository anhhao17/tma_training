#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,char **argv){
    int arr[5];
    mkfifo("fifo",0777);
    srand(time(NULL));
    for (int i=0;i<5;i++){
        arr[i]=rand()%10;
        printf("Generated %d \n",arr[i]);
    }
    int fd=open("fifo",O_WRONLY);
    if(fd==-1){
        perror("Open");
        exit(EXIT_FAILURE);
    }
    if(write(fd,arr,sizeof(int)*5)==-1){
        perror("Write");
        exit(EXIT_FAILURE);
    }
    close(fd);
    return 0;
}