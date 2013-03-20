#include<stdio.h>
#include<memory.h>

#define MaxN 101

int s1[MaxN];
int s2[MaxN];
int dp[MaxN][MaxN];
int f[MaxN][MaxN];
int g[MaxN][MaxN];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int i;
    int j;
    int k;
    int n1;
    int n2;
    int test_case;

    scanf("%d", &test_case);

    for (k=0; k<test_case; ++k)
    {
        scanf("%d %d", &n1, &n2);

        for (i=1; i<=n1; ++i)
        {
            scanf("%d", s1 + i);
        }

        for (i=1; i<=n2; ++i)
        {
            scanf("%d", s2 + i);
        }

        memset(f, 0, sizeof(f));

        for (i=1; i<=n1; ++i)
        {
            for (j=1; j<=n2; ++j)
            {
                if (s1[i] == s2[j-1])
                {
                    f[i][j] = j - 1;
                }
                else
                {
                    f[i][j] = f[i][j-1];
                }
            }
        }

        for (j=1; j<=n2; j++)
        {
            for (i=1; i<=n1; i++)
            {
                if (s1[i-1] == s2[j])
				{	
					g[j][i] = i - 1;
				}
                else
				{
					g[j][i] = g[j][i-1];
				}
            }
        }

        for (i=1; i<=n1; ++i)
        {
            for (j=1; j<=n2; ++j)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                if (s1[i] == s2[j])
                {
                    continue;
                }
                
                if (g[j][i] == 0)
                {
                	continue;
				}
				
				if (f[i][j] == 0)
				{
					continue;
				}

                dp[i][j] = max(dp[i][j], dp[g[j][i]-1][f[i][j]-1] + 2);
            }
        }

        printf("%d\n", dp[n1][n2]);
    }

    return 0;
}
