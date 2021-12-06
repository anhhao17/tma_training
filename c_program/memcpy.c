#include <stdio.h>
#include <string.h>

int main(){
	int a=12;
	int b;
	printf("mempry %p\n%p\n",&a,&b);
	memcpy(&b,&a,sizeof(a));
	printf("mempry %d\n%d\n",a,b);

}