#include <stdio.h>

_Bool year(int n)
{
	if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int n, x;
	scanf_s("%d %d", &n, &x);
	if (year(n) == 1)
	{
		if (x == 2)
		{
			printf("29\n");
		}
		else 
		{
			if (x == 1 | x == 3 | x == 5 | x == 7 | x == 8 | x == 10 | x == 12)
			{
				printf("31");
			}
			else
			{
				printf("30");
			}
		}
	}
	else
	{
		if (x == 2)
		{
			printf("28\n");
		}
		else
		{
			if (x == 1 | x == 3 | x == 5 | x == 7 | x == 8 | x == 10 | x == 12)
			{
				printf("31");
			}
			else
			{
				printf("30");
			}
		}
	}
}