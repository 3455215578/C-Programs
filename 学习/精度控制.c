#include<stdio.h>
int main(void)
{
    double grade1, grade2;
    printf("请输入两个数字(用空格隔开):");
    scanf_s("%lf %lf", &grade1,&grade2);
    double all, ave;
    all = grade1 + grade2;
    ave = all / 2;
    printf("整数:%.0lf\n",all);
    printf("保留两位小数:%.2lf", ave);

    return 0;
}