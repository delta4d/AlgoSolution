#include<stdio.h>

char word[30];

int belong(int i)
{
	if (word[i] == 'B' || word[i] == 'F' || word[i] == 'P' || word[i] == 'V')
	{
		return 1;
	}
	else if (word[i] == 'C' || word[i] == 'G' || word[i] == 'J'|| word[i] == 'K' 
	|| word[i] == 'Q' || word[i] == 'S' || word[i] == 'X' || word[i] ==  'Z')
	{
		return 2;
	}
	else if (word[i] == 'D' || word[i] == 'T')
	{
		return 3;
	}
	else if (word[i] == 'L')
	{
		return 4;
	}
	else if (word[i] == 'M' || word[i] == 'N')
	{
		return 5;
	}
	else if (word[i] == 'R')
	{
		return 6;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int i;
	int k;
	int len;
	int pre;
	
	while (scanf("%s", word) != EOF)
	{
		len = strlen(word);
		pre = -1;
		
		for (i=0; i<len; ++i)
		{
			if (belong(i) == 0)
			{
				pre = 0;
			}
			else if (belong(i) != pre)
			{
				printf("%d", belong(i));
				pre = belong(i);
			}
		}
		
		printf("\n");
	}

	return 0;
}
