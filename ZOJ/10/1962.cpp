#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

struct BigNum
{
	int num[102];
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

int compare(struct BigNum * a, struct BigNum * b)
{
	int len;
	int i;
	int res = 0;
	
	if (a -> len != b -> len)
	{
		res = a -> len - b -> len;
	}
	else
	{
		len = a -> len;
		
		for (i=len-1; i>-1; --i)
		{
			if (a -> num[i] != b -> num[i])
			{
				res = a -> num[i] - b -> num[i];
				break;
			}
		}
	}
	
	return res;
}

int main(void)
{
	int n;
	int i;
	int k;
	int len;
	long res;
	char s[102];
	char t[102];
	struct BigNum * c;
	struct BigNum * start;
	struct BigNum * end;
	
	c = (struct BigNum *)malloc(sizeof(struct BigNum));	
	start = (struct BigNum *)malloc(sizeof(struct BigNum));
	end = (struct BigNum *)malloc(sizeof(struct BigNum));
	
	scanf("%s %s", s, t);
	
	while ((strcmp(s, "0") != 0) || (strcmp(t, "0") != 0))
	{
		memset(start->num, 0, 102*sizeof(int));
		memset(end->num, 0, 102*sizeof(int));
		
		len = strlen(s);
		start -> len = len;
		for (i=len-1; i>-1; --i)
		{
			start -> num[len-i-1] = s[i] - '0'; 
		}
		
		len = strlen(t);
		end -> len = len;
		for (i=len-1; i>-1; --i)
		{
			end -> num[len-i-1] = t[i] - '0'; 
		}
		
		for (i=0; i<2; ++i)
		{
			memset(f[i].num, 0, 102*sizeof(int));
		}
		
		f[0].num[0] = 1;
		f[1].num[0] = 1;
		f[0].len = 1;
		f[1].len = 1;
		res = 0;
		
		while (compare(&f[1], end) <= 0)
		{
			if (compare(&f[1], start) >= 0)
			{
				++res;
			}
			
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
		
		printf("%ld\n", res);
		
		scanf("%s %s", s, t);
	}
	
	return 0;
}
