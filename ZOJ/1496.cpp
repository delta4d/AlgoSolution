#include<stdio.h>
#include<math.h>

#define PI 3.14159

int main(void)
{
	double f[3];
	double r[9];
	double d;
	double target;
	double opf;
	double opr;
	double gear;
	double c;
	double closest;
	long TestCase;
	long k;
	long i;
	long j;
	
	scanf("%ld", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		for (i=0; i<3; ++i)
		{
			scanf("%lf", f+i);
		}
		for (i=0; i<9; ++i)
		{
			scanf("%lf", r+i);
		}
		scanf("%lf %lf", &d, &target);
		
		closest = -999999999;
		
		for (i=0; i<3; ++i)
		{
			for (j=0; j<9; ++j)
			{
				c = PI * d;
				gear = f[i] / r[j] * c;
				
				if (fabs(gear - target) < fabs(closest - target))
				{
					opf = f[i];
					opr = r[j];
					closest = gear;
				}
				else if ((fabs(gear - target) == fabs(closest - target)) && (f[i] < opf))
				{
					opf = f[i];
					opr = r[j];
				}
			}
		}
		
		printf("A gear selection of %.0lf/%.0lf produces a gear size of %.3lf.\n", opf, opr, closest);
		
		if (k < TestCase - 1)
		{
			printf("\n");
		}
	}

	return 0;
}
