#include<stdio.h>

#define MaxN 31

int f[MaxN];

int main(void)
{
	int up;
	int down;
	int up_len;
	int down_len;
	int count;
	int count_up;
	int count_down;
	int i;
	int j;
	int k;
	int len = 0;
	double avg_up;
	double avg_down;

	scanf("%d", f + len);
	
	while (f[len] != 0)
	{
		while (f[len] != 0)
		{
			++len;
			scanf("%d", f + len);
		}
		
		up_len = 0;
		down_len = 0;
		count_up = 0;
		count_down = 0;
		
		for (i=0; i<len; ++i)
		{
			up = 0;
			down = 0;
			count = -1;
			
			for (j=i; j<len-1; ++j)
			{
				++count;
				
				if ((up == 1) && (f[j] > f[j + 1]) || (down == 1) && (f[j] < f[j + 1]))
				{
					break;
				}
				
				if (f[j] < f[j + 1])
				{
					up = 1;
				}
				else if (f[j] > f[j + 1])
				{
					down = 1;
				}			
			}
			
			if (j == len - 1)
			{
				++count;
			}
			
			if (up == 1)
			{
				up_len += count;
				++count_up;
			}
			else if (down == 1)
			{
				down_len += count;
				++count_down;
			}
			
			if (j == len - 1)
			{
				break;
			}
			
			i = j - 1;
		}
		
		avg_up = avg_down = 0;
		
		if (count_up != 0)
		{
			avg_up = (double)up_len / (double)count_up;
		}
		
		if (count_down != 0)
		{
			avg_down = (double)down_len / (double)count_down;
		}
		
		printf("Nr values = %d:  %.6lf %.6lf\n", len, avg_up, avg_down);
		
		len = 0;
		scanf("%d", f + len);
	}
	
	return 0;
}
