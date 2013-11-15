#include <cstdio>
#include <memory>
using namespace std;

#define debug 1
const int INF = 0x7ffffff;
const int MaxN = 201;
int w[6];
int f[MaxN];

void gao()
{
    int i;
    int j;
    int k;
    int sum(0);
    int max(0);
    bool over(false);
    fill(f, f+MaxN, INF);
    for (i=0; i<6; ++i)
    {
        f[w[i]] = 1;
    }
    while (!over)
    {
    	over = true;
        for (i=1; i<MaxN; ++i)
        {
            if (f[i] != INF)
            {
            	for (j=0; j<6; ++j)
            	{
            		if (i - w[j] > 0 && f[i-w[j]] > f[i] + 1)
            		{
            			over = false;
            			f[i-w[j]] = f[i] + 1;
					}
					if (i + w[j] < MaxN && f[i+w[j]] > f[i] + 1)
					{
						over = false;			
						f[i+w[j]] = f[i] + 1;
					}
				}
			}
        }
    }
    for (i=1; i<=MaxN/2; ++i)
    {
    	sum += f[i];
    	max = max < f[i] ? f[i] : max;
	}
	printf("%.2lf %d\n", sum/100.0, max);
}

int main()
{
    int i;
    int k;
    int tc;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
    scanf("%d", &tc);
    for (k=0; k<tc; ++k)
    {
        for (i=0; i<6; ++i) scanf("%d", w+i);
        gao();
    }

    return 0;
}