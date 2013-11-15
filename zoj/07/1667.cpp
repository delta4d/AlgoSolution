#include<stdio.h>
#include<memory.h>

int main(void)
{
	char x[7];
	char temp[7];
	char order[6];
	int n;
	int i;
	int j;	

	scanf("%d", &n);

	while (n != 0)
	{
		for (i=0; i<7; ++i)
		{
			x[i] = i;
		}
		
		for (i=0; i<n; ++i)
		{
			scanf("%s", order);
			
			if (strcmp(order, "north") == 0)
			{
				temp[1] = x[5];
				temp[2] = x[1];
				temp[3] = x[3];
				temp[4] = x[4];
				temp[5] = x[6];
				temp[6] = x[2];
			}
			else if (strcmp(order, "south") == 0)
			{
				temp[1] = x[2];
				temp[2] = x[6];
				temp[3] = x[3];
				temp[4] = x[4];
				temp[5] = x[1];
				temp[6] = x[5];
			}
			else if (strcmp(order, "west") == 0)
			{
				temp[1] = x[4];
				temp[2] = x[2];
				temp[3] = x[1];
				temp[4] = x[6];
				temp[5] = x[5];
				temp[6] = x[3];
			}
			else	
			{
				temp[1] = x[3];
				temp[2] = x[2];
				temp[3] = x[6];
				temp[4] = x[1];
				temp[5] = x[5];
				temp[6] = x[4];
			}					
							
			for (j=1; j<7; ++j)
			{
				x[j] = temp[j];
			}
		}
		
		printf("%d\n", x[1]);
		
		scanf("%d", &n);
	}

	return 0;
}
