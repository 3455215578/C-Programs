#include <stdio.h>

/** ���--�ǵݹ� **/
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

������������ʱ���������ջ�ڴ��У���ջ��ģʽ���úͷ���ֵ

**/

/** ���--�ݹ�(�ݽ�������) **/
int Sum_Recursion(int n)
{
	// �ݹ�ʱ��ȷ���ķ���ֵ�ͳ�ջ(����ȳ�)
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return Sum_Recursion(n - 1) + n;
	}
}

/** ����쳲��������е�n���ֵ(n >= 3) -- �ǵݹ� **/
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


/** ����쳲��������е�n���ֵ(n >= 3) -- �ݹ� **/
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