#include<stdio.h>

#define MaxN 100002

long long left[MaxN];
long long right[MaxN];
long long height[MaxN];

int main(void)
{
	long long i;
	long long j;
	long long n;
	long long max;
	long long temp;
	
	scanf("%lld", &n);
	
	while (n != 0)
	{
		for (i=1; i<=n; ++i)
		{
			scanf("%lld", height + i);
		}
		
		height[0] = height[n + 1] = -1;
		
		for (i=1; i<=n; ++i)
		{
			left[i] = right[i] = i;
		}
		
		for (i=1; i<=n; ++i)
		{
			while (height[left[i] - 1] >= height[i])
			{
				left[i] = left[left[i] - 1];
			}
		}
		
		for (i=n; i>=1; --i)
		{
			while (height[right[i] + 1] >= height[i])
			{
				right[i] = right[right[i]+1];
			}
		}
		
		max = 0;
		
		for (i=1; i<=n; ++i)
		{
			temp = (right[i] - left[i] + 1) * height[i];
			
			if (max < temp)
			{
				max = temp;
			}
		}
		
		printf("%lld\n", max);
		
		scanf("%lld", &n);
	}
	
	return 0;
}
