#include <stdio.h>
int main(void)
{
	unsigned int m, t, s;
	scanf_s("%d %d %d", &m, &t, &s);

	// 1.���t=0,��ô��һ˲��ͻ��������ƻ��

	if (t == 0)
	{
		printf("0\n");
		return 0;
	}

	int eat = s / t;

	// 2.����Ե���ƻ��������������ʣ���Ǹ��Ͳ�������������

	if (s % t != 0)  // �ж�����
	{
		eat += 1;    // int����ȡ��,int(1.9) Ҳ�ǵ���1
	}

	// 3. ���ʱ��s����ʹ�� m-eat Ϊ����,���0
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