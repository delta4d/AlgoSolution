#include<stdio.h>

int convert_judge(int base, int n)
{
    char num[20];
    int i, j;
    int flag = 1;

    if (base <= 10)
      {
          i = 1;

          while (n != 0)
            {
                num[i] = n % base + '0';
                n /= base;
                i++;
            }
      }
    else
      {
          i = 1;

          while (n != 0)
            {
                if (n % base >= 10)
                  {
                      num[i] = n % base - 10 + 'A';
                      n /= base;
                      i++;
                  }
                else
                  {
                      num[i] = n % base;
                      n /= base;
                      i++;
                  }
            }
      }

   i--;


   for (j=1; j<=i/2; j++)
    {
	if (num[j] != num[i+1-j])
            {
                flag = 0;
                break;
            }
    }

   return flag;

}

int main()
{
    int base[17];
    int i;
    int n;
    int flag;

    scanf("%d", &n);

    while (n != 0)
     {
         flag = 0;

         for (i=2; i<=16; i++)
           {
               base[i] = 0;
           }

         for (i=2; i<=16; i++)
           {
               if (convert_judge(i, n) == 1)
                 {
                     base[i] = 1;
                     flag = 1;
                 }
           }

         if (flag == 0)
           {
               printf("Number %d is not a palindrom\n", n);
           }
         else
           {
               printf("Number %d is palindrom in basis",n);

               for (i=2; i<=16; i++)
                {
                    if (base[i] == 1)
                     {
                         printf(" %d", i);
                     }
                }

               printf("\n");
           }

         scanf("%d", &n);
     }
}

