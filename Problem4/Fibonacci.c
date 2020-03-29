#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>


void *fibonacci_generator(void *ptr_array)
{	int *arr;
	arr=(int*)ptr_array;																				//Typecasting back to int array pointer
	int terms=*arr;																						//Using first element to determine the size of array

	*(arr+1)=0;																							//Finding and assigning the terms of Fibonacci series

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
	
	printf("Please enter the number of terms you want to create in the Fibonacci series : ");
	scanf("%d",&value);
	int *array=calloc((value+1),sizeof(int));															//Creation of array for the series dynamically
	*array=value;																						//Initialising first element to show the length of the series
	
	pthread_create(&thread,NULL,fibonacci_generator,(void*)array);										//Implementing thread
	pthread_join(thread,NULL);

	printf("\nThe values are : \n");																	//Printing values after termination of child thread
	for(int i=1;i<=value;i++)
	{	if(i==value)
		{	printf("%d",*(array+i));
			break;
		}
		printf("%d, ",*(array+i));
	}
	printf("\n\n");
	
	free(array);																						//Deallocating the space
	return 0;
}