#include<stdio.h>

char message[100];

long isvowel(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int i;
	int len;
	int flag1;
	int flag2;
	int flag3;
	
	scanf("%s", message);
	
	while (strcmp(message, "end") != 0)
	{
		len = strlen(message);
		
		flag1 = 0;
		flag2 = 1;
		flag3 = 1;
		
		for (i=0; i<len; ++i)
		{
			if (isvowel(message[i]))
			{
				flag1 = 1;
			}
			
			if (i + 2 < len)
			{
				if (isvowel(message[i]) && isvowel(message[i+1]) && isvowel(message[i+2]) || 
				    !isvowel(message[i]) && !isvowel(message[i+1]) && !isvowel(message[i+2]))
				{
					flag2 = 0;
					break;
				}
			}
			
			if (i + 1 < len)
			{
				if ((message[i] == message[i+1]) && (message[i] != 'e') && (message[i] != 'o'))
				{
					flag3 = 0;
					break;
				}		
			}
		}
		
		if ((flag1 == 1) && (flag2 == 1) && (flag3 == 1))
		{
			printf("<%s> is acceptable.\n", message);
		}
		else
		{
			printf("<%s> is not acceptable.\n", message);
		}
		
		scanf("%s", message);
	}

	return 0;
}
