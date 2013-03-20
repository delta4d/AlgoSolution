#include<stdio.h>

int main(void)
{
	char word[100];
	int i;
	int k;
	int len;
	int newline = 0;
	
	while (scanf("%s", word) != EOF)
	{
		if (strcmp(word, "<br>") == 0)
		{
			printf("\n");
			newline = 0;
		}
		else if (strcmp(word, "<hr>") == 0)
		{
			if (newline != 0)
			{
				printf("\n");
				newline = 0;
			}
			
			for (i=0; i<80; ++i)
			{
				printf("-");
			}
			
			printf("\n");
			newline = 0;
		}
		else
		{
			len = strlen(word);
			
			if (len > 79 - newline)
			{
				printf("\n");
				newline = 0;
			}
			else
			{
				if (newline != 0)
				{
					printf(" ");
					++newline;
				}
			}
			
			for (i=0; i<len; ++i)
			{
				if (newline == 80)
				{
					printf("\n");
					newline = 0;
					printf("%c", word[i]);
				}
				else
				{
					++newline;
					printf("%c", word[i]);
				}
			}
			
			if (newline == 80)
			{
				newline = 0;
				printf("\n");
			}
		}
		
	}
	
	printf("\n");
	
	return 0;
}