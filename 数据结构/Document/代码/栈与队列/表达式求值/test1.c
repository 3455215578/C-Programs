#include <stdio.h>

enum weekday
{
	mon=1, tue, wed, thu, fri, sat, sun
};



int main(int argc, char const *argv[])
{
	enum weekday a;
	a = mon;
	enum weekday b;
	b = tue;
	printf("%d\n", a);
	printf("%d\n", b);
	return 0;
}