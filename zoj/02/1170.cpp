#include<stdio.h>

#define MaxN 100

char s1[MaxN];
char s2[MaxN];
char temp[MaxN];

int gcd(int a, int b)
{
	int t;
	
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	
	return a;
}

int main(void)
{
	int i;
	int j;
	int k;
	int len1;
	int len2;
	int max;
	int cur;
	int g;
	
	scanf("%s", s1);
	
	while (strcmp(s1, "-1") != 0)
	{
		scanf("%s", temp);
		
		len1 = strlen(s1);
		len2 = strlen(temp);
		max = 0;
		
		for (i=0; i<len2; ++i)
		{
			s2[i + len1] = temp[i];
		}
		
		for (i=0; i<len1; ++i)
		{
			s2[i] = 'a';
		}
		
		for (i=len1+len2; i<MaxN; ++i)
		{
			s2[i] = 'a';
		}
		
		for (k=0; k<len1+len2; ++k)
		{
			cur = 0;
			
			for (i=0; i<len1; ++i)
			{
				if (s1[i] == s2[i+k])
				{
					++cur;
				}
			}
			
			if (cur > max)
			{
				max = cur;
			}
		}
		
		printf("appx(%s,%s) = ", s1, temp);
		
		if (max == 0)
		{
			printf("0\n");
		}
		else
		{
			g = gcd(max * 2, len1 + len2);
			
			if (g == len1 + len2)
			{
				printf("%d\n", max * 2 / g);
			}
			else
			{
				printf("%d/%d\n", max*2/g, (len1+len2)/g);
			}
		}
		
		scanf("%s", s1);
	}
	
	return 0;
}
