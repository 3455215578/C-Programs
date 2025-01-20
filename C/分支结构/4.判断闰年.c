#include <stdio.h>

int main(void)
{
	int n;
	scanf_s("%d", &n);
	if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

	return 0;
}