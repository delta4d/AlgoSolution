#include<stdio.h>

char message[10000];
long f[10000];

int main(void)
{
    long n;
    long i;
    long len;

    scanf("%s", message);

    while (strcmp(message, "0") != 0)
    {
        len = strlen(message);

        f[0] = 1;
        if (message[1] == '0')
        {
        	f[1] = 1;
		}
        else if ((message[0] == '2') && (message[1] <= '6') || message[0] == '1')
        {
            f[1] = 2;
        }
        else
        {
            f[1] = 1;
        }

        for (i=2; i<len; ++i)
        {
        	if (message[i] == '0')
        	{
        		f[i] = f[i-2];
			}
            else if ((message[i-1] == '2') && (message[i] <= '6') || message[i-1] == '1')
            {
                f[i] = f[i-1] + f[i-2];
            }
            else
            {
            	f[i] = f[i-1];
			}
        }
        
        printf("%ld\n", f[len-1]);
        
        scanf("%s", message);
    }

    return 0;
}
