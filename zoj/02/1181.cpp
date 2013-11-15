#include<stdio.h>
#include<stdlib.h>

#define MaxN 100

struct W
{
	char w[7];
}buff[MaxN];
char word[MaxN][7];
char arr[MaxN][7];
char temp[7];

int char_cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

int word_cmp(const void *a, const void *b)
{
	struct W *c = (struct W *)a;
	struct W *d = (struct W *)b;
	int clen = strlen(c -> w);
	int dlen = strlen(d -> w);
	int len = clen < dlen ? clen : dlen;
	int i;
	
	for (i=0; i<len; ++i)
	{
		if (c -> w[i] != d -> w[i])
		{
			return c -> w[i] - d -> w[i];
		}
	}
}

int find(int n)
{
	int i;
	int k = 0;
	
	for (i=0; i<n; ++i)
	{
		if (strcmp(temp, arr[i]) == 0)
		{
			strcpy(buff[k].w, word[i]);
			++k;
		}
	}
	
	return k;
}

int main(void)
{
	int i;
	int j;
	int k;
	int n;
	int m;
	
	scanf("%s", temp);
	i = 0;
	
	while (strcmp(temp, "XXXXXX") != 0)
	{
		strcpy(word[i], temp);
		qsort(temp, strlen(temp), sizeof(temp[0]), char_cmp);
		strcpy(arr[i], temp);
		++i;
		
		scanf("%s", temp);
	}
	
	n = i;
	
	scanf("%s", temp);
	
	while (strcmp(temp, "XXXXXX") != 0)
	{
		qsort(temp, strlen(temp), sizeof(temp[0]), char_cmp);
		m = find(n);
		
		if (m == 0)
		{
			printf("NOT A VALID WORD\n");
			printf("******\n");
		}
		else
		{
			qsort(buff, m, sizeof(buff[0]), word_cmp);
			
			for (i=0; i<m; ++i)
			{
				printf("%s\n", buff[i].w);
			}
			
			printf("******\n");
		}
		
		scanf("%s", temp);
	}
	
	return 0;
}
