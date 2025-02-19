#include "stdio.h"


int main(void)
{
    union {
        float array[2][1];
        struct {
            float T1_set_point;
            float T4_set_point;
        } E;

    } T1_T4_set_point;

    T1_T4_set_point.E.T1_set_point = 2.0f;
    T1_T4_set_point.E.T4_set_point = 4.0f;
        
    printf("%f %f\n", T1_T4_set_point.array[0][0], T1_T4_set_point.array[1][0]);

	return 0;
}