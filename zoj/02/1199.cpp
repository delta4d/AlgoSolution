#include<stdio.h>
#include<math.h>

double distance(double x1, double y1, double x2, double y2)
{
	double res;
	
	res = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	
	res = sqrt(res);
	
	return res;
}

int main(void)
{
	double x0;
	double x1;
	double x2;
	double y0;
	double y1;
	double y2;
	double r1;
	double r2;
	double t;
	double dis;
	int TestCase;
	int k;
	int i;
	int possible;
	
	scanf("%d", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
		
		dis = distance(x1, y1, x2, y2);
		
		possible = 1;
		
		if ((r1 == r2) || (dis <= fabs(r1-r2)))
		{
			possible = 0;
		}
		
		if (possible == 1)
		{
			if (r2 > r1)
			{
				t = x1;
				x1 = x2;
				x2 = t;
				t = y1;
				y1 = y2;
				y2 = t;
				t = r1;
				r1 = r2;
				r2 = t;
			}
			
			x0 = (x2 * r1 - x1 * r2) / (r1 - r2);
			y0 = (y2 * r1 - y1 * r2) / (r1 - r2);
			
			printf("%.2lf %.2lf\n", x0, y0);
		}
		else
		{
			printf("Impossible.\n");
		}
	}
	
	return 0;
}
