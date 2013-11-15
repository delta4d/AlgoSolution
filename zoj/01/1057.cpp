#include<stdio.h>

int main()
{
    int a[30];
    int b[30];
    int n;
    int i;
    int scoreA;
    int scoreB;
    
    scanf("%d", &n);
    
    while (n != 0)
      {
          scoreA = scoreB = 0;
          
          for (i=0; i<n; i++)
            {
                    scanf("%d", a+i);
            }
          for (i=0; i<n; i++)
            {
                    scanf("%d", b+i);
            }  
            
          for (i=0; i<n; i++)
            {
                    if (a[i] > b[i])
                      {
                             if (a[i] - b[i] == 1)
                             {
                                      if (b[i] != 1)
                                        {
                                               scoreB += a[i] +b[i];
                                        }
                                      else
                                        {
                                               scoreB += 6;
                                        }  
                             }
                             else
                             {
                                      scoreA += a[i];
                             }
                      }
                    else if (a[i] < b[i])
                      {
                            if (b[i] - a[i] == 1)
                            {
                                     if (a[i] != 1)
                                       {
                                              scoreA += a[i]+b[i];
                                       }
                                     else
                                       {
                                              scoreA += 6;
                                       }  
                            }
                            else
                            {
                                     scoreB += b[i];
                            }
                      }  
                      
            } 
            
          printf("A has %d points. B has %d points.\n", scoreA, scoreB);
          
          scanf("%d", &n);  
          
          if (n != 0)
            {
                printf("\n");
            } 
            
      }
    
}
