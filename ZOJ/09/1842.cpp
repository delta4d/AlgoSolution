#include<cstdio>
#include<cmath>

long long prime[4852];
long long isprime[1000010];

void gen_prime()
{
    long long i;
    long long k;
    long long flag;
    long long order = 1;

    for (k=3; k<=47000; ++k)
    {
        flag = 1;

        for (i=0; prime[i]*prime[i]<=k; ++i)
        {
            if (k % prime[i] == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            prime[order] = k;
            ++order;
        }
    }
}

void sieve(long long L, long long U)
{
    long long i;
    long long j;
    long long k;

    for (i=0; i<U-L+1; ++i)
    {
        isprime[i] = 1;
    }
    
    if (L == 1)
    {
    	isprime[0] = 0;
	}

    for (i=0; prime[i]*prime[i]<=U; ++i)
    {
        if (L == prime[i])
        {
        	j = 2;
		}
		else
		{
			j = L / prime[i];
			
			if (L % prime[i] != 0)
			{
				++j;
			}
			
			if (j == 1)
			{
				++j;
			}
		}

        for (k=j*prime[i]; k<=U; k+=prime[i])
        {
            isprime[k-L] = 0;
        }
    }

}

int main(void)
{
    long long i;
    long long j;
    long long L;
    long long U;
    long long C1;
    long long C2;
    long long D1;
    long long D2;
    long long n;
    long long pre;
    long long index;

    prime[0] = 2;
    gen_prime();

    while (scanf("%lld %lld", &L, &U) != EOF)
    {
    	sieve(L, U);
    	
        D1 = D2 = C1 = C2 = -1;

        for (i=L; i<=U; ++i)
        {
            if (isprime[i-L] == 1)
            {
                C1 = D1 = i;
                index = i+1;
                break;
            }
        }

        if (C1 != -1)
        {
            for (i=index; i<=U; ++i)
            {
                if (isprime[i-L] == 1)
                {
                    if (D2 == -1)
                    {
                        D2 = C2 = i;
                    }

                    else
                    {
                        if (C2 - C1 > i - pre)
                        {
                            C2 = i;
                            C1 = pre;
                        }

                        if (D2 - D1 < i - pre)
                        {
                            D2 = i;
                            D1 = pre;
                        }
                    }
                    
                    pre = i;
                }
            }
        }

        if (D1 == -1 || D2 == -1)
        {
            printf("There are no adjacent primes.\n");
        }
        else
        {
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", C1, C2, D1, D2);
        }
    }

    return 0;
}
