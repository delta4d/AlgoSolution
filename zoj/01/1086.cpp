#include<stdio.h>
#include<memory.h>

#define MaxL 100

char orc[MaxL];
int d[MaxL];

int main(void)
{
	int i;
	int j;
	int k;
	int len;
	int x;
	
	while (scanf("%s", orc) != EOF)
	{
		len = strlen(orc);
	 	k = 1;
	 	memset(d, 0, sizeof(d));
		
		for (i=len-1; i>1; --i)
		{
			x = 0;
			d[1] = orc[i] - '0';
			
			for (j=1; ; ++j)
			{	
				x = x * 10 + d[j];
				d[j] = x / 8;
				x %= 8;
				
				if ((x == 0) && (j > k))
				{
					k = j;
					break;
				}
			}
		}

		printf("%s [8] = 0.", orc);
		for (i=2; i<=k; ++i)
		{
			printf("%d", d[i]);
		}
		printf(" [10]\n");
	}
	
	return 0;
}
