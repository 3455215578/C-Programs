#include <stdio.h>
#include <string.h>

/** �����ַ��� **/
/** �ַ��õ����ű�ʾ **/
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

	// �ַ�����ֵ

	//str = {"HelloWorld"};

	strcpy_s(str,sizeof("HelloWorld"),  "HelloWorld");
	printf("%s\n", str);
	printf("%d\n", strlen(str));


	return 0;
}