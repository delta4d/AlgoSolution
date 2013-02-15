#include<stdio.h>

int orign[9][9];

int main(void)
{
	char s[10];
	int r;
	int c;
	int i;
	int j;
	int t;
	
	scanf("%s", s);
	
	while (strcmp(s, "ENDOFINPUT") != 0)
	{
		scanf("%d %d", &r, &c);
		
		while (strcmp(s, "END") != 0)
		{
			for (i=0; i<r; ++i)
			{
				scanf("%s", s);
				
				for (j=0; j<c; ++j)
				{
					orign[i][j] = s[j] - '0';
				}
			}
			
			scanf("%s", s);
		}
		
		for (i=0; i<r-1; ++i)
		{
			for (j=0; j<c-1; ++j)
			{
				t = (orign[i][j] + orign[i][j+1] + orign[i+1][j] + orign[i+1][j+1]) / 4;
				
				printf("%d", t);
			}
			
			printf("\n");
		}
		
		scanf("%s", s);
	}
	
	return 0;
}
