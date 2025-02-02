#include <stdio.h>
/*需求：
  程序中可能会有无数个位置用到1加到100的和，
  每次使用时都写出完整代码太麻烦,
  所以需要封装成函数，每次调用时只要写函数名即可。
*/

//函数fun()实现计算1加到100的和，并输出
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