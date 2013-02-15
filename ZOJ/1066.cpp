#include<stdio.h>
#include<memory.h>

#define debug 0
#define MaxN 50

int t;
int a[11][11];
int r[11][11];
int c[11][11];
char f[MaxN][MaxN];

void LT(int x, int y)
{
	f[x][y] = 'O';
	f[x][y-1] = '-';
	f[x][y-2] = 'H';
	f[x-1][y] = '|';
	f[x-2][y] = 'H';
}

void LB(int x, int y)
{
	f[x][y] = 'O';
	f[x][y-1] = '-';
	f[x][y-2] = 'H';
	f[x+1][y] = '|';
	f[x+2][y] = 'H';
}

void RB(int x, int y)
{
	f[x][y] = 'O';
	f[x][y+1] = '-';
	f[x][y+2] = 'H';
	f[x+1][y] = '|';
	f[x+2][y] = 'H';
}

void RT(int x, int y)
{
	f[x][y] = 'O';
	f[x][y+1] = '-';
	f[x][y+2] = 'H';
	f[x-1][y] = '|';
	f[x-2][y] = 'H';
}

void H(int x, int y)
{
	f[x][y] = 'O';
	f[x][y-1] = '-';
	f[x][y-2] = 'H';
	f[x][y+1] = '-';
	f[x][y+2] = 'H';
}

void V(int x, int y)
{
	f[x][y] = 'O';
	f[x-1][y] = '|';
	f[x-2][y] = 'H';
	f[x+1][y] = '|';
	f[x+2][y] = 'H';
}

int main(void)
{
	int case_num = 1;
	int i;
	int j;
	int k;
	int m;
	int n;
	
#if debug
	freopen("f:\\in.txt", "r", stdin);
	freopen("f:\\out.txt", "w", stdout);
#endif
	
	scanf("%d", &t);
	
	while (t != 0)
	{
		for (i=0; i<t; ++i)
		{
			for (j=0; j<t; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}
		
		memcpy(r, a, sizeof(a));
		memcpy(c, a, sizeof(a));
		
		for (i=1; i<t; ++i)
		{
			for (j=0; j<t; ++j)
			{
				c[i][j] = c[i-1][j] + a[i][j];
				r[j][i] = r[j][i-1] + a[j][i];
			}
		}

		memset(f, ' ', sizeof(f));
		
		for (i=0; i<t; ++i)
		{
			for (j=0; j<t; ++j)
			{
				m = 4 * i + 1;
				n = 4 * j + 3;
				if (a[i][j] == 1)
				{
					H(m, n);
				}
				else if (a[i][j] == -1)
				{
					V(m, n);
				}
				else
				{
					if (r[i][j] == 0 && c[i][j] == 1)
					{
						LT(m, n);
					}
					else if (r[i][j] == 0 && c[i][j] == 0)
					{
						LB(m, n);
					}
					else if (r[i][j] == 1 && c[i][j] == 0)
					{
						RB(m, n);
					}
					else
					{
						RT(m, n);
					}
				}
			}
		}
		
		m = 4 * t - 1;
		n = 4 * t + 3;
		
		for (i=0; i<n; ++i)
		{
			f[0][i] = '*';
			f[m-1][i] = '*';
		}
		for (i=0; i<m; ++i)
		{
			f[i][0] = '*';
			f[i][n-1] = '*';
			f[i][n] = '\0';
		}
		
		printf("Case %d:\n\n", case_num);
		++case_num;
		for (i=0; i<m; ++i)
		{
			printf("%s\n", f[i]);
		}
		
		scanf("%d", &t);
		
		if (t != 0)
		{
			printf("\n");
		}
	}
	
	return 0;
}
