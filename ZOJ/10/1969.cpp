#include<stdio.h>

long num[10];

long convert(long k)
{
	long i;
	long res = 0;
	
	for (i=k; i>-1; --i)
	{
		res = res * 10 + num[i];
	}
	
	return res;
}

int main(void)
{
	char equation[30];
	long len;
	long a;
	long i;
	long k;
	long start;
	
	do
	{
		scanf("%s", equation);
		
		len = strlen(equation);
		k = 0;
		start = 0;
		
		for (i=start; equation[i] != '+'; ++i)
		{
			num[k] = equation[i] - '0';
			++k;
		}
		
		a = convert(k-1);
		
		k = 0;
		start = i + 1;	
	
		for (i=start; equation[i] != '='; ++i)
		{
			num[k] = equation[i] - '0';
			++k;
		}
		
		a += convert(k-1);
		
		k=0;
		start = i + 1;
		
		for (i=start; i<len; ++i)
		{
			num[k] = equation[i] - '0';
			++k;
		}
		
		a -= convert(k-1);
	
		if (a == 0)
		{
			printf("True\n");
		}
		else
		{
			printf("False\n");
		}
				
	}while (strcmp(equation, "0+0=0") != 0);

	return 0;
}
