#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>


void *fibonacci_generator(void *ptr_array)
{	int *arr;
	arr=(int*)ptr_array;
	int terms=*arr;

	*(arr+1)=0;

	if(terms>1)
	{	*(arr+2)=1;

		for(int i=3;i<=terms;i++){
			*(arr+i)=*(arr+i-1)+*(arr+i-2);
		}
	}
}


int main()
{	pthread_t thread;
	int value=0;
	int iret;
	
	printf("Please enter the number of terms you want to create in the Fibonacci series : ");
	scanf("%d",&value);
	int *array=calloc((value+1),sizeof(int));
	*array=value;
	
	iret=pthread_create(&thread,NULL,fibonacci_generator,(void*)array);
	pthread_join(thread,NULL);

	printf("\nThe values are : \n");
	for(int i=1;i<=value;i++)
	{	if(i==value)
		{	printf("%d",*(array+i));
			break;
		}
		printf("%d, ",*(array+i));
	}
	printf("\n\n");
	
	free(array);
	return 0;
}