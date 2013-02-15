#include<stdio.h>

char s[100];

int ism()
{
	char temp[100];
	int i;
	int len = strlen(s);
	int flag = 1;
	
	for (i=0; i<len; ++i)
	{
		switch(s[i])
		{
			case 'E': temp[i] = '3'; break;
			case 'J': temp[i] = 'L'; break;
			case 'L': temp[i] = 'J'; break;
			case 'S': temp[i] = '2'; break;
			case 'Z': temp[i] = '5'; break;
			case '2': temp[i] = 'S'; break;
			case '3': temp[i] = 'E'; break;
			case '5': temp[i] = 'Z'; break;
			case 'A': temp[i] = 'A'; break;
			case 'H': temp[i] = 'H'; break;
			case 'I': temp[i] = 'I'; break;
			case 'M': temp[i] = 'M'; break;
			case 'O': temp[i] = 'O'; break;
			case 'T': temp[i] = 'T'; break;
			case 'U': temp[i] = 'U'; break;
			case 'V': temp[i] = 'V'; break;
			case 'W': temp[i] = 'W'; break;
			case 'X': temp[i] = 'X'; break;
			case 'Y': temp[i] = 'Y'; break;
			case '1': temp[i] = '1'; break;
			case '8': temp[i] = '8'; break;
			default: flag = 0; break;
		}
		
		if (flag == 0)
		{
			break;
		}
	}

	if (flag == 1)
	{
		for (i=0; i<len; ++i)
		{
			if (temp[len-1-i] != s[i])
			{
				flag = 0;
				break;
			}
		}	
	}
	
	return flag;
}

int isp()
{
	int i;
	int len = strlen(s);
	int flag = 1;
	
	for (i=0; i<len; ++i)
	{
		if (s[i] != s[len-1-i])
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}

int main(void)
{
	int m;
	int p;
	
	while (scanf("%s", s) != EOF)
	{
		m = ism();
		p = isp();
		
		printf("%s", s);
		
		if ((m == 1) && (p == 1))
		{
			printf(" -- is a mirrored palindrome.\n\n");
		}
		else if ((m == 1) && (p == 0))
		{
			printf(" -- is a mirrored string.\n\n");
		}
		else if ((m == 0) && (p == 1))
		{
			printf(" -- is a regular palindrome.\n\n");
		}
		else
		{
			printf(" -- is not a palindrome.\n\n");
		}
	}
	
	return 0;
}
