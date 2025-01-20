#include <stdio.h>

int main(void)
{
	int x;
	double money;
	scanf_s("%d", &x);
	if (x <= 150)
	{
		money = 0.4463 * x;
	}

	else if (x>=151 && x <= 400)
	{
		money = 0.4463 * 150 + 0.4663 * (x - 150);
	}

	else if (x >= 401)
	{
		money = 0.4463 * 150 + 0.4663 * 250 + 0.5663 * (x -400);
	}
	printf("%.1lf", money);
	return 0;
}