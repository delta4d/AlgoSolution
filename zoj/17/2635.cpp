#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define MaxL 101
#define MaxN 27

char key[MaxN];
char temp[MaxN];
char msg[MaxL][MaxN];
char text[MaxL];

int cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

int find_pos(char ch)
{
	int i;
	int len = strlen(key);
	
	for (i=0; i<len; ++i)
	{
		if (ch == key[i])
		{
			return i;
		}
	}
}

void solve()
{
	int len = strlen(text);
	int n = strlen(key);
	int i;
	int j;
	int k;
	int p;
	int offset;
	int ptr = 0;
	memset(msg, '\0', sizeof(msg));
	strcpy(temp, key);
	qsort(temp, n, sizeof(temp[0]), cmp);
	
	for (k=0; k<n; ++k)
	{
		p = find_pos(temp[k]);
		
		offset = 0;
		if (p < len % n)
		{
			offset = 1;
		}
		
		for (i=0; i<len/n+offset; ++i)
		{
			msg[i][p] = *(text + ptr + i) - 'A' + 'a';
		}
		
		ptr += i;
	}
	
	k = 0;
	
	for (i=0; i<=len/n; ++i)
	{
		printf("%s", msg[i]);
	}
	
	printf("\n");
	
	return;
}

int main(void)
{
	int k;
	int test_case;
	
	scanf("%d", &test_case);
	
	for (k=0; k<test_case; ++k)
	{
		scanf("%s %s", key, text);
		
		solve();
	}
	
	return 0;
}
