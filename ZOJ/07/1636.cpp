#include<stdio.h>
#include<memory.h>

long long matrix[501][501];

int main(void)
{
	long long i;
	long long j;
	long long k;
	long long t;
	long long m;
	long long n;
	long long r1;
	long long c1;
	long long r2;
	long long c2;
	long long sum;
	long long TestCase;
	long long order = 1;
	
	scanf("%lld", &TestCase);

	for (k=0; k<TestCase; ++k)
	{
		scanf("%lld %lld", &m, &n);
		
		memset(matrix, 0, sizeof(matrix));
		
		for (i=1; i<=m; ++i)
		{
			for (j=1; j<=n; ++j)
			{
				scanf("%lld", &t);
				
				matrix[i][j] = matrix[i][j-1] + matrix[i-1][j] - matrix[i-1][j-1] + t * t;
			}
		}
		
		scanf("%lld", &n);
		
		printf("Case %lld:\n", order);
		
		++order;
		
		for (t=0; t<n; ++t)
		{
			scanf("%lld %lld %lld %lld", &r1, &c1, &r2, &c2);
			
			sum = matrix[r2][c2] - matrix[r2][c1-1] - matrix[r1-1][c2] + matrix[r1-1][c1-1];			
			
			printf("%lld\n", sum);
		}
	}

	return 0;
}
