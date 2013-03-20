#include<stdio.h>
#include<stdlib.h>

double f[15];

int cmp(const void *a, const void *b)
{
	if (*(double *)a < *(double *)b)
	{
		return 1;
	}
	
	return -1;
}

int main(void)
{
	char ch;
	char temp[10];
	int i;
	int j;
	int k;
	
	while ((ch = getchar()) != -1)
	{
		k = 0;
		
		while (ch != '\n')
		{
			scanf("%lf", f + k);
			scanf("%s", temp);
			
			ch = getchar();
			if (ch == '\n')
			{
				break;
			}
			ch = getchar();
			++k;
		}
		
		qsort(f+2, k-2, sizeof(f[2]), cmp);
		
		if (f[0] <= 0 || f[0] == f[2] || (f[0] == f[2]) && (f[0] == f[3]))
		{
			printf("PlayOn\n");
		}		
		else if ((f[0] > f[1]) && (f[0] > f[3]))
		{
			printf("Offside\n");
		}
		else
		{
			printf("PlayOn\n");
		}
	}
	
	return 0;
}
