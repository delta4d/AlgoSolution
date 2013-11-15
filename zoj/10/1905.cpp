#include<stdio.h>

#define MaxN 1000001

char s[MaxN];

int main(void)
{
    long i;
    long j;
    long k;
    long n;
    long len;
    long flag;

	scanf("%s", s);

    while (strcmp(s, ".") != 0)
    {
        len = strlen(s);

        for (k=1; k<len; ++k)
        {
            if (len % k == 0)
            {
                flag = 1;

                for (i=k; i<len; i+=k)
                {
                    for (j=i; j<i+k; ++j)
                    {
                        if (s[j] != s[j-i])
                        {
                            flag = 0;
                            break;
                        }
                    }

                    if (flag == 0)
                    {
                        break;
                    }
                }
            }

            if (flag == 1)
            {
                break;
            }
        }
        
        printf("%ld\n", len / k);
        
        scanf("%s", s);
    }
    
    return 0;
}
