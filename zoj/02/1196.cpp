#include<stdio.h>
#include<math.h>

#define MaxN 201
#define MaxK 31

int d[MaxN];
int f[MaxN][MaxK];

int cost(int a, int b)
{
    int sum = 0;
    
    while (a < b)
    {
        sum += d[b] - d[a];
        ++a;
        --b;
    }
    
    return sum;
}

void calc_f(int n, int nk)
{
	int i;
	int j;
	int k;
	int min = -1;
	
	for (i=1; i<=n; ++i)
	{
		f[i][1] = cost(1, i);
	}
	
	for (i=1; i<=n; ++i)
	{
		for (j=2; j<=nk; ++j)
		{
			for (k=1; k<=i-j+1; ++k)
			{
				if (min > f[i-k][j-1] + cost(i-k+1, i) || min < 0)
				{
					min = f[i-k][j-1] + cost(i-k+1, i);
				}
			}
			
			f[i][j] = min;
			min = -1;
		}
	}
	
	return;
}

int main(void)
{
	int n;
	int k;
	int i;
	int j;
	int sum;
	int order = 1;
	
	scanf("%d %d", &n, &k);
	
	while (n != 0 || k != 0)
	{
		for (i=1; i<=n; ++i)
		{
			scanf("%d", d + i);
		}
		
		calc_f(n, k);
		
		printf("Chain %d\nTotal distance sum = %d\n\n", order, f[n][k]);
		++order;
		scanf("%d %d", &n, &k);
	}
	
	return 0;
}
