#include<stdio.h>

char s[5001];
long len;

long checkodd(int k)
{
	int i;
	int res = 0;
	
	for (i=1; ((k-i>=0))&&(k+i<len); ++i)
	{
		if (s[k+i] != s[k-i])
		{
			break;
		}
		else
		{
			++res;
		}
	}
	
	return res;
}

long checkeven(int k)
{
	int i;
	int res = 1;
	
	for (i=1; ((k-i>=0))&&(k+1+i<len); ++i)
	{
		if (s[k+1+i] != s[k-i])
		{
			break;
		}
		else
		{
			++res;
		}
	}
	
	return res;
} 

int main(void)
{
	long i;
	long j;
	long k;
	long res;

	while (scanf("%s", s) != EOF)
	{
		len = strlen(s);
		res = len;
		
		for (i=0; i<len-1; ++i)
		{
			res += checkodd(i);
			
			if (s[i] == s[i+1])
			{
				res += checkeven(i);
			}
		}
		
		printf("%ld\n", res);
	}
	
	return 0;
}
