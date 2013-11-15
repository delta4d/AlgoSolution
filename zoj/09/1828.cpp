#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

struct BigNum
{
	int num[1010];
	int len;
}f[2];

struct BigNum * Add(struct BigNum * a, struct BigNum * b)
{
	int len;
	int i;
	struct BigNum * c;

	c = (struct BigNum *)malloc(sizeof(struct BigNum));
	memset(c -> num, 0, sizeof(c -> num));
	len = a -> len > b -> len ? a -> len : b -> len;

	for (i=0; i<len; ++i)
	{
    	c -> num[i] += (a -> num[i] + b -> num[i]);
  
    	if (c -> num[i] > 9)
		{
    		++(c -> num[i+1]);
    		c -> num[i] -= 10;
   		}
	} 

	if (c -> num[len] != 0)
	{
   		++len;
	}

	c -> len = len;

	return c;
}

int main(void)
{
	int n;
	int i;
	int k;
	struct BigNum * c;
	
	c = (struct BigNum *)malloc(sizeof(struct BigNum));	
	
	while (scanf("%d", &n) != EOF)
	{
		for (i=0; i<2; ++i)
		{
			memset(f[i].num, 0, 1010*sizeof(int));
		}
		
		f[0].num[0] = 1;
		f[1].num[0] = 1;
		f[0].len = 1;
		f[1].len = 1;
		
		for (i=3; i<=n; ++i)
		{
			c = Add(&f[0], &f[1]);
		
			for (k=0; k<f[1].len; ++k)
			{
				f[0].num[k] = f[1].num[k];
				f[0].len = f[1].len;
			}
		
			for (k=0; k<c->len; ++k)
			{
				f[1].num[k] = c -> num[k];
				f[1].len = c -> len;
			}
		}
		
		for (i=f[1].len-1; i>-1; --i)
		{
			printf("%d", f[1].num[i]);
		}
		
		printf("\n");
	}
	
	return 0;
}
