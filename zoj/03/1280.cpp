#include<stdio.h>

long x[4];
long y[4];

int main(void)
{
	int test_case;
	int i;
	int j;
	int k;
	double x0;
	double y0;
	long a[2];
	long b[2];
	long c[2];
	
	scanf("%d", &test_case);
	printf("INTERSECTING LINES OUTPUT\n");
	
	for (k=0; k<test_case; ++k)
	{
		for (i=0; i<4; ++i)
		{
			scanf("%ld %ld", x + i, y + i);
		}
		
		a[0] = y[1] - y[0];
		a[1] = y[3] - y[2];
		b[0] = -x[1] + x[0];
		b[1] = -x[3] + x[2];
		c[0] = -x[1] * (y[1] - y[0]) + y[1] * (x[1] - x[0]);
		c[1] = -x[3] * (y[3] - y[2]) + y[3] * (x[3] - x[2]);
		
		if ((a[0] * b[1] == a[1] * b[0]) && (b[0] * c[1] == b[1] * c[0]) && (a[0] * c[1] == a[1] * c[0]))
		{
			printf("LINE\n");
		}
		else if ((a[0] * b[1] == a[1] * b[0]) && ((b[0] * c[1] != b[1] * c[0]) || (a[0] * c[1] != a[1] * c[0])))
		{
			printf("NONE\n");
		}
		else
		{
			y0 = ((double)a[1] * c[0] - a[0] * c[1]) / ((double)a[0] * b[1] - a[1] * b[0]);
			
			if (a[0] != 0)
			{
				x0 = (-b[0] * y0 - c[0]) / (double)a[0];
			}
			else
			{
				x0 = (-b[1] * y0 - c[1]) / (double)a[1];
			}
			
			printf("POINT %.2lf %.2lf\n", x0, y0);
		}
	}
	
	printf("END OF OUTPUT\n");
	
	return 0;
}
