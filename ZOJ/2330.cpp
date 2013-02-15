#include<stdio.h>
#include<math.h>

int main(void)
{
	double e = exp(1.0);
	double eps = 1e-14;
	double inc = 0.000001;
	double a;
	double t;
	double b;
	double i;
	double s;
	double left;
	double right;
	double mid;
	FILE * fp;
	
	/*fp = fopen("f:\\out1.txt", "w");*/
		
	/*for (a=1.1; a<e; a+=0.01)*/
	while (scanf("%lf", &a) != EOF)
	{
		if (a >= e)
		{
			/*fprintf(fp, "-1\n");*/
			printf("-1\n");
		}
		else
		{
			t = a / log(a);
			left = e;
			right = 44.0;
			mid = (left + right) / 2;
			
			while (left <= right + eps)
			{				
				if (fabs(mid/log(mid) - t) < eps)
				{
					break;
				}
				
				if (mid/log(mid) > t + eps)
				{
					right = mid;
				}
				else
				{
					left = mid;
				}
				
				mid = (left + right) / 2;
			}
			
			/*fprintf(fp, "%.5lf\n", mid);*/
			
			printf("%.5lf\n", mid);
		}
	}
	
	return 0;
}
