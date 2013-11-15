#include<stdio.h>

char code[4000];

int main()
{
	int n;
	int i;
	int k;
	int len;
	int tab;
	int space;
	
	scanf("%d", &n);
	
	for (k=0; k<n; k++)
	{
		tab = space = 0;
		
		while (gets(code) && (strcmp(code, "##") != 0))
		{
			len = strlen(code);
			
			for (i=0; i<len; i++)
			{
				if (code[i] == '\t')
				{
					tab++;
				}
			}
			
			for (i=len-1; i>=0; i--)
			{
				if (code[i] == ' ')
				{
					space++;
				}
				else if(code[i] == '\t')
				{
					space += 4;
				}
				else
				{
					break;
				}
				
			}
		}
		
		printf("%d tab(s) replaced\n%d trailing space(s) removed\n", tab, space);
	}
}