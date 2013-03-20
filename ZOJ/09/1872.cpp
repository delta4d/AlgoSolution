#include<cstdio>
#include<cmath>
#include<memory>
using namespace std;

const int MaxN = 100;
const double Inf = 999999999;

int n;
double x[MaxN];
double y[MaxN];
double dis[MaxN];
bool visit[MaxN];

double calc_dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void mst()
{
    int i;
    int j;
    int k;
    int index;
    double min;
    double len = 0;

    for (i=1; i<n; ++i)
    {
        dis[i] = Inf;
    }
    dis[0] = 0;
    memset(visit, false, sizeof(visit));

    for (j=0; j<n; ++j)
    {
        min = Inf;

        for (i=0; i<n; ++i)
        {
            if (!visit[i] && (min > dis[i]))
            {
                min = dis[i];
                index = i;
            }
        }
        
        visit[index] = true;

        for (i=0; i<n; ++i)
        {
            if (!visit[i] && (dis[i] > calc_dis(x[i], y[i], x[index], y[index])))
            {
                dis[i] = calc_dis(x[i], y[i], x[index], y[index]);
            }
        }
    }

    for (i=0; i<n; ++i)
    {
        len += dis[i];
    }

    printf("%.2lf\n", len);
}

int main(void)
{
    int i;

    while (scanf("%d", &n) != EOF)
    {
        for (i=0; i<n; ++i)
        {
            scanf("%lf %lf", x + i, y + i);
        }

        mst();
    }

    return 0;
}
