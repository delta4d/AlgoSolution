#include<stdio.h>
#include<stdlib.h>

long path[100011];       /*path[i]记录第i个点从哪个点过来，记录的是排好序后的次序，并非ClubMember中的噢、position*/
long last[100011];
long invite[100011];

struct ClubMember
{
	long strength;
	long beauty;
	long position;
}member[100011];

int cmp(const void *a   ,const void *b)
{
	struct ClubMember *c = (struct ClubMember *)a;
	struct ClubMember *d = (struct ClubMember *)b;

	if(c->strength != d->strength)
	{
		return c->strength - d->strength;
	}
	else
	{
		return d->beauty - c->beauty;
	}
}

int main()
{
	long TestCase;
	long k;
	long i;
	long j;
	long n;
	long len;
	long left;
	long right;
	long mid;
	long index;

	scanf("%ld", &TestCase);

	for (k=0; k<TestCase; ++k)
	{
		scanf("%ld", &n);

		for (i=1; i<n+1; ++i)
		{
			scanf("%ld %ld", &member[i].strength, &member[i].beauty);
			
			member[i].position = i;
		}
		
		qsort(member + 1, n, sizeof(member[1]), cmp);	
		
		path[1] = 1;
		last[1] = 1;
		len = 1;
		
	/*	index = 1;*/
		
		for(i = 2;i <= n;i++)
        {
            left = 1;
			right = len;
            while(left <= right)
            {
                mid = (left + right)/2;
				
                if(member[last[mid]].beauty < member[i].beauty) 
				{	
					left = mid + 1;
				}	
                else
				{	
					right = mid - 1;
				}
				
            }
			
            last[left] = i;
			path[i] = last[left-1];
			
            if(left > len)
			{
				len++;
			}
			
		/*	if (left >= len)
			{
				index = i;
			} */
			
        }
		
		printf("%d\n",len);
		
		i = 0;
		index = last[len];
		while (len--)
		{			
			invite[i++] = member[index].position;
			index = path[index];
		}
		
	/*	invite[i] = index; */
		
		for (j=i-1; j>0; --j)
		{
			printf("%ld ", invite[j]);
		}
		
		printf("%ld\n", invite[0]);
		
		if (k < TestCase - 1)
		{
			printf("\n");
		}
		
	}
}
