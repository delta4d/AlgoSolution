#include<stdio.h>

int isHumbleNumber(long n)
{
    int res = 1;
    
    while (n % 2 == 0)
     {
          n /= 2;
     }
    while (n % 3 == 0)
     {
          n /= 3;
     }     
    while (n % 5 == 0)
     {
          n /= 5;
     }
    while (n % 7 == 0)
     {
          n /= 7;
     }          
     
    if (n > 1)
      {
          res = 0;
      } 
      
    return res;  
}

int main()
{
    long n;
    long i;
    long rank;
    long order;
    
    scanf("%ld", &n);
    
    while (n != 0)
      {
          rank = 0;
          
          for (i=1; rank<n; i++)
            {
                    if (isHumbleNumber(i))
                      {
                           rank++;               
                      }
            }
            
          order = n % 10;
          
          if (order == 1)  
            {
                  printf("The %ldst humble number is %ld.\n", n, i-1);  
            }
          else if (order == 2)  
            {
                  printf("The %ldnd humble number is %ld.\n", n, i-1);  
            }   
          else if (order == 3)  
            {
                  printf("The %ldrd humble number is %ld.\n", n, i-1);  
            }
          else  
            {
                  printf("The %ldth humble number is %ld.\n", n, i-1);  
            }                                 
          
          scanf("%ld", &n);  
      }
}
