#include<stdio.h>

struct Guess
{
	int num;
	int res;
}f[20];

int main(void)
{
	char temp[10];
	int i;
	int k;
	int n;
	int ishonest;
	
	scanf("%d", &n);
	getchar();
	
	while (n != 0)
	{
		gets(temp);
		i = 0;
		
		while (strcmp(temp, "right on") != 0)
		{
			f[i].num = n;
			if (strcmp(temp, "too high") == 0)
			{
				f[i].res = 1;
			}
			else
			{
				f[i].res = -1;
			}
			
			++i;
			
			scanf("%d", &n);
			getchar();
			gets(temp);
		}
		
		k = i;
		ishonest = 1;
		
		for (i=0; i<k; ++i)
		{
			if ((f[i].res == 1) && (f[i].num <= n))
			{
				ishonest = 0;
				break;
			}
			else if ((f[i].res == -1) && (f[i].num >= n))
			{
				ishonest = 0;
				break;
			}			
		}
		
		if (ishonest == 1)
		{
			printf("Stan may be honest\n");
		}
		else
		{
			printf("Stan is dishonest\n");
		}
		
		scanf("%d", &n);
		getchar();
	}
	
	return 0;
}
