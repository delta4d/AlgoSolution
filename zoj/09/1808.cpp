#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Code
{
	char bit[11];
	int len;
}code[10];

int cmp(const void * a, const void * b)
{
	struct Code * c = (struct Code *) a;
	struct Code * d = (struct Code *) b;
	
	return c -> len - d -> len;
}

int main(void)
{
	int i;
	int j;
	int k;
	int n;
	int flag;
	int order = 1;
	char s[11];
	
	while (scanf("%s", s) != EOF)
	{
		i = 2;
		strcpy(code[0].bit, s);
		code[0].len = strlen(s);
		
		scanf("%s", s);
		strcpy(code[1].bit, s);
		code[1].len = strlen(s);
		
		while (strcmp(s, "9") != 0)
		{
			scanf("%s", s);
			strcpy(code[i].bit, s);
			code[i].len = strlen(s);
			++i;
		}
		
		n = i - 1;
		
		flag = 1;
		
		qsort(code, n, sizeof(code[0]), cmp);
		
		for (i=0; i<n; ++i)
		{
			for (j=i+1; j<n; ++j)
			{
				for (k=0; k<code[i].len; ++k)
				{
					s[k] = code[j].bit[k];
				}
				
				s[code[i].len] = '\0';
				
				if (strcmp(code[i].bit, s) == 0)
				{
					flag = 0;
					break;
				}
			}
			
			if (flag == 0)
			{
				break;
			}
		}
		
		if (flag == 1)
		{
			printf("Set %d is immediately decodable\n", order);
			++order;
		}
		else
		{
			printf("Set %d is not immediately decodable\n", order);
			++order;
		}
	}
	
	return 0;
}
