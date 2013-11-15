#include<stdio.h>

#define MaxN 100005

long long front[MaxN];
long long rear[MaxN];
long long height[MaxN];

int main()
{
	long long i;
	long long n;
	long long max;
	long long cur;
	
	scanf("%lld", &n);
	
	while (n != 0)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%lld", height + i);
		}
		
		front[0] = 1;
		
		for (i=1; i<n; ++i)
		{
			if (height[i] > height[i-1])
			{
				front[i] = 1;
			}
			else
			{
				front[i] = front[i-1] + 1;
			}
		}
		
		rear[n-1] = 1;
		
		for (i=n-2; i>=0; --i)
		{
			if (height[i] > height[i+1])
			{
				rear[i] = 1;
			}
			else
			{
				rear[i] = rear[i+1] + 1;
			}
		}
		
		max = 0;
		
		for (i=0; i<n; ++i)
		{
			cur = (front[i] + rear[i] - 1) * height[i];
			
			if (max < cur)
			{
				max = cur;
			}
		}
		
		printf("%lld\n", max);
		
		scanf("%lld", &n);
	}
	
	return 0;
}
