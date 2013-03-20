#include<stdio.h>
#include<math.h>

double dis(double x1, double x2, double y1, double y2, double z1, double z2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

double dotp(double x1, double x2, double y1, double y2, double z1, double z2)
{
    return x1 * x2 + y1 * y2 + z1 * z2;
}

int main(void)
{
    double x0;
    double x1;
    double x2;
    double xt;
    double y0;
    double y1;
    double y2;
    double yt;
    double z0;
    double z1;
    double z2;
    double zt;
    double max;
    double t;
    double a;
    double b;
    double c;
    double temp;
    long n;
    long i;
    long j;
    long k;

    while (scanf("%ld", &n) != EOF)
    {
        scanf("%lf %lf %lf", &x1, &y1, &z1);
        scanf("%lf %lf %lf", &x2, &y2, &z2);

        a = x2 - x1;
        b = y2 - y1;
        c = z2 - z1;
        max = -1.0;

        for (i=0; i<n; ++i)
        {
            scanf("%lf %lf %lf", &x0, &y0, &z0);

            t = dotp(a, x0-x2, b, y0-y2, c, z0 - z2) / dotp(a, a, b, b, c, c);
            xt = a * t + x2;
            yt = b * t + y2;
            zt = c * t + z2;

            if (((x1 <= x2) && (xt >= x1) || (x1 >= x2) && (xt <= x1))
                    &&((y1 <= y2) && (yt >= y1) || (y1 >= y2) && (yt <= y1))
                    &&((z1 <= z2) && (zt >= z1) || (z1 >= z2) && (zt <= z1)))
            {
                temp = dis(xt, x0, yt, y0, zt, z0);
            }
            else
            {
                temp = dis(x1, x0, y1, y0, z1, z0);
            }
            
            if (temp > max)
            {
                max = temp;
            }
        }
        
        printf("%.2lf\n", max);
    }

    return 0;
}
