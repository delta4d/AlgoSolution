#include<stdio.h>
#include<math.h>

int prime(long long n)
{
    int i;
    int flag = 1;

    for (i=2; i*i<=n; ++i)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main(void)
{
    long long i;
    long long j;
    long long k;
    long long n;
    FILE *fp = fopen("f:\\merson.txt", "w");

    for (i=11; i<64; ++i)
    {
        if (prime(i))
        {
            n = (long long)pow(2, i) - 1;

            fprintf(fp, "%lld: %lld = ", i, n);

            for (j=2; j*j<=n; ++j)
            {
            	if (n % j == 0)
            	{
            		while (n % j == 0)
            		{
            			fprintf(fp, "%lld ", j);
            			n /= j;
					}
				}
			}
			
			if (n != 1)
			{
				fprintf(fp, "%lld", n);
			}
			
			fprintf(fp, "\n");
		}
    }

    return 0;
}
