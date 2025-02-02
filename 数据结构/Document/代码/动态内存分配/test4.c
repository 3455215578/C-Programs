#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	int x;
	int y;
}po;

int main(int argc, char const *argv[])
{
	po *p;
	p = (po*)malloc(sizeof(po));
	p->x = 5;
	p->y = 10;
	printf("%d\n", p->x);
	printf("%d\n", p->y);
	return 0;
}





