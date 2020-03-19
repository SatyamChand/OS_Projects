#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>


void *fibonacci_generator(void *ptr){
	int* value;
	value=(int*)ptr;
	printf("%d\n",value);
}

int main(){
	pthread_t thread;
	int value=0;
	int iret;
	printf("Please enter the number of terms you want to create in the Fibonacci series : ");
	scanf("%d",&value);
	int *n=value;
	iret=pthread_create(&thread,NULL,fibonacci_generator,(void*)n);
	pthread_join(thread,NULL);
	printf("Thread1 returns : %d\n",iret);
	return 0;
}