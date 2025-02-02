#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char str[] = "HelloWorld";
	printf("%s\n", str);

	char str2[11];
	//str2 = "HelloWorld";
	strcpy(str2, "HelloWorld");
	printf("%s\n", str2);
	return 0;
}