#include<stdio.h>

char post[30];
int position;

void build(char *pre, char *in)
{
	int i;
	int j;
	int k;
	int len = strlen(in);
	char tp[30];
	char ti[30];
	
	post[position] = pre[0];
	
	if (len == 1)
	{
		return;
	}
	
	k = 0;
	
	while (in[k] != pre[0])
	{
		++k;
	}
	
	if (k != len-1)
	{
		for (i=k+1; i<len; ++i)
		{
			tp[i-k-1] = pre[i];
			ti[i-k-1] = in[i];
		}
		
		tp[len-k-1] = ti[len-k-1] = '\0';
		--position;
		
		build(tp, ti);	
	}
	
	if (k != 0)
	{
		for (i=1; i<=k; ++i)
		{
			tp[i-1] = pre[i];
			ti[i-1] = in[i-1];
		}
		
		tp[k] = ti[k] = '\0';
		--position;
		
		build(tp, ti);
		
	}

}

int main(void)
{
	char pre[30];
	char in[30];
	int len;
	int i;
	
	while (scanf("%s %s", pre, in) != EOF)
	{
		len = strlen(in);
		position = len;
		
		build(pre, in);
		
		for (i=1; i<=len; ++i)
		{
			printf("%c", post[i]);
		}
		
		printf("\n");
	}

	return 0;
}
