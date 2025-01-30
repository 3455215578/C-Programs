#include <stdio.h>

/** 求和--非递归 **/
int Sum_Not_Recursion(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}

/**

当函数被调用时，它会进入栈内存中，以栈的模式调用和返回值

**/

/** 求和--递归(递进，归来) **/
int Sum_Recursion(int n)
{
	// 递归时有确定的返回值就出栈(后进先出)
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return Sum_Recursion(n - 1) + n;
	}
}

/** 返回斐波那契数列第n项的值(n >= 3) -- 非递归 **/
int Fibonacci_Not_Recursion(int n)
{
	int prev = 1;
	int curr = 1;
	int next;

	for (int i = 0; i < n - 2; i++)
	{
		next = prev + curr;

		prev = curr;
		curr = next;
	}

	return next;

}


/** 返回斐波那契数列第n项的值(n >= 3) -- 递归 **/
int Fibonacci_Recursion(int n)
{
	if ((n == 1) || (n == 2))
	{
		return 1;
	}

	return Fibonacci_Recursion(n - 2) + Fibonacci_Recursion(n - 1);
}

int main(void)
{
	int fifth_value = Fibonacci_Recursion(5);
	printf("%d\n", fifth_value);

	return 0;
}