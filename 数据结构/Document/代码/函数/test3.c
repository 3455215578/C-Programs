#include <stdio.h>
/*需求：
  计算1加到100的值并输出结果
*/

void fun()
{
	//用来接收累加值
	int sum = 0;
	//从 1 循环到 100，每次将值累加到变量 sum
	for (int i = 1; i <= 100; i++)
	{
		//累加
		sum += i;
	}
	//输出结果
	printf("sum=%d\n", sum);
}


int main(int argc, char const *argv[])
{
	//调用fun()函数
	fun();
	return 0;
}