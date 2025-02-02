#include <stdio.h>

int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main(int argc, char const *argv[])
{
	printf("%d\n", fibonacci(6));
	return 0;
}




