#include <stdio.h>



typedef struct
{
	int biggest;
	int bigger;
	int small;
}Seq;

void compare(int a, int b, int c, Seq* Result)       // 函数不用返回值，主函数传来一个结构体指针的地址后，该函数会给里面的结构体成员一个值
{
	
	
	// a最大
	if ((a>=b) && (a>=c))
	{
		Result->biggest = a;
		if (b >= c)
		{
			Result->bigger = b;
			Result->small = c;
		}
		else if (b <= c)
		{
			Result->bigger = c;
			Result->small = b;
		}

	}

	// b最大
	else if ((b >= a) && (b >= c))
	{
		Result->biggest = b;
		if (a >= c)
		{
			Result->bigger = a;
			Result->small = c;
		}
		else if (a <= c)
		{
			Result->bigger = c;
			Result->small = a;
		}
	}

	// c最大
	else if ((c >= a) && (c >= b))
	{
		Result->biggest = c;
		if (a >= b)
		{
			Result->bigger = a;
			Result->small = b;
		}
		else if (a <= b)
		{
			Result->bigger = b;
			Result->small = a;
		}
	}

}

int main(void)
{
	int a, b, c;
	Seq Num;
	scanf_s("%d %d %d", &a, &b, &c);
	compare(a, b, c, &Num);           // 正常定义结构体，加个取地址符把结构体的地址传过去就行，函数会自己补充
	printf("%d %d %d", Num.small, Num.bigger, Num.biggest);
	
	return 0;
}