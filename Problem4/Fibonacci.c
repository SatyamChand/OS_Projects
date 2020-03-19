#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>


void *fibonacci_generator(void *ptr_array){
	int *arr;
	arr=(int*)ptr_array;

	

	printf("\nThe values are : \n");
	for(int i=1;i<=*arr;i++){
		printf("\n%d",*(arr+i));
	}
}

int main(){
	pthread_t thread;
	int value=0;
	int iret;
	printf("Please enter the number of terms you want to create in the Fibonacci series : ");
	scanf("%d",&value);
	int *array=calloc((value+1),sizeof(int));
	*array=value;
	iret=pthread_create(&thread,NULL,fibonacci_generator,(void*)array);
	pthread_join(thread,NULL);
	printf("\nThread1 returns : %d\n",iret);
	return 0;
}