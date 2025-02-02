#include <stdio.h>

struct point
{
	int x;
	int y;
};

int main(int argc, char const *argv[])
{
	struct point p;
    p.x = 5;
    p.y = 10;

	struct point *pp;
    pp = &p;

    (*pp).x = 10;
    (*pp).y = 5;

    printf("x=%d,y=%d\n", p.x, p.y);
    printf("x=%d,y=%d\n", pp->x, pp->y);
	return 0;
}







