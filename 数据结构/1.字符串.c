#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[11];

	// �ַ�����ֵ

	//str = {"HelloWorld"};

	strcpy_s(str,sizeof("HelloWorld"),  "HelloWorld");
	printf("%s\n", str);
	printf("%d\n", strlen(str));


	return 0;
}