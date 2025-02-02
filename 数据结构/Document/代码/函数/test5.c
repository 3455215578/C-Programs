#include <stdio.h>
/*需求：
  计算1加到的n值，并输出计算结果，n的值在调用函数时传入。
*/


void fun(int n)
{
	//用来接收累加值
	int sum = 0;
	//从 1 循环到 100，每次将值累加到变量 sum
	for (int i = 1; i <= n; i++)
	{
		//累加
		sum += i;
	}
	//输出计算结果
	printf("sum=%d\n", sum);
}


int main(int argc, char const *argv[])
{
	//调用fun()函数,并传入参数
	fun(100);
	return 0;
}







