#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t lock;
int a=0;
void *func(void *argv){
	for(int i=0;i<100000;i++){
		a++;
	}
	pthread_exit(NULL);
}
int main(){
	pthread_t t1,t2;
	pthread_create(&t1,NULL,&func,NULL);
	pthread_create(&t2,NULL,&func,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("%d\n",a);
	return 0;
}