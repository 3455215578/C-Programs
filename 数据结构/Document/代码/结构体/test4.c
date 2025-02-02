#include <stdio.h>

typedef int myType1;
typedef char myType2;

int main(int argc, char const *argv[])
{
	myType1 a = 5;
	myType2 b = 'o';
	printf("%d\n", a);
	printf("%c\n", b);
	return 0;
}

