#include<stdio.h>

int num[3001];

int main()
{
	int n;
	int i;
	long a1;
	long a2;
	int flag;
	
    while (scanf("%ld", &n) != EOF)
	{
		for (i=1; i<=n-1; i++)
		{
			num[i] = 0;
		}
		
		if (n == 1)
		{
			printf("Jolly\n");
			scanf("%ld", &a1);
		}
		else
		{
		    scanf("%ld %ld", &a1, &a2);
		
		    if ((a1 < a2) && (a2 - a1) <= 3001)
		    {
			    num[a2 - a1] = 1;
		    }
		    else if ((a2 < a1) && (a1 - a2) <= 3001)
		    {
			    num[a1 -a2] = 1;
		    }
		
		    for (i=1; i<=n-2; i++)
		    {
			    a1 = a2;
			    scanf("%ld", &a2);
			    if ((a1 < a2) && (a2 - a1) <= 3001)
			    {
			       num[a2 - a1] = 1;
			    }
			    else if ((a2 < a1) && (a1 - a2) <= 3001)
			    {
				    num[a1 -a2] = 1;
				}
			}
		
	    	flag = 1;
		
		    for (i=1; i<n; i++)
		    {
			   if (num[i] == 0)
			   {
				   flag = 0;
				   break;
			   }
		    }
		
		    if (flag == 1)
		    {
			   printf("Jolly\n");
		    }
		    else
		    {
			    printf("Not jolly\n");
		    }
		}
	}
	
}