#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t lock;
int a=0;
void *func(void *argv){
    for(int i=0;i<10000000;i++){
        pthread_mutex_lock(&lock);
        a++;
        pthread_mutex_unlock(&lock);

    }
    return NULL;
}
int main(){
	pthread_t t1,t2;
    if(pthread_mutex_init(&lock,NULL)){
        perror("pthread mutex");
        return 1;
    }
	pthread_create(&t1,NULL,&func,NULL);
	pthread_create(&t2,NULL,&func,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("%d\n",a);
    pthread_mutex_destroy(&lock);
	return 0;
}