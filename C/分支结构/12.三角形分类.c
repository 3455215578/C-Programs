#include <stdio.h>
#include <math.h>

int RAO_judge(int a, int b, int c)          // 判断三角形是不是直角 锐角 钝角...
{
	int biggest = 0, bigger = 0, small = 0;
	if ((a >= b) && (a >= c))
	{
		biggest = a;
		if (b >= c)
		{
			bigger = b;
			small = c;
		}
		else if (b <= c)
		{
			bigger = c;
			small = b;
		}

	}

	
	else if ((b >= a) && (b >= c))
	{
		biggest = b;
		if (a >= c)
		{
			bigger = a;
			small = c;
		}
		else if (a <= c)
		{
			bigger = c;
			small = a;
		}
	}

	
	else if ((c >= a) && (c >= b))
	{
		biggest = c;
		if (a >= b)
		{
			bigger = a;
			small = b;
		}
		else if (a <= b)
		{
			bigger = b;
			small = a;
		}
	}

	int d;
	d = sqrt(bigger*bigger + small* small);

	if (biggest > d)  // 钝角三角形
	{
		return 0;      
	}
	else if (biggest == d)  // 直角三角形
	{
		return 1;
	}
	if (biggest < d)  // 锐角三角形
	{
		return 2;
	}
}
int main(void)
{
	int a, b, c,x;
	scanf_s("%d %d %d",&a, &b, &c);
	x = RAO_judge(a, b, c);
	if ((a + b <= c) | (b + c <= a) | (a + c <= b))
	{
		printf("Not triangle");
	}

	else
	{
		if (x == 0)
		{
			if ((a == b) || (a == c) || (b == c))
			{
				printf("Obtuse triangle\n");
				printf("Isosceles triangle\n");
			}
			else
			{
				printf("Obtuse triangle\n");
			}
		}

		else if (x == 1)
		{
			if ((a == b) || (a == c) || (b == c))
			{
				printf("Right triangle\n");
				printf("Isosceles triangle\n");
			}
			else
			{
				printf("Right triangle\n");
			}
		}

		if (x == 2)
		{
			if ((a == b) || (a == c) || (b == c))
			{
				if (a == b && b == c)
				{
					printf("Acute triangle\n");
					printf("Isosceles triangle\n");
					printf("Equilateral triangle\n");
					
				}
				else
				{
					printf("Acute triangle\n");
					printf("Isosceles triangle\n");
				}
			}
			else
			{
				printf("Acute triangle\n");
			}
		}
	}
	return 0;
}