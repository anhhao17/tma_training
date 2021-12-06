#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define port 8080
int main(int argc, char **argv){

    int sockfd,new_sock,c;
    char *mess;
    char mess_recv[1000];
    struct sockaddr_in address,client;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        perror("socket");
        exit(EXIT_FAILURE);
    }
    address.sin_port=htons(port);
    address.sin_addr.s_addr=INADDR_ANY;
    address.sin_family=AF_INET;
    if(bind(sockfd,(struct sockaddr *)&address,sizeof(address))<0){
        perror("bind");
        exit(EXIT_FAILURE);
    }
    puts("bind done");
    if(listen(sockfd,2)<0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    puts("Waiting for incoming connections...");

    c=sizeof(struct sockaddr_in);
/*
    while((new_sock=accept(sockfd,(struct sockaddr *)&client,(socklen_t *)&c))){
        puts("Connection accepted");
        mess="hello client, I reviced your connection \n";
        write(new_sock,mess,strlen(mess));


    }
*/
    
    new_sock=accept(sockfd,(struct sockaddr *)&client,(socklen_t *)&c);
    if(new_sock==-1){
        perror("accept");
        exit(EXIT_FAILURE);
    }
    puts("Connection accepted");
    mess="hello client, I reviced your connection \n";
    write(new_sock,mess,strlen(mess));
    memset(mess_recv,0,sizeof(mess_recv));
    if(recv(new_sock,mess_recv,1000,0)<0){
        perror("revice data");
        exit(EXIT_FAILURE);
    }
    printf("Data recived from client : %s \n",mess_recv);
    


    if(new_sock<0){
        perror("accept");
        exit(EXIT_FAILURE);
    }

    
    return 0;
}