#include <stdio.h>

typedef enum
{
	mon=1, tue, wed, thu, fri, sat, sun
} weekday;

int main(int argc, char const *argv[])
{
	weekday a;
	a = mon;
	printf("%d\n", a);
	return 0;
}