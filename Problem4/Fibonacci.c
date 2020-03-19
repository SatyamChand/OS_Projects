#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>


void *fibonacci_generator(void *ptr_array){
	printf("Inside Generator\n");
	int *arr;
	arr=(int*)ptr_array;
	printf("%d",sizeof(*ptr_array));
	for(int i=0;i<5;i++){
		printf("\n%d",*(arr+i));
	}
}

int main(){
	pthread_t thread;
	int value=0, *array;
	int arr[]={1,2,3,4,6};
	array=arr;
	int iret;
	printf("Please enter the number of terms you want to create in the Fibonacci series : ");
	scanf("%d",&value);
	iret=pthread_create(&thread,NULL,fibonacci_generator,(void*)array);
	pthread_join(thread,NULL);
	printf("\nThread1 returns : %d\n",iret);
	return 0;
}