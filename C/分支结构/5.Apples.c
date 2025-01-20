#include <stdio.h>

int main(void)
{
	int x;
	scanf_s("%d", &x);

	if ((x == 0) || (x == 1))
	{
		printf("Today, I ate %d apple.", x);
	}

	else
	{
		printf("Today, I ate %d apples.", x);
	}

	return 0;
}