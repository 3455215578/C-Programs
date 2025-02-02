#include <stdio.h>

int fun(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", fun(5));
	return 0;
}