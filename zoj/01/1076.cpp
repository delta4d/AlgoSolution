#include<stdio.h>
#include<stdlib.h>

long path[1111];
long last[1111];
long lastmark[1111];
long invite[1111];

struct Exon
{
	long start;
	long end;
	long position;
}exons[1111];

int cmp(const void * a, const void * b)
{
	struct Exon * c = (struct Exon *) a;
	struct Exon * d = (struct Exon *) b;

	return c -> start - d -> start;
}

int main()
{
	long n;
	long left;
	long right;
	long mid;
	long j;
	long i;
	long index;
	long len;

	scanf("%ld", &n);

	while (n != 0)
	{
		for (i=1; i<n+1; ++i)
		{
			scanf("%ld %ld", &exons[i].start, &exons[i].end);

			exons[i].position = i;
		}
		
		qsort(exons+1, n, sizeof(exons[1]), cmp);
		
		left = 1;
		len = 1;
		last[1] = exons[1].end;
		right = len;
		mid = (left + right) / 2;
		path[1] = 0;
		index = 1;
		lastmark[1] = 1;
		
		for (i=2; i<n+1; ++i)
		{
			left = 1;
			right = len;
			mid = (left + right) / 2;
			
			while (left <= right)
			{
				if (last[mid] < exons[i].start)
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
				index = i;
				last[left] = exons[i].end;
				lastmark[left] = i;
			}
			else
			{
				if (last[left] > exons[i].end)
				{
					last[left] = exons[i].end;
					lastmark[left] = i;
				}
			}
			
			path[i] = lastmark[left - 1];
			
		}
		
		i = 0;
		
		while (len--)
		{			
			invite[i++] = exons[index].position;
			index = path[index];
		}
		
		for (j=i-1; j>0; --j)
		{
			printf("%ld ", invite[j]);
		}
		
		printf("%ld\n", invite[0]);
		
		scanf("%ld", &n);
	}
	
	
	return 0;
}