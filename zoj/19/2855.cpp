#include<stdio.h>
#include<math.h>

#define pi 3.141592653589

int main(void)
{
	double xl;
	double xr;
	double yt;
	double yb;
	double xp;
	double yp;
	double a;
	double b;
	double x;
	double y;
	int n;
	int i;
	
	while (scanf("%lf %lf %d", &a, &b, &n) != EOF)
	{
		xl = -pi;
		xr = pi;
		yt = log(tan(pi / 4.0 + 85.0 * pi / 360.0));
		yb = log(tan(pi / 4.0 - 85.0 * pi / 360.0));
		x = a * pi / 180.0;
		y = log(tan(pi / 4.0 + b * pi / 360.0));
		
		printf("t");
		
		for (i=0; i<n; ++i)
		{
			xp = (xl + xr) / 2.0;
			yp = (yt + yb) / 2.0;
			
			if ((x < xp) && (y > yp))
			{
				printf("q");
				xr = xp;
				yb = yp;
			}
			else if ((x > xp) && (y > yp))
			{
				printf("r");
				xl = xp;
				yb = yp;
			}
			else if ((x < xp) && (y < yp))
			{
				printf("t");
				xr = xp;
				yt = yp;
			}
			else
			{
				printf("s");
				xl = xp;
				yt = yp;
			}
		}
		
		printf("\n");
	}
	
	return 0;
}
