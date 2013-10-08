/* +AMDG */

#include<stdio.h>
#include<float.h>

int main(void)
{
	double test;
	printf("DBL_DIG:  %d\n",DBL_DIG);
	printf("DBL_MAX:  %f\n",DBL_MAX);
	printf("-DBL_MAX:  %f\n",-DBL_MAX);
	test = DBL_MAX;
	printf("%f\n",test);
}
