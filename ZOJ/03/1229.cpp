#include<cstdio>
#include<memory>

bool flag;
long n;
long m;

void dfs(long pos, long k)
{
	if (flag)
	{
		return;
	}
	
	if (pos == m)
	{
		flag = true;
		return;
	}
	
	if (pos + k <= n)
	{
		dfs(pos + k, k + 2);
	}
	
 	if (pos - k >= 1)
	{
		dfs(pos - k, k + 2);
	}
	
	if (flag)
	{
		return;
	}
}

int main(void)
{
	long i;
	long j;
	
	scanf("%ld %ld", &n, &m);
	
	while (n != 0 || m != 0)
	{
		if (n >= 50)
		{
			printf("Let me try!\n");
		}
		else
		{
			flag = false;
			dfs(0, 1);
			
			if (flag)
			{
				printf("Let me try!\n");
			}
			else
			{
				printf("Don't make fun of me!\n");
			}
		}
		
		scanf("%ld %ld", &n, &m);
	}
	
	return 0;
} 
