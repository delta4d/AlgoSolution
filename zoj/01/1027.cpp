#include<stdio.h>

long f[111][111];

long max3(long a, long b, long c)
{
	long res;
	
	res = a > b ? a : b;
	
	res = res > c ? res : c;
	
	return res;
}

long sw(char a)
{
	long t;
	
	if (a == 'A')
	{
		t = 0;
	}
	else if (a == 'C')
	{
		t = 1;
	}
	else if (a == 'G')
	{
		t = 2;
	}
	else if (a == 'T')
	{
		t = 3;
	}
	else
	{
		t = 4;
	}
	
	return t;
}

int main(void)
{
	long cost[5][5] = {{5, -1, -2, -1, -3},
					   {-1, 5, -3, -2, -4},
					   {-2, -3, 5, -2, -2}, 
					   {-1, -2, -2, 5, -1}, 
					   {-3, -4, -2, -1, -9999999}};
	
	long TestCase;
	long m;
	long n;
	long i;
	long j;
	long k;
	long tx;
	long ty;
	long max[3];
	char x[111];
	char y[111];
	
	f[0][0] = 0;
	
	scanf("%ld", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%ld %s", &m, x);
		scanf("%ld %s", &n, y);
		
		for (i=0; i<m; ++i)
		{
			tx = sw(x[i]);
			
			f[i+1][0] = cost[tx][4] + f[i][0];
		}
		
		for (i=0; i<n; ++i)
		{
			ty = sw(y[i]);
			
			f[0][i+1] = cost[4][ty] + f[0][i];
		}
		
		for (i=0; i<m; ++i)
		{
			tx = sw(x[i]);
			
			for (j=0; j<n; ++j)
			{
				ty = sw(y[j]);
				
				max[0] = f[i][j] + cost[tx][ty];
				max[1] = f[i][j+1] + cost[tx][4];
				max[2] = f[i+1][j] + cost[4][ty];
				
				f[i+1][j+1] = max3(max[0], max[1], max[2]);
			}
		}
		
		printf("%ld\n", f[m][n]);
	}
	
	return 0;
}