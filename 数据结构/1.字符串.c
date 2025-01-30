#include <stdio.h>
#include <string.h>

/** 遍历字符串 **/
/** 字符用单引号表示 **/
void Travel_String(const char* string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		printf("%c\n", string[i]);
	}
}

int main(void)
{
	char str[11];

	// 字符串赋值

	//str = {"HelloWorld"};

	strcpy_s(str,sizeof("HelloWorld"),  "HelloWorld");
	printf("%s\n", str);
	printf("%d\n", strlen(str));


	return 0;
}