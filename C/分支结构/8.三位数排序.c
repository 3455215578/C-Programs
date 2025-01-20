#include <stdio.h>



typedef struct
{
	int biggest;
	int bigger;
	int small;
}Seq;

void compare(int a, int b, int c, Seq* Result)       // �������÷���ֵ������������һ���ṹ��ָ��ĵ�ַ�󣬸ú����������Ľṹ���Աһ��ֵ
{
	
	
	// a���
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

	// b���
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

	// c���
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
	compare(a, b, c, &Num);           // ��������ṹ�壬�Ӹ�ȡ��ַ���ѽṹ��ĵ�ַ����ȥ���У��������Լ�����
	printf("%d %d %d", Num.small, Num.bigger, Num.biggest);
	
	return 0;
}