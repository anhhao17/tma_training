#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#define port 8080


void send_data(int sock_fd){
    char buff[1024];
    //int n;
    read(sock_fd,buff,sizeof(buff));
    printf("%s",buff);
    
    while(1){
        memset(buff,0,sizeof(buff));
        printf("enter string: ");
        fgets(buff,sizeof(buff),stdin);
        //n=0;
        //while ((buff[n++] = getchar()) != '\n');
        write(sock_fd,buff,sizeof(buff));
        memset(buff,0,sizeof(buff));
        read(sock_fd,buff,sizeof(buff));
        printf("From server : %s",buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
			printf("Client Exit...\n");
			break;
		}
       // memset(buff,0,sizeof(buff));
        
    };


}

int main(int argc,char **argv){

    int sock_fd;
    struct sockaddr_in address;
    char *hello="hello from client\n";
    char mess[1000]={0};
    sock_fd=socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd==-1){
        perror("Socket");
        exit(EXIT_FAILURE);
    }
    address.sin_port=htons(port);
    address.sin_family=AF_INET;
    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if(connect(sock_fd,(struct sockaddr *)&address,sizeof(address))==-1){
        perror("connect");
        exit(EXIT_FAILURE);  
    }
    puts("Connected\n");
    read(sock_fd,mess,1000);
    
    printf("data recieve : %s \n",mess);
    bzero(mess,1000);

    if(send(sock_fd,hello,strlen(hello),0)==-1){
        perror("send");
        exit(EXIT_FAILURE);
    }
    puts("data send\n");
    //
    send_data(sock_fd);
    close(sock_fd);
    return 0;
}