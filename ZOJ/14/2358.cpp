#include<stdio.h>

#define MaxN 10
long fact[MaxN];

void gen_fact(void)
{
    long i;
    fact[0] = 1;

    for (i=1; i<MaxN; ++i)
    {
        fact[i] = fact[i-1] * i;
    }

    return;
}

int main(void)
{
	int i;
	long n;
    gen_fact();

    scanf("%ld", &n);

    while (n >= 0)
    {
        if (n == 0)
        {
        	printf("NO\n");
		}
		else
		{
			for (i=MaxN-1; i>=0; --i)
			{
				if (n == 0)
				{
					break;
				}
				
				if (n >= fact[i])
				{
					n -= fact[i];
				}
			}
			
			if (n != 0)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
		}

        scanf("%ld", &n);
    }

    return 0;
}
