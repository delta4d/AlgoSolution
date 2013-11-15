#include<stdio.h>
#include<stdlib.h>

struct ele
{
	int position;
	double sa;
}a[1000];

int cmp1(const void *a, const void *b)
{
	struct ele * c = (struct ele *)a;
	struct ele * d = (struct ele *)b;
	
	if (c -> sa < d -> sa)
	{
		return 1;
	}
	else if (c -> sa > d -> sa)
	{
		return -1;
	}
	else
	{
		return c -> position - d -> position;
	}
}

int cmp2(const void *a, const void *b)
{
	struct ele * c = (struct ele *)a;
	struct ele * d = (struct ele *)b;
	
	return d -> position - c -> position;
}

int main(void)
{
	int n;
	int m;
	int k;
	int i;
	int j;
	double temp;
	
	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		for (i=1; i<=m; ++i)
		{
			a[i].position = i;
			a[i].sa = 0;
		}
		
		for (i=0; i<n; ++i)
		{
			for (j=1; j<=m; ++j)
			{
				scanf("%lf", &temp);
				
				a[j].sa += temp;
			}
		}
		
		if (k != m)
		{
			qsort(a+1, m, sizeof(a[0]), cmp1);
			qsort(a+1, k, sizeof(a[0]), cmp2);
		
			for (i=1; i<k; ++i)
			{
				printf("%d ", a[i].position);
			}
		
			printf("%d\n", a[k].position);
		}
		else
		{
			for (i=k; i>1; --i)
			{
				printf("%d ", i);
			}
			
			printf("1\n");
		}
	}

	return 0;
}
