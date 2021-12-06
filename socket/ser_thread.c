#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#define port 8080

void *connect_handle(void *argv){
    int fd; 
    fd=*(int *)argv;
    char mess[1024]="Greetings! I am your connection handler\n";
    //char client_mess[1000];
    write(fd,mess,strlen(mess));
    //memset(client_mess,0,sizeof(client_mess));
    //bzero(client_mess, 1000);
    while(1){
        memset(mess,0,sizeof(mess));
        read(fd,mess,sizeof(mess));
        printf("data recieve form client  : %s\n",mess);
        memset(mess,0,sizeof(mess));
        printf("Enter string : ");
        fgets(mess,sizeof(mess),stdin);
        write(fd,mess,strlen(mess));
        if(strncmp(mess,"exit",4)==0){
            printf("EXIT\n");
            break;
        }
            
        
        //memset(client_mess,0,sizeof(client_mess));
        
    
    }
    
   

    free(argv);
    return NULL;
}
int main(int argc, char **argv){

    int sockfd,new_sock,c,*temp_sock;
    
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
    if(listen(sockfd,5)<0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    puts("Waiting for incoming connections...");

    c=sizeof(struct sockaddr_in);

    while((new_sock=accept(sockfd,(struct sockaddr *)&client,(socklen_t *)&c))){
        printf("value new_sock = %d\n",new_sock);
        puts("Connection accepted");
        pthread_t con_thread;
        temp_sock=malloc(1);
        *temp_sock=new_sock;
        if(pthread_create(&con_thread,NULL,connect_handle,(void *)temp_sock)){
            perror("thread create");
            exit(EXIT_FAILURE);
        }
        puts("Handler assigned");
        
    }
    if(new_sock<0){
        perror("accept");
        exit(EXIT_FAILURE);
    }

    
    return 0;
}