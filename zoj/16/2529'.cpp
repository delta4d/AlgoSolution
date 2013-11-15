#include<stdio.h>
#include<memory.h>

int a[30];
int b[30];
int sum[30];
int prime[30];
int len;

void gen_prime()
{
	int i;
	int j;
	int flag;
	int k = 0;
	
	for (i=2; k<30; ++i)
	{
		flag = 1;
		
		for (j=2; j*j<=i; ++j)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		
		if (flag == 1)
		{
			prime[k] = i;
			++k;
		}
	}
	
	return;
}

void add()
{
	int i;
	
	for (i=0; i<len; ++i)
	{
		sum[i] = sum[i] + a[i] + b[i];
		
		if (sum[i] >= prime[i])
		{
			sum[i + 1] = sum[i + 1] + sum[i] / prime[i];
			sum[i] = sum[i] % prime[i];
		}
	}
	
	if (sum[len] != 0)
	{
		++len;
	}
	
	return;
}

int main(void)
{
	char ch;
	int temp[30];
	int t;
	int i;
	int k;
	int alen;
	int blen;
	int tlen;
	gen_prime();
	
	while (scanf("%d", &t) != EOF)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(sum, 0, sizeof(sum));
		
		ch = getchar();
		tlen = 0;
		
		while (ch != ' ')
		{
			temp[tlen] = t;
			++tlen;
			scanf("%d", &t);
			ch = getchar();
		}
		
		for (i=tlen-1; i>=0; --i)
		{
			a[i] = temp[tlen-i-1];
		}
		alen = tlen;
		
		scanf("%d", &t);
		ch = getchar();
		tlen = 0;
		
		while (ch != '\0')
		{
			temp[tlen] = t;
			++tlen;
			scanf("%d", &t);
			ch = getchar();
		}
		
		for (i=tlen-1; i>=0; --i)
		{
			b[i] = temp[tlen-i-1];
		}
		blen = tlen;
		
		len = alen > blen ? alen : blen;
		
		add();
		
		for (i=len-1; i>0; --i)
		{
			printf("%d,", sum[i]);
		}
		
		printf("%d\n", sum[0]);
	}
	
	return 0;
}
