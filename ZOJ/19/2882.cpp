#include<stdio.h>
#include<stdlib.h>

int last[20001];

struct Doll
{
	int width;
	int height;
}dolls[20001];

int cmp(const void * a, const void * b)
{
	struct Doll * c = (struct Doll *) a;
	struct Doll * d = (struct Doll *) b;
	
	if (c -> width != d -> width)
	{
		return d -> width - c -> width;
	}
	else
	{
		return c -> height - d -> height;
	}
}

int main(void)
{
	int TestCase;
	int k;
	int i;
	int left;
	int right;
	int mid;
	int len;
	int n;
	
	scanf("%d", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%d", &n);
		
		for (i=1; i<n+1; ++i)
		{
			scanf("%d %d", &dolls[i].width, &dolls[i].height);
		}
		
		qsort(dolls + 1, n, sizeof(dolls[1]), cmp);
		
		last[1] = dolls[1].height;
		left = 1;
		len =1;
		right = 1;
		
		for (i=2; i<n+1; ++i)
		{
			left = 1;
			right = len;
			mid = (left + right) / 2;
			
			while (left <= right)
			{
				if (last[mid] <= dolls[i].height)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
				
				mid = (left + right) / 2;
			}
			
			if (left > len)
			{
				++len;
			}
			
			last[left] = dolls[i].height;
		}
		
		printf("%d\n", len);
	}
	
	return 0;
}