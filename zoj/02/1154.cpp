#include<stdio.h>

int main(void)
{
    char num[100];
    long base;
    long sum;
    long len;
    long dec;
    long i;
    long j;
    long k;
    long TestCase;

    scanf("%ld", &TestCase);

    for (k=0; k<TestCase; ++k)
    {
        scanf("%ld", &base);

        while (base != 0)
        {
            scanf("%s", num);

            len = strlen(num);

            sum = dec = 0;

            for (i=0; i<len; ++i)
            {
                dec = dec * base + num[i] - '0';
                sum += num[i] - '0';
            }

            if (dec % sum == 0)
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }

            scanf("%ld", &base);
        }
        
        if (k < TestCase - 1)
        {
        	printf("\n");
		}
    }

    return 0;
}
