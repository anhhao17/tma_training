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
    int sum=0;
    //mkfifo("fifo",0777);
    int fd=open("fifo",O_RDONLY);
    if(fd==-1){
        perror("Open");
        exit(EXIT_FAILURE);
    }
    if(read(fd,arr,sizeof(int)*5)==-1){
        perror("Read");
        exit(EXIT_FAILURE);
    }
    close(fd);
    for(int i=0;i<5;i++){
        sum+=arr[i];
    }
    printf("Sum = %d\n",sum);
    return 0;
}