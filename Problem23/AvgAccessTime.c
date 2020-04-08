#include<stdio.h>
#include<unistd.h>

int main(){
	float Tnotmodified=8000;
	float Tmodified=20000;
	float Maccess=100;

	float Avg_time=200;

	float Page_modified=0.7;
	float Page_not_modified=1-Page_modified;

	float Avg_page_fault= (Page_not_modified*Tnotmodified + Page_modified*Tmodified) + Maccess;

	float Acceptable_rate=(Avg_time-Maccess)/(Avg_page_fault-Maccess);

	printf("%f\n", Avg_page_fault);
	printf("Aceptable page fault is : %f\n", Acceptable_rate);

	return 0;
}