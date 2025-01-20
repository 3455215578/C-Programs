#include <stdio.h>

int main(void)
{
	int x, n, week, day;
	scanf_s("%d %d", &x, &n);
	week = (int)n / 7;
	day = n % 7;
	if (x == 6)
	{
		printf("%d", 250*5*week + (day - 3)*250);
	}
	else if (x == 7)
	{
		printf("%d", 250 * 5 * week + (day - 2) * 250);
	}
}