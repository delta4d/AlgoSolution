#include<stdio.h>
#include<memory.h>

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,
			  59,61,67,71,73,79,83,89,97,101,103,107,109,113};
			  
int a[30];
int b[30];
int sum[30];

int add(int len)
{
	int i;
	
	memset(sum, 0, sizeof(sum));
	
	for (i=0; i<len; ++i)
	{
		sum[i] = a[i] + b[i] + sum[i];
		
		if (sum[i] >= prime[i])
		{
			sum[i + 1] = sum[i] / prime[i];
			sum[i] = sum[i] % prime[i];
		}
	}
	
	if (sum[len] != 0)
	{
		++len;
	}
	
	return len;
}

int main(void)
{
	int len;
	int alen;
	int blen;
	int t;
	int i;
	int j;
	int k;
	int num;
	int temp[30];
	char atemp[100];
	char btemp[100];
	
	while (scanf("%s %s", atemp, btemp) != EOF)
	{
		k = 0;
		num = 0;
		for (i=0; i<strlen(atemp); ++i)
		{
			if (atemp[i] != ',')
			{
				temp[k] = num;
				++k;
				num = 0;
			}
			else
			{
				num = num * 10 + atemp[i] - '0';
			}
		}
		
		temp[k] = num;
		++k;
		
		for (i=0; i<k; ++i)
		{
			a[i] = temp[k-1-i];
		}
		
		alen = k;
		
		k = 0;
		num = 0;
		for (i=0; i<strlen(btemp); ++i)
		{
			if (btemp[i] != ',')
			{
				temp[k] = num;
				++k;
				num = 0;
			}
			else
			{
				num = num * 10 + btemp[i] - '0';
			}
		}
		
		temp[k] = num;
		++k;
		
		for (i=0; i<k; ++i)
		{
			a[i] = temp[k-1-i];
		}
		
		blen = k;
		
		len = alen > blen ? alen : blen;
		
		len = add(len);
		
		for (i=len-1; i>0; --i)
		{
			printf("%d,", sum[i]);
		}
		
		printf("%d\n", sum[0]);
	}
	
	return 0;
}
