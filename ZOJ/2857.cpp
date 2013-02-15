#include<stdio.h>

int res[100][100];

int main()
{
	int m;
	int n;
	int i;
	int j;
	int k;
	int temp;
	int rank = 1;
	
	scanf("%d %d", &m, &n);
	
	while ((m != 0) || (n != 0))
	{
		for (i=0; i<100; i++)
		{
			for (j=0; j<100; j++)
			{
				res[i][j] = 0;
			}
		}
		
		for (k=0; k<3; k++)
		{
		    for (i=0; i<m; i++)
		    {
			    for (j=0; j<n; j++)
			    {
				    scanf("%d", &temp);
				
				    res[i][j] += temp;
			    }
		    }
		}
		
		printf("Case %d:\n", rank);
		for (i=0; i<m; i++)
		{
			for (j=0; j<n-1; j++)
			{
				printf ("%d,", res[i][j] / 3);				
			}
			printf ("%d\n", res[i][n-1]/3);
		}
		
		rank++;
		
		scanf("%d %d", &m, &n);
	}
}