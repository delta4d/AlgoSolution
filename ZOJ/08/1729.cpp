#include<stdio.h>

#define MaxN 100001

char s[MaxN];

int main(void)
{
	long i;
	long j;
	long k;
	long len;
	long t;
	long test_case;
	long res;
	long x;
	long y;
	
	scanf("%ld", &test_case);
	
	for (t=0; t<test_case; ++t)
	{
		scanf("%ld %s", &len, s);
		
		i = 0;
		j = 1;
		k = 0;
		
		while((i < len) && (j < len) && (k < len))
		{
			x = i + k >= len ? i + k - len : i + k;
			y = j + k >= len ? j + k - len : j + k;
			
			if(s[x] == s[y])
			   k++;
			else
			{
				if(s[x] > s[y])
				   i = i + k + 1;
	            else
	               j = j + k + 1;
	            
				if(i == j) j++;   
	            k = 0;   
			}
		}
		
		res = i;
		/*res = i < j ? i : j;*/
		
		printf("%ld\n", res);
	}
	
	return 0;
} 
