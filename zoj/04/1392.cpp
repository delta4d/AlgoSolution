#include<stdio.h>

int isup(char ch)
{
	if ((ch <= 'Z') && (ch >= 'A'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char convert(char ch)
{
	ch = (ch - 'A' + 21) % 26 + 'A';
	
	return ch;
}

int main(void)
{
	char message[201];
	int i;
	int j;
	int len;
	
	gets(message);
	
	while (strcmp(message, "ENDOFINPUT") != 0)
	{
		while (strcmp(message, "END") != 0)
		{
			if (strcmp(message, "START") != 0)
			{
				len = strlen(message);
			
				for (i=0; i<len; ++i)
				{
					if (isup(message[i]))
					{
						message[i] = convert(message[i]);
					}
				}
											
				puts(message);			
			}

			gets(message);
		}
		
		gets(message);
	}

	return 0;
}
