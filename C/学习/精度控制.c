#include<stdio.h>
int main(void)
{
    double grade1, grade2;
    printf("��������������(�ÿո����):");
    scanf_s("%lf %lf", &grade1,&grade2);
    double all, ave;
    all = grade1 + grade2;
    ave = all / 2;
    printf("����:%.0lf\n",all);
    printf("������λС��:%.2lf", ave);

    return 0;
}