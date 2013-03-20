#include<stdio.h>
int main()
{
	int t;
	int i;
	int k;
	int n;
	int temp;
	int min;
	int max;
	char a[10];
	
	scanf("%d", &t);
	
	for (k=0; k<t; k++)
	{
		scanf("%s", a);
		scanf("%d", &n);
		
		if (strcmp(a, "Faster") == 0)
		{
			scanf("%d", &min);
			
			for (i=0; i<n-1; i++)
			{
				scanf("%d", &temp);
				
				if (min > temp)
				{
					min = temp;
				}
			}
			
			printf("%d\n", min);
		}
		else
		{
			scanf("%d", &max);
			
			for (i=0; i<n-1; i++)
			{
				scanf("%d", &temp);
				
				if (max < temp)
			    {
					max = temp;
				}
			}
			
			printf("%d\n", max);
		}
		
	}
}