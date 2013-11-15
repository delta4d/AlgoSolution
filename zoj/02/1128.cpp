#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 256;
double x1[MAXN];
double y1[MAXN];
double x2[MAXN];
double y2[MAXN];
double x[MAXN<<1];
double y[MAXN<<1];

int main()
{
    int i;
    int j;
    int k;
    int t;
    int n;
    int cn(0);
    double area;

    //freopen("f:\\in.txt", "r", stdin);
    scanf("%d", &n);
    while (n != 0)
    {
        for (t=0; t<n; ++t)
        {
            scanf("%lf %lf %lf %lf", x1+t, y1+t, x2+t, y2+t);
            x[t<<1] = x1[t];
            x[(t<<1)+1] = x2[t];
            y[t<<1] = y1[t];
            y[(t<<1)+1] = y2[t];
        }
        sort(x, x+(n<<1));
        sort(y, y+(n<<1));
        area = 0;
        for (i=0; i<(n<<1)-1; ++i)
        {
            for (j=0; j<(n<<1)-1; ++j)
            {
                for (k=0; k<n; ++k)
                {
                    if (x[i] >= x1[k] && x[i+1] <= x2[k] && y[j] >= y1[k] && y[j+1] <= y2[k])
                    {
                        area += (x[i+1] - x[i]) * (y[j+1] - y[j]);
                        break;
                    }
                }
            }
        }
        printf("Test case #%d\n", ++cn);
        printf("Total explored area: %.2lf\n\n", area);
        scanf("%d", &n);
    }
    return 0;
}
