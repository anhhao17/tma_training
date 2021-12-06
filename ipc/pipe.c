#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char **argv){
    int fd[2];
    int id;
    if(pipe(fd)==-1){
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    id=fork();
    if(id==0){
        close(fd[0]);
        int x;
        printf("Enter number x = ");
        scanf("%d",&x);
        write(fd[1],&x,sizeof(int));
        close(fd[1]);
    }
    else{
        int y;
        close(fd[1]);
        read(fd[0],&y,sizeof(int ));
        printf("Read data y = %d\n",y);
        close(fd[0]);
    }
    return 0;
}