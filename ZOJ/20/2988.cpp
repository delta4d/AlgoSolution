#include<stdio.h>
int main()
{
	char metric[10];
	int t;
	int k;
	int i;
	int rank = 1;
	double ori;
	double res;
	
	scanf("%d", &t);
	
	for (k=0; k<t; k++)
	{
		scanf("%lf", &ori);
		scanf("%s", metric);
		
		if (strcmp(metric, "kg") == 0)
		{
			res = ori * 2.2046 ;
			
			printf("%d %.4lf lb\n", rank, res);
			
			rank++;
		}
		else if (strcmp(metric, "lb") == 0)
		{
			res = ori * 0.4536;
			
			printf("%d %.4lf kg\n", rank, res);
			
			rank++;
		}
        else if (strcmp(metric, "l") == 0)
		{
			res = ori * 0.2642;
			
			printf("%d %.4lf g\n", rank, res);
			
			rank++;
		}	
        else
		{
			res = ori * 3.7854;
			
			printf("%d %.4lf l\n", rank, res);
			
			rank++;
		}				
	}
}