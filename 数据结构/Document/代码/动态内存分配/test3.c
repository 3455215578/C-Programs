#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int *arr = (int*)malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		arr[i] = 0;
	}
	
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}

    /*
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *(arr+i));
	}
	*/
	return 0;
}

