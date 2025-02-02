#include <stdio.h>
/*需求：
  计算1加到100的值，返回计算结果。
*/


int fun()
{
	//用来接收累加值
	int sum = 0;
	//从 1 循环到 100，每次将值累加到变量 sum
	for (int i = 1; i <= 100; i++)
	{
		//累加
		sum += i;
	}
	//返回计算结果
	return sum;
}


int main(int argc, char const *argv[])
{
	//调用fun()函数接收返回值
	int s = fun();
	//输出接收的计算结果
	printf("s=%d\n", s);
	return 0;
}