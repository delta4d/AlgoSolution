#include<stdio.h>

int main(void)
{
    long k;
    long n;
    long T;

    scanf("%ld", &T);

    for (k=0; k<T; ++k)
    {
        scanf("%ld", &n);

		if(n==1)

                     printf("7\n");

              else if(n==2)

                     printf("27\n");

              else if(n<=10)

                     printf("70\n");

              else if(n<=11)

                     printf("270\n");

              else if(n<=100)

                     printf("700\n");

              else if(n<=101)

                     printf("2700\n");

              else if(n<=1000)

                     printf("7000\n");

              else if(n<=1002)

                     printf("26999\n");

              else if(n<=10000)

                     printf("70000\n");

              else if(n<=10001)

                     printf("270000\n");

              else if(n<=100000)

                     printf("700000\n");

              else if(n<=100001)

                     printf("1699999\n");

              else if(n<=1000000)

                     printf("7000000\n");

              else if(n<=1000001)

                     printf("27000000\n");

              else if(n<=10000000)

                     printf("70000000\n");

              else if(n<=10000001)

                     printf("270000000\n");

              else

                     printf("700000000\n");
    }

    return 0;
}
