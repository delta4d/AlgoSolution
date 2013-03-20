#include<stdio.h>
#include<stdlib.h>

long a[10011],last[10011];

struct WoodStick
{
	long length;
	long weight;
}sticks[10011];

int cmp(const void *a   ,const void *b)
{
	struct WoodStick *c = (struct WoodStick *)a;
	struct WoodStick *d = (struct WoodStick *)b;

	if(c->length != d->length)
	{
		return d->length - c->length;
	}
	else
	{
		return d->weight - c->weight;
	}
}

int main()
{
	long testcase;
	long k;
	long i;
	long j;
	long n;
	long m, len;
	long left, mid, right;
	
	
	scanf("%ld", &testcase);
	
	for (k=0; k<testcase; ++k)
	{
		scanf("%ld", &n);
		
		for (i=0; i<n; ++i)
		{
			scanf("%ld %ld", &sticks[i].length, &sticks[i].weight);
		}
		
	    qsort(sticks, n, sizeof(sticks[0]), cmp);
		
		for (i=0; i<n; i++)
		{
			a[i+1] = sticks[i].weight;
		}
		
		last[1] = a[1];
		len = 1;
		
		for(i = 2;i <= n;i++)
        {
            left = 1;
			right = len;
            while(left <= right)
            {
                mid = (left + right)/2;
				
                if(last[mid] < a[i]) 
					left = mid + 1;
                else
					right = mid - 1;
            }
			
            last[left] = a[i];
			
            if(left > len) 
				len++;
        }
			
		printf("%d\n",len);
		
	}

}