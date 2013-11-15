#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct BigNum
{
	int num[100];
	int len;
}f[101];

struct BigNum * Add(struct BigNum * a, struct BigNum * b)
{
	struct BigNum * c;
	long i;
	long len;
	long k;

	c = (struct BigNum *)malloc(sizeof(struct BigNum));

	len = a->len > b->len ? a->len : b->len;
	memset(c->num, 0, sizeof(c->num));

	for (i=0; i<len; ++i)
	{
		c->num[i] += (a->num[i] + b->num[i]);

		if (c->num[i] > 9)
		{
			++(c->num[i+1]);
			c->num[i] -= 10;
		}
	}

	if (c->num[len] != 0)
	{
		++len;
	}

	c->len = len;

	return c;
}

struct BigNum * Mul(struct BigNum * a, struct BigNum * b)
{
	struct BigNum * c;
	long i;
	long j;
	long len;

	c = (struct BigNum *)malloc(sizeof(struct BigNum));
	memset(c->num, 0, sizeof(c->num));

	for (i=0; i<a->len; ++i)
	{
		for (j=0; j<b->len; ++j)
		{
			c->num[i+j] += (a->num[i] * b->num[j]);

			if (c->num[i+j] > 9)
			{
				c->num[i+j+1] += (c->num[i+j] / 10);
				c->num[i+j] %= 10;
			}
		}
	}

	len = a->len + b->len;
	
	if (c->num[len-1] == 0)
	{
		--len;
	}
	
	c->len = len;
	
	return c;
}

int main(void)
{
	long i;
	long j;
	long k;
	long n;
	struct BigNum * t;

	f[0].num[0] = 1;
	f[0].len = 1;

	for (i=1; i<101; ++i)
	{
		f[i].len = 1;
		f[i].num[0] = 0;

		for (k=0; k<i; ++k)
		{
			t = Mul(&f[k], &f[i-1-k]);
			t = Add(t, &f[i]);

			f[i].len = t->len;

			for (j=0; j<f[i].len; ++j)
			{
				f[i].num[j] = t->num[j];
			}
		}
	}

	scanf("%ld", &n);

	while (n != -1)
	{
		for (i=f[n].len-1; i>-1; --i)
		{
			printf("%d", f[n].num[i]);
		}

		printf("\n");

		scanf("%ld", &n);
	}

	return 0;
}
