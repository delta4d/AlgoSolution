#include<cstdio>
#include<memory>
#include<cmath>

using namespace std;

const int MaxN = 729;
bool f[MaxN][MaxN];

void gen(void)
{
    int i;
    int j;
    int k;
    int t;
    int len;
    int x[4];
    int y[4];
    memset(f, false, sizeof(f));

    f[0][0] = true;

    for (k=1; k<7; ++k)
    {
        len = int(pow(3.0, double(k-1)));

        x[0] = 0;
        x[1] = len;
        x[2] = 2 * len;
        x[3] = 2 * len;
        y[0] = 2 * len;
        y[1] = len;
        y[2] = 0;
        y[3] = 2 * len;

        for (t=0; t<4; ++t)
        {
            for (i=x[t]; i<x[t]+len; ++i)
            {
                for (j=y[t]; j<y[t]+len; ++j)
                {
                    f[i][j] = f[i-x[t]][j-y[t]];
                }
            }
        }
    }
    
    return;
}

void draw(int d)
{
	int len = int(pow(3.0, double(d-1)));
	int i;
	int j;
	int k;
	
	for (i=0; i<len; ++i)
	{
		k = len - 1;
		
		while (!f[i][k])
		{
			--k;
		}
		
		for (j=0; j<=k; ++j)
		{
			if (f[i][j])
			{
				printf("X");
			}
			else
			{
				printf(" ");
			}
		}
		
		printf("\n");
	}
	
	printf("-\n");
	
	return;
}

int main(void)
{
    int n;

    gen();

    scanf("%d", &n);

    while (n != -1)
    {
        draw(n);

        scanf("%d", &n);
    }

    return 0;
}
