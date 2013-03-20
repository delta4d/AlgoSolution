#include<cstdio>
#include<memory>
using namespace std;

int d[49];
int record[1300];
int graph[49][49];
int num;
int n;

void euler(int x)
{
    int k;

    if (d[x] == 0)
    {
        record[num++] = x;
    }
    else
    {
        for (k=0; k<n; ++k)
        {
            if (graph[x][k] == 1 )
            {
                graph[x][k] = 0;
                graph[k][x] = 0;
                
                d[x]--;
                d[k]--;

                euler(k);
            }
        }

        record[num++] = x;
    }
}

int main()
{
    int i;
    int j;
    int k;
    int start;
    int len;

    while (scanf("%d", &n) != EOF)
    {
        for (i=0; i<n; ++i)
        {
            d[i] = n - 1;
        }

		for (i=0; i<n; ++i)
		{
			for (j=0; j<n; ++j)
			{
				graph[i][j] = 1;
			}
		}
		
		for (i=0; i<n; ++i)
		{
			graph[i][i] = 0;
		}
		
		num = 0;
		
		euler(0);

		printf("%d\n", n * (n - 1) / 2);

        for (i=n*(n-1)/2-1; i>0; --i)
        {
            printf("%d ", record[i]);
        }

        printf("%d\n", record[i]);
    }

    return 0;
}
