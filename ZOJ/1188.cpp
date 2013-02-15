#include<stdio.h>
#include<stdlib.h>

struct Strings
{
	char str[51];
	int rev;
	int position;
}f[100];

int cmp(const void * a, const void * b)
{
	struct Strings * c = (struct Strings *) a;
	struct Strings * d = (struct Strings *) b;
	
	if (c -> rev != d -> rev)
	{
		return c -> rev - d -> rev; 
	}
	else
	{
		return c -> position - d -> position;
	}
}

int main(void)
{
	int TestCase;
	int k;
	int i;
	int j;
	int x;
	int n;
	int m;
	
	scanf("%d", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%d %d", &n, &m);
		
		for (i=0; i<m; ++i)
		{
			scanf("%s", f[i].str);
			f[i].rev = 0;
			f[i].position = i;
		}
		
		for (i=0; i<m; ++i)
		{
			for (j=0; j<n; ++j)
			{
				for (x=j+1; x<n; ++x)
				{
					if (f[i].str[x] < f[i].str[j])
					{
						++f[i].rev;
					}
				}
			}
		}
		
		qsort(f, m, sizeof(f[0]), cmp);
		
		for (i=0; i<m; ++i)
		{
			printf("%s\n", f[i].str);
		}
		
		if (k < TestCase - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
