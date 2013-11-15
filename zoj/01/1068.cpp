#include<stdio.h>

int main()
{
	char key[30][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
	".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
	"..-", "...-", ".--", "-..-", "-.--", "--..", "..--", ".-.-", "---.", "----"};
	
	char message[101];
	char temp[500];
	char code[5];
	char * p;
	long testcase;
	long i;
	long j;
	long k;
	long len;
	long order = 1;
	long keylen;
	long encyp[101];
	
	scanf("%ld", &testcase);
	
	for (k=0; k<testcase; k++)
	{
		scanf("%s", message);
		
		len = strlen(message);
		p = temp;
		
		for (i=0; i<len; i++)
		{
			if ((message[i] <= 'Z') && (message[i] >= 'A'))
			{
				keylen = strlen(key[message[i] - 'A']);
				strcpy(p, key[message[i] - 'A']);
				p = p + keylen;
			}
			else if (message[i] == '_')
			{
				keylen = strlen(key[26]);
				strcpy(p, key[26]);
				p = p + keylen;
			}
			else if (message[i] == ',')
			{
				keylen = strlen(key[27]);
				strcpy(p, key[27]);
				p = p + keylen;
			}
			else if (message[i] == '.')
			{
				keylen = strlen(key[28]);
				strcpy(p, key[28]);
				p = p + keylen;
			}
			else
			{
				keylen = strlen(key[29]);
				strcpy(p, key[29]);
				p = p + keylen;
			}
			
			encyp[i] = keylen;
		}
		
		p = temp;
		
		printf("%ld: ", order);
		
		for (i=len-1; i>=0; i--)
		{
			for (j=0; j<encyp[i]; j++)
			{
				code[j] = p[j];
			}
			p += encyp[i];

			code[j] = '\0';

			for (j=0; j<30; j++)
			{
				if (strcmp(code, key[j]) == 0)
				{
					if (j<26)
					{
						printf("%c", j + 'A');
					}
					else if (j == 26)
					{
						printf("_");
					}
					else if (j == 27)
					{
						printf(",");
					}
					else if (j == 28)
					{
						printf(".");
					}
					else
					{
						printf("?");
					}
					break;
				}
			}
			
		}
		
		printf("\n");
		order++;
		
	}
	
	
}