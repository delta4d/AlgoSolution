#include<stdio.h>

#define MaxN 81

char f[MaxN];

int main(void)
{
	int len;
	int i;
	int j;
	int sum;
	int res;
	int p;
	
	scanf("%s", f);
	
	while (strcmp(f, "#") != 0)
	{
		len = strlen(f);
		sum = 0;
		
		for (i=0; i<len; ++i)
		{
			p = 0;
			
			if (f[i] == '.')
			{
				p = 100;
			}
			else if (f[i] == '_')
			{
				p = 0;
			}
			else if (f[i] == '\\')
			{
				for (j=i+1; j<len; ++j)
				{
					if (f[j] == '.')
					{
						p = 100;
						break;
					}
					else if (f[j] == '|' || f[j] == '/')
					{
						p = 0;
						break;
					}					
				}
				
				if (j == len)
				{
					p = 100;
				}
			}
			else if (f[i] == '/')
			{
				for (j=i-1; j>=0; --j)
				{
					if (f[j] == '.')
					{
						p = 100;
						break;
					}
					else if (f[j] == '|' || f[j] == '\\')
					{
						p = 0;
						break;
					}
				}
				
				if (j == -1)
				{
					p = 100;
				}
			}
			else
			{
				for (j=i+1; j<len; ++j)
				{
					if (f[j] == '.')
					{
						p = 100;
						break;
					}
					else if (f[j] == '|' || f[j] == '/')
					{
						p = 0;
						break;
					}
				}
				
				if (j == len)
				{
					p = 100;
				}
				
				p /= 2;
				
				for (j=i-1; j>=0; --j)
				{
					if (f[j] == '.')
					{
						p += 50;
						break;
					}
					else if (f[j] == '|' || f[j] == '\\')
					{
						break;
					}
				}
				
				if (j == -1)
				{
					p += 50;
				}
			}
			
			sum += p;
		}
		
		printf("%d\n", sum/len);
		
		scanf("%s", f);
	}
	
	return 0;
}
