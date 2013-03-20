#include<stdio.h>
#include<memory.h>

int main(void)
{
	char num1[20];
	char num2[20];
	long add1[20];
	long add2[20];
	long len;
	long len1;
	long len2;
	long i;
	long k;
	long res;
	long carry;
	
	scanf("%s %s", num1, num2);

	while (strcmp(num1, "0") != 0 || strcmp(num2, "0") != 0)
	{
		memset(add1, 0, sizeof(add1));
		memset(add2, 0, sizeof(add2));
				
		len1 = strlen(num1);
		len2 = strlen(num2);
		
		for (i=0; i<len1; ++i)
		{
			add1[len1-1-i] = num1[i] - '0';
		}
		
		for (i=0; i<len2; ++i)
		{
			add2[len2-1-i] = num2[i] - '0';
		}
		
		len = len1 > len2 ? len1 : len2;
		carry = 0;
		res = 0;
		
		for (i=0; i<len; ++i)
		{
			k = add1[i] + add2[i] + carry;
			
			if (k > 9)
			{
				++res;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}
		
		if (res == 0)
		{
			printf("No carry operation.\n");
		}
		else if (res == 1)
		{
			printf("%ld carry operation.\n", res);
		}
		else
		{
			printf("%ld carry operations.\n", res);
		}
		
		scanf("%s %s", num1, num2);
	}

	return 0;
}
