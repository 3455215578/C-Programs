#include <stdio.h>

typedef struct {

	int x;
	int y;

}Point_t;

// 学习封装思想

// 主函数中已经定义了一个结构体，在函数中又创建一个，比较占用内存，可传入结构体的地址来优化
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