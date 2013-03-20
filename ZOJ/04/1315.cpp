#include<stdio.h>

#define MaxN 20
#define MaxKL 21
#define MaxL 71

char key[MaxN][MaxKL];
char excuse[MaxN][MaxL];
char buff[MaxKL];
int select[MaxN];
int n;
int m;

char to_low(char ch)
{
	if ((ch <= 'Z') && (ch >= 'A'))
	{
		return ch - 'A' + 'a';
	}
	
	return ch;
}

int is_key()
{
	int i;
	
	for (i=0; i<n; ++i)
	{
		if (strcmp(buff, key[i]) == 0)
		{
			return 1;
		}
	}
	
	return 0;
}

int is_alp(char ch)
{
	if ((ch <= 'z') && (ch >= 'a') || (ch <= 'Z') && (ch >= 'A'))
	{
		return 1;
	}
	
	return 0;
}

int main(void)
{
	int i;
	int j;
	int k;
	int max;
	int key_num;
	int ps;
	int case_num = 1;
	
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%s", key[i]);
		}
		
		max = -1;
		ps = 0;
		getchar();
		
		for (i=0; i<m; ++i)
		{
			gets(excuse[i]);
			k = 0;
			key_num = 0;
			
			for (j=0; j<strlen(excuse[i]); ++j)
			{
				if (is_alp(excuse[i][j]))
				{
					buff[k] = to_low(excuse[i][j]);
					++k;
				}
				else if (k > 0)
				{
					buff[k] = '\0';
					k = 0;
					if (is_key())
					{
						++key_num;
					}
				}
			}
			
			if (key_num > max)
			{
				select[0] = i;
				ps = 1;
				max = key_num;
			}
			else if (key_num == max)
			{
				select[ps] = i;
				++ps;
			}
		}
		
		printf("Excuse Set #%d\n", case_num);
		
		for (i=0; i<ps; ++i)
		{
			printf("%s\n", excuse[select[i]]);
		}
		++case_num;
		printf("\n");
	}
	
	return 0;
}
