#include<stdio.h>
#include<math.h>

#define PI 3.1415926535898

int main(void)
{
    int i;
    int j;
    double w;
    double h;
    double res;

    scanf("%lf %lf", &w, &h);

    while (w != 0.0 && h != 0.0)
    {
        res = 1;

        if ((int)w * (int)h % 2 == 1)
        {
            res = 0;
        }
        else
        {
            for (i=1; i<=w/2; ++i)
            {
                for (j=1; j<=h/2; ++j)
                {
                    res *= (4 * pow(cos(PI * i / (w + 1)), 2) + 4 * pow(cos(PI * j / (h + 1)), 2));
                }
            }
        }

        printf("%lld\n", (long long)(res + 0.5));

        scanf("%lf %lf", &w, &h);
    }

    return 0;
}
