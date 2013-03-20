#include<stdio.h>
#include<memory.h>

#define debug 0
#define MaxN 200

char triangle[MaxN][2 * MaxN];
int right[MaxN][2 * MaxN];

int main(void)
{
    int i;
    int j;
    int k;
    int n;
    int max;
    int case_num = 1;

#if debug
    freopen("f:\\triangle.in", "r", stdin);
    freopen("f:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);

    while (n != 0)
    {
        for (i=0; i<n; ++i)
        {
            scanf("%s", triangle[i]);
        }

        memset(right, 0, sizeof(right));

        for (i=0; i<n; ++i)
        {
            for (j=2*(n-i)-2; j>=0; --j)
            {
                if (triangle[i][j] == triangle[i][j+1])
                {
                    right[i][j] = right[i][j+1] + 1;
                }
                else
                {
                    right[i][j] = 1;
                }
            }
        }

        max = 0;

        for (i=n-1; i>=0; --i)
        {
            for (j=0; j<2*(n-i)-1; j+=2)
            {
                if (triangle[i][j] == '-')
                {
                	for (k=1; i-k>=0; ++k)
                	{
                		if (triangle[i-k][j] == '-' && right[i-k][j] >= 2 * k + 1)
                		{
                			continue;
						}
						break;
					}
					
					if (k > max)
					{
						max = k;
					}
				}
            }
        }
        
        for (i=0; i<n; ++i)
        {
        	for (j=1; j<2*(n-i)-1; j+=2)
        	{
        		if (triangle[i][j] == '-')
        		{
        			for (k=1; k+i<n && j>=2*k; ++k)
        			{
        				if (triangle[i+k][j-2*k] == '-' && right[i+k][j-2*k] >= 2 * k + 1)
        				{
        					continue;
						}
						break;
					}
					
					if (k > max)
					{
						max = k;
					}
				}
			}
		}

        printf("Triangle #%d\n", case_num);
        ++case_num;
        printf("The largest triangle area is %d.\n\n", max * max);

        scanf("%d", &n);
    }

    return 0;
}
