#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char *s;
	s = (char*)malloc(10);
	strcpy(s, "Hello");
	printf("%s\n", s);
	return 0;
}