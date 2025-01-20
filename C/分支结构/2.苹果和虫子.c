#include <stdio.h>
int main(void)
{
	unsigned int m, t, s;
	scanf_s("%d %d %d", &m, &t, &s);

	// 1.如果t=0,那么在一瞬间就会吃完所有苹果

	if (t == 0)
	{
		printf("0\n");
		return 0;
	}

	int eat = s / t;

	// 2.如果吃掉的苹果不是整数，那剩余那个就不能算是完整的

	if (s % t != 0)  // 判断整除
	{
		eat += 1;    // int向下取整,int(1.9) 也是等于1
	}

	// 3. 如果时间s过长使得 m-eat 为负数,输出0
	if (m - eat < 0)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", m - eat);
	}

	return 0;
}