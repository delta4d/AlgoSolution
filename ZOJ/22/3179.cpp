#include<stdio.h>
#include<math.h>

char f[7][7];

int main(void)
{
	long test_case;
	long i;
	long j;
	long k;
	long sum;
	long x;
	long y;
	long temp;
	
	scanf("%ld", &test_case);
	
	for (k=0; k<test_case; ++k)
	{
		scanf("%ld %ld", &x, &y);
		sum = (x + y) * (y - x + 1) / 2;
		
		for (i=0; i<8; ++i)
		{
			if (i == 2)
			{
				scanf("%s", f[i]);
				continue;
			}
			
			if (i<2)
			{
				scanf("%s", f[i]);
			}
			else
			{
				scanf("%s", f[i-1]);
			}
		}
		
		temp = 0;
		
		for (i=0; i<6; ++i)
		{
			if (f[1][i] == 'o')
			{
				temp += 5 * (long)pow(10, 5-i);
			}
		}
		
		for (i=0; i<6; ++i)
		{
			j = 2;
			
			while (f[j][i] == 'o')
			{
				++j;
			}
			
			temp += (j - 2) * (long)pow(10, 5-i);			
		}
		
		if (temp == sum)
		{
			printf("No mistake\n");
		}
		else
		{
			printf("Mistake\n");
		}
	}
	
	return 0;
}
