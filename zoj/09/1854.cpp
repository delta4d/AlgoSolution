#include<stdio.h>
#include<memory.h>

#define MaxL 81
#define MaxN 21

int n;
int f[MaxN];
char person[MaxN][MaxL];
char party[MaxN][MaxL];
char temp[MaxL];

int find()
{
	int i;
	
	for (i=0; i<n; ++i)
	{
		if (strcmp(temp, person[i]) == 0)
		{
			return i;
		}
	}
	
	return n;
}

int main(void)
{
	int m;
	int i;
	int k;
	int max;
	int index;
	
	while (scanf("%d", &n) != EOF)
	{
		while (getchar() != '\n'){}
		
		for (i=0; i<n; ++i)
		{
			gets(person[i]);
			gets(party[i]);
		}
		
		scanf("%d", &m);
		while (getchar() != '\n'){}
		memset(f, 0 ,sizeof(f));
		
		for (i=0; i<m; ++i)
		{
			gets(temp);
 			++f[find()];
		}
		
		max = -1;
		
		for (i=0; i<n; ++i)
		{
			if (max < f[i])
			{
				max = f[i];
				index = i;
				k = 1;
			}
			else if (max == f[i])
			{
				++k;
			}
		}
		
		if (k != 1)
		{
			printf("tie\n");
		}
		else
		{
			printf("%s\n", party[index]);
		}
	}
	
	return 0;
}
