#include<stdio.h>
#include<memory.h>

int f[1001];
int val[10];
int num[10];

int main(void)
{
    int m;
    int n;
    int valt;
    int numt;
    int i;
    int j;
    int k;

	scanf("%d %d", &n, &m);

    while (1)
    {
        for (i=0; i<m; ++i)
        {
            scanf("%d %d", val + i, num + i);
        }

        memset(f, 0, sizeof(f));

        f[0] = 1;

        for (i=0; i<m; ++i)
        {
            for (k=n; k>=0; --k)
            {
                if (f[k] != 0)
                {
					for (j=1; j<=num[i]; ++j)
					{
						if (k + j * val[i] <= n)
						{
							f[k + j * val[i]] += f[k];
						}
					}
                }
            }
        }
        
        printf("%d\n", f[n]);
        
        if (scanf("%d %d", &n, &m) != EOF)
        {
        	printf("\n");
		}
		else
		{
			break;
		}
    }

    return 0;
}
