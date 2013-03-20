#include<stdio.h>

int main(void)
{
	char temp[30];
	double sum;
	double money;
	long t;
	long i;
	long j;
	long k;
	long n;
	long tm[30];
	
	scanf("%ld", &n);
	
	while (n != 0)
	{
		sum = 0;
		
		for (k=0; k<n; ++k)
		{
			scanf("%s", temp);
			money = 0;
		
			for (i=0; temp[i]!='\0'; ++i)
			{
				if ((temp[i] != '$') && (temp[i] != ',') && (temp[i] != '.'))
				{
					money = money * 10 + temp[i] - '0';
				}
			}
					
			sum += money;
		}
		
		k = 1;
		t = (long)sum;
		tm[1] = 0;
		
		while (t != 0)
		{
			tm[k] = (t % 10);
			t /= 10;
			++k;
		}
		
		printf("$");
		
		for (i=k-1; i>2; --i)
		{
			if ((i != (k-1)) && ((i-2) % 3 == 0))
			{
				printf(",%ld", tm[i]);
			}
			else
			{
				printf("%ld", tm[i]);
			}
		}
		
		if (sum >= 100)
		{	
			printf(".%ld%ld\n", tm[2], tm[1]);
		}
		else
		{
			sum = sum / 100.0;
			printf("%.2lf\n", sum);
		}
				
		scanf("%ld", &n);
	}
	
	return 0;
}
