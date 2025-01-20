#include<stdio.h>
int main(void)
{
	enum DAY { MON = 1, TUE, WED, THU£¬FRI, SAT, SUN };
	enum DAY date = MON;
	printf("date = %d\n", date);
	return 0;
}