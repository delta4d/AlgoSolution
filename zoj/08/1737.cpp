#include<stdio.h>

int main(void)
{
	char message[26];
	char t[26];
	char order[7];
	char mlen;
	char olen;
	char temp;	
	int TestCase;
	int i;
	int j;
	int k;
	
	scanf("%d", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%s %s", order, message);
		
		olen = strlen(order);
		mlen = strlen(message);
		
		for (i=olen-1; i>=0; --i)
		{
			if (order[i] == 'J')
			{
				temp = message[mlen-1];
				
				for (j=mlen-1; j>=0; --j)
				{
					message[j] = message[j-1];
				}
				
				message[0] = temp;
			}
			else if (order[i] == 'C')
			{
				temp = message[0];
				
				for (j=0; j<mlen-1; ++j)
				{
					message[j] = message[j+1];
				}
				
				message[mlen-1] = temp;
			}
			else if (order[i] == 'E')
			{
				for (j=0; j<mlen/2; ++j)
				{
					t[j] = message[j];
				}
				
				if (mlen % 2 == 0)
				{
					for (j=0; j<mlen/2; ++j)
					{
						message[j] = message[j+mlen/2];
					}
					
					for (j=0; j<mlen/2; ++j)
					{
						message[j+mlen/2] = t[j];
					}
				}
				else
				{
					for (j=0; j<mlen/2; ++j)
					{
						message[j] = message[j+mlen/2+1];
					}
					
					for (j=0; j<mlen/2; ++j)
					{
						message[j+mlen/2+1] = t[j];
					}
				}								
			}
			else if (order[i] == 'A')
			{
				for (j=0; j<mlen; ++j)
				{
					t[mlen-j-1] = message[j];
				}
				
				for (j=0; j<mlen; ++j)
				{
					message[j] = t[j];
				}
			}
			else if (order[i] == 'P')
			{
				for (j=0; j<mlen; ++j)
				{
					if ((message[j] >= '0') && (message[j] <= '9'))
					{
						message[j] = (message[j] - '0' - 1 + 10) % 10 + '0';
					}
				}
			}
			else
			{
				for (j=0; j<mlen; ++j)
				{
					if ((message[j] >= '0') && (message[j] <= '9'))
					{
						message[j] = (message[j] - '0' + 1) % 10 + '0';
					}
				}
			}
		}
		
		printf("%s\n", message);
	}
	
	return 0;
}
