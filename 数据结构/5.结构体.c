#include <stdio.h>

typedef struct {

	int x;
	int y;

}Point_t;

// ѧϰ��װ˼��

// ���������Ѿ�������һ���ṹ�壬�ں������ִ���һ�����Ƚ�ռ���ڴ棬�ɴ���ṹ��ĵ�ַ���Ż�
Point_t CreatePoint1(int x, int y)
{
	Point_t temp;

	temp.x = x;
	temp.y = y;

	return temp;
}

void CreatePoint2(Point_t* point, int x, int y)
{
	point->x = x;
	point->y = y;
}

void CreatePoint3(Point_t point, int x, int y)
{
	point.x = x;
	point.y = y;
}

int main(void)
{
	Point_t A;
	//CreatePoint2(&A, 10, 5);
	 CreatePoint3(A, 10, 5);
	//A = CreatePoint1(10, 5);

	printf("x=%d, y=%d", A.x, A.y);

	return 0;
}