#include <stdio.h>
#include <math.h>

int main(void)
{
	double m, h, bmi;
	scanf_s("%lf %lf", &m, &h);
	bmi = m / (h * h);

	if (bmi < 18.5)
	{
		printf("Underweight");
	}
	else if ((bmi >= 18.5) && (bmi < 24))
	{
		printf("Normal");
	}
	else if (bmi >= 24)
	{
		double x1 = bmi * 10000;      // �жϵ�6λ��Ч�����Ƿ�Ϊ0
		int x2 = round(x1);           // <math.h>�������뺯��
		if ((x2 % 10) == 0)            
		{
			printf("%.3lf\n", bmi);
			printf("Overweight");
		}
		else
		{
			printf("%.4lf\n", bmi);
			printf("Overweight");
		}
	}
	return 0;
}