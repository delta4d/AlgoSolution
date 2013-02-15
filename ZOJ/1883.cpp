#include<stdio.h>

double f[10][10][101];

void dp()
{
    int i;
    int j;
    int k;

    for (k=0; k<=9; ++k)
    {
        for (i=0; i<=k; ++i)
        {
            f[k][i][1] = 1;
        }

        for (j=2; j<=100; ++j)
        {
            for (i=0; i<=k; ++i)
            {
                if (i == k)
                {
                    f[k][i][j] = f[k][i][j-1] + f[k][i-1][j-1];
                }
                else if (i == 0)
                {
                    f[k][i][j] = f[k][i][j-1] + f[k][i+1][j-1];
                }
                else
                {
                    f[k][i][j] = f[k][i-1][j-1] + f[k][i][j-1] + f[k][i+1][j-1];
                }
            }
        }
    }
}

int main(void)
{
    int k;
    int n;
    int i;
    int j;
    double res;

	dp();

    while (scanf("%d %d", &k, &n) != EOF)
    {
    	res = 0;
    	
        for (i=0; i<=k; ++i)
        {
        	res += f[k][i][n];
		}
		
		for (i=0; i<n; ++i)
		{
			res /= (double)(k+1);
		}
		
		res *= 100;
		
		printf("%.5lf\n", res);
    }

    return 0;
}
