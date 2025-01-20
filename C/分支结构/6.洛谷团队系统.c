#include <stdio.h>

int local(int n)
{
	return 5 * n;
}

int luogu(int n)
{
	return 11+3*n;
}

int main(void)
{
	int n;
	scanf_s("%d", &n);

	if (local(n) < luogu(n))
		printf("Local");
	else
	{
		printf("Luogu");
	}

	return 0;
}