#include<stdio.h>
#include<memory.h>

#define MaxN 99

double f[MaxN][MaxN];
double temp[MaxN][MaxN];
int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int border(int x, int y)
{
	if ((x >= 0) && (x < n) && (y >= 0) && (y < n))
	{
		return 1;
	}
	
	return 0;
}

double P(int x, int y)
{
	if ((x > 0) && (x < n - 1) && (y > 0) && (y < n - 1))
	{
		return 1.0 / 4.0;
	}
	
	if (((x == 0) && (y == 0)) || ((x == 0) && (y == n - 1)) ||
	    ((x == n - 1) && (y == 0)) || ((x == n - 1) && (y == n - 1)))
	{
		return 1.0 / 2.0;
	}
	
	return 1.0 / 3.0;
}

double solve()
{
	int i;
	int j;
	int k;
	int tx;
	int ty;
	int t;
	double p;
	double res = 0;
	memset(f, 0, sizeof(f));
	f[n/2][n/2] = 1;
	
	for (k=0; k<n; ++k)
	{		
		memset(temp, 0, sizeof(temp));
		
		for (i=0; i<n; ++i)
		{
			for (j=0; j<n; ++j)
			{
				if (f[i][j] != 0)
				{
					p = P(i, j);
					
					for (t=0; t<4; ++t)
					{
						tx = i + dx[t];
						ty = j + dy[t];
						
						if (border(tx, ty))
						{
							temp[tx][ty] += f[i][j] * p;
						}
					}
				}
			}
		}
		
		res += temp[k][n/2];
		memcpy(f, temp, sizeof(temp));
		f[k][n/2] = 0;
	}
	
	return res;
}

int main(void)
{
	double res;
	
	while (scanf("%d", &n) != EOF)
	{
		res = solve();
		
		printf("%.4lf\n", res);
	}
	
	return 0;
}
