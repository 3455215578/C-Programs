#include <stdio.h>
#include <math.h>
#define PI 3.141593


int day_peach(int n)
{	
	int num;
	if (n == 4)
	{
		num = 1;
	}
	else
	{
		num = 2 * (day_peach(n + 1) + 1);           // ���ݵ�����͵����������Ĺ�ϵ���Ƶõ�
	}
	return num;
}

void solve1()
{
		printf("I love Luogu!");
}
	
void solve2()
{
	int all, n_A, n_UIM;
	all = 10, n_A = 2, n_UIM = 4;
	printf("%d %d", n_A + n_UIM, all - (n_A + n_UIM));
}

void solve3()
{
	int all, num, ave;
	all = 14, num = 4;
	ave = (int)all / num;
	printf("%d\n", ave);
	printf("%d\n", ave * 4);
	printf("%d", all - ave * 4);
}

void solve4()
{
	int ml, num;
	double ave;
	ml = 500, num = 3;
	ave = ml * 1.0 / num;    // �˳�������������һ��Ϊ�������������Ϊ������
	printf("%.3lf", ave);
}

void solve5()
{
	// ���ҳ�Ϊ�ο�ϵ����׳�����ҵ��ٶ�Ϊv
	int v = 12 + 20;
	printf("%d", (260+220) / v);    // ע�����ռλ��
}

void solve6()
{
	double a;
	a = sqrt(6*6 + 9*9);                // sqrt��pow�����ı�������double����
	printf("%lf", a);
}

void solve7()
{
	int a = 100;
	printf("%d\n", a += 10);
	printf("%d\n", a -= 20);
	printf("%d", 0);
}

void solve8()
{
	int r = 5;
	printf("%f\n", 2 * PI * r);
	printf("%f\n", PI * r * r);
	printf("%f", (4 * PI * pow(r, 3)) / 3);
}

void solve9()   // �ݹ�
{
	printf("%d", day_peach(1));
}
	
void solve10()   
{
	printf("9");
}
	
void solve11()
{
	double t;
	t = 100 * 1.0 / 3;
	printf("%f", t);
}
	
void solve12()
{	
	char ch1, ch2;
	ch1 = 'A', ch2 = 'M';
	printf("%d\n", (ch2 - ch1) + 1);    // C�����е��ַ������Ͼ��������������ӡһ���ַ�ʱ����ʵ�������ڴ�ӡ���ַ���ASCIIֵ
	printf("%c", (char)(ch1 + 17));     // ����ַ�ʹ�õ���%c,����ַ���ʹ��%s
}

void solve13()
{
	int r1, r2;
	r1 = 4, r2 = 10;
	float V, a;
	V = 4 * PI / 3 * (pow(r1, 3) + pow(r2, 3));
	a = pow(V, 1.0/3);
	printf("%d", (int)a);
}

void solve14()
{
	printf("%d", 50);
}


int main(void)
{
	int t;
	scanf_s("%d", &t);
	if (t == 1)
	{
		solve1();
	}

	else if (t == 2)
	{
		solve2();
	}

	else if (t == 3)
	{
		solve3();
	}

	else if (t == 4)
	{
		solve4();
	}

	else if (t == 5)
	{
		solve5();
	}

	else if (t == 6)
	{
		solve6();
	}

	else if (t == 7)
	{
		solve7();
	}

	else if (t == 8)
	{
		solve8();
	}

	else if (t == 9)
	{
		solve9();
	}

	else if (t == 10)
	{
		solve10();
	}

	else if (t == 11)
	{
		solve11();
	}

	else if (t == 12)
	{
		solve12();
	}

	else if (t == 13)
	{
		solve13();
	}

	else if (t == 14)
	{
		solve14();
	}
	return 0;
}


