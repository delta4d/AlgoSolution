#include<stdio.h>
#include<memory.h>
#define MaxN 101
#define Inf 1001
#define Ref -1

int is_simple[MaxN];
int buff_min[MaxN];
int buff_max[MaxN];

int main(void)
{
	int i;
	int j;
	int kmin;
	int kmax;
	int t;
	int n;
	int p;
	int temp;
	int min;
	int max;
	int test_case;
	int find;
	
	scanf("%d", &test_case);
	
	for (t=1; t<=test_case; ++t)
	{
		scanf("%d %d", &n, &p);
		memset(is_simple, 0, sizeof(is_simple));
		
		for (i=0; i<n; ++i)
		{
			min = Inf;
		    max = Ref;
			kmin = 0;
			kmax = 0;
			
			for (j=1; j<=p; ++j)
			{
				scanf("%d", &temp);
				
				if (min > temp)
				{
					min = temp;
					buff_min[0] = j;
					kmin = 1;
				}
				else if (min == temp)
				{
					buff_min[kmin] = j;
					++kmin;
				}
				
				if (max < temp)
				{
					max = temp;
					buff_max[0] = j;
					kmax = 1;
				}
				else if (max == temp)
				{
					buff_max[kmax] = j;
					++kmax;
				}
			}
			
			for (j=0; j<kmin; ++j)
			{
				if (is_simple[buff_min[j]] >= 0)
				{
					++is_simple[buff_min[j]];
				}
			}
			
			for (j=0; j<kmax; ++j)
			{
				is_simple[buff_max[j]] = -1;
			}
		}
		
		find = 0;
		
		for (i=1; i<=p; ++i)
		{
			if (is_simple[i] > n/2)
			{
				find = 1;
				break;
			}
		}
		
		if (find == 1)
		{
			printf("%d", i);
			
			for (i=i+1; i<=p; ++i)
			{
				if (is_simple[i] > n/2)
				{
					printf(" %d", i);
				}
			}
			
			printf("\n");
		}
		else
		{
			printf("0\n");
		}
		
		if (t < test_case)
		{
			printf("\n");
		}
	}
	
	return 0;
}
