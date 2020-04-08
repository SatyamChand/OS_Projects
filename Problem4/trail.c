#include<stdio.h>

int main()
{	long * a;
	long c=1;
	*a=c;
	unsigned long *b=(unsigned long*)a;
	printf("%lu\n", *b);
	return 0;
}