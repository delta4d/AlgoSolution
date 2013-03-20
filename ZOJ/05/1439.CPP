#include<stdio.h>
#include<math.h>

double distance(double x1, double y1, double z1, double x2, double y2, double z2)
{
	double dis;

	dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);

	dis = sqrt(dis);

	return dis;
}

double area(double a, double b, double c)
{
	double p;
	double res;

	p = (a + b + c) / 2;

	res = p * (p - a) * (p - b) * (p - c);

	res = sqrt(res);

	return res;
}

int main(void)
{
	double x1;
	double y1;
	double z1;
	double x2;
	double y2;
	double z2;
	double x3;
	double y3;
	double z3;
	double a;
	double b;
	double c;
	double S;
	double res;

	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3 ) != EOF)
	{
		a = distance(x1, y1, z1, x2, y2, z2);
		b = distance(x2, y2, z2, x3, y3, z3);
		c = distance(x3, y3, z3, x1, y1, z1);
		S = area(a, b, c);
		
		res = 8 * S * S / (a + b + c) / a / b / c;
		
		res = res * res;
		
		printf("%.3lf\n", res);
	}	
	
	return 0;
}
