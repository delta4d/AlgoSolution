#include<stdio.h>
#include<memory.h>
#include<math.h>

int bit[10][20];

int main(void)
{
    int i;
    int j;
    int k;
    int n;
    int x;
    int flag;

    while (scanf("%d", &n) != EOF)
    {
        memset(bit, 0, sizeof(bit));

        for (i=0; i<n; ++i)
        {
            j = 0;

            scanf("%d", &x);

            j=0;
            do
            {
                k = x % 10;
                
                if (k < 0)
                {
                    k = (int)fabs(k) + 10;
                }
                
                ++bit[j++][k];
                x = x / 10;
            }
            while (x);

        }

        flag = 0;

        for (i=9; i>=0; --i)
        {
            for (j=0; j<19; ++j)
            {
                if ((bit[i][j] > n/2) && (flag == 0))
                {
                    if (j>9)
                    {
                        printf("-");
                        printf("%d", j-10);
                    }
                    else
                    {
                        printf("%d", j);
                    }

                    flag = 1;
                    
                    break;
                }
                else if (bit[i][j] > n/2)
                {
                    if (j > 9)
                    {
                        printf("%d", j-10);
                    }
                    else
                    {
                        printf("%d", j);
                    }
                    
                    break;
                }
            }
        }

        printf("\n");
    }

    return 0;
}
