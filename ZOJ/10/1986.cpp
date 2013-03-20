#include<stdio.h>

long res[41111];
long signal[41111];
long mark[41111];

void fill()
{
	long i;
	
	for (i=0; i<41111; i++)
	{
		mark[i] = 41111;
	}
	
	mark[0] = -1;
	
	return;
}

long find(long n, long len)
{
	long left = 1;
	long right = len;
	long middle = (left + right) / 2;
	long i;
	
    while (left <= right)
	{
		if (n < mark[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
		
		middle = (left + right) / 2;
	}
	
	return left;
}

int main()
{
	long testcase;
	long n;
	long k;
	long i;
	long j;
	long max;
	long loc;
	long len;
	
	scanf("%ld", &testcase);
	
	for (k=0; k<testcase; k++)
	{
		scanf("%ld", &n);
		scanf("%ld", signal);
		
		fill();
		len = 1;
		res[0] = 1;
		mark[1] = signal[0];
		max = 1;
		
		for (i=1; i<n; i++)
		{
			scanf("%ld", signal + i);
			
			loc = find(signal[i], len);
			
			if (mark[loc] < signal[i])
			{
				res[i] = loc + 1;
			}
			else
			{
				res[i] = loc;
			}
			
			if (mark[res[i]] > signal[i])
			{
				mark[res[i]] = signal[i];
			}
			
			if (res[i] > len)
			{
				len++;
			}
			
			if (max < res[i])
			{
				max = res[i];
			}
		}	
		
		printf("%ld\n", max);
	}
	
}