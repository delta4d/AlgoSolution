#include<stdio.h>
#include<memory.h>

int main(void)
{
	int m[10][10];
	int a[101];
	int n;
	int i;
	int j;
	int k;
	int t;
	int in;
	int sum;
	int temp;
	int flag;
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		flag = 1;
		k = 0;
		
		for (i=0; i<n; ++i)
		{
			for (j=0; j<n; ++j)
			{
				scanf("%d", &m[i][j]);
				
				if (k == 0)
				{
					a[k] = m[i][j];
					++k;
				}
				else
				{
					in = 0;
					
					for (t=0; t<k; ++t)
					{
						if (a[t] == m[i][j])
						{
							in = 1;
							flag = 0;
							break;
						}						
					}
					
					if (in == 0)
					{
						a[k] = m[i][j];
						++k;
					}
				}
			}
		}
		
		sum = 0;
		
		for (i=0; i<n; ++i)
		{
			sum += m[0][i];
		}
		
		for (i=1; i<n; ++i)
		{
			temp = 0;
			
			for (j=0; j<n; ++j)
			{
				temp += m[i][j];
			}
			
			if (temp != sum)
			{
				flag = 0;
				break;
			}
		}
		
		for (i=0; i<n; ++i)
		{
			temp = 0;
			
			for (j=0; j<n; ++j)
			{
				temp += m[j][i];
			}
			
			if (temp != sum)
			{
				flag = 0;
				break;
			}
		}
		
		temp = 0;
		
		for (i=0; i<n; ++i)
		{
			temp += m[i][i];
		}
		
		if (temp != sum)
		{
			flag = 0;
		}
		
		temp = 0;
		
		for (i=0; i<n; ++i)
		{
			temp += m[i][n-1-i];
		}
		
		if (temp != sum)
		{
			flag = 0;
		}
		
		if (flag == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		
		scanf("%d", &n);
	}
	
	return 0;
}
