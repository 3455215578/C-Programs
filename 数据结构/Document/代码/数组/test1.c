#include <stdio.h>

int main(int argc, char const *argv[])
{
	//声明一个长度为5的int数组
	int a[] = {16,47,89,42,38};
	
	//遍历数组
	for (int i = 0; i < 5; i++)
	{
		//按顺序输出数组中的每一个元素
		printf("%d\n", a[i]);

	}
}