#include<stdio.h>
#include<memory.h>

int r[26][26];
int flag;

void floyd()
{
	int i;
	int j;
	int k;
	
	for (k=0; k<26; ++k)
	{
		for (i=0; i<26; ++i)
		{
			for (j=0; j<26; ++j)
			{
				if ((r[i][k] != 0) && (r[k][j] != 0))
				{
					if (r[i][j] != 1)
					{
						r[i][j] = 2;
						flag = 1;
					}
				}
			}
		}
	}
}

int main()
{
	int TestCase;
	int k;
	int i;
	int j;
	int n;
	int order = 1;
	char relation[10];
	
	scanf("%d", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		memset(r, 0, sizeof(r));
		
		scanf("%d", &n);
		
		for (i=0; i<n; ++i)
		{
			scanf("%s", relation);
			
			if (relation[1] == '>')
			{
				r[relation[2]-'A'][relation[0]-'A'] = 1;
			}
			else
			{
				r[relation[0]-'A'][relation[2]-'A'] = 1;
			}
		}
		
		flag = 0;
		
		floyd();
		
		printf("Case %d:\n", order);
		
		++order;
		
		if (flag == 1)
		{
			for (i=0; i<26; ++i)
			{
				for (j=0; j<26; ++j)
				{
					if (r[i][j] == 2)
					{
						printf("%c<%c\n", i+'A', j+'A');
					}
				}
			}
		}
		else
		{
			printf("NONE\n");
		}
	}
	
	return 0;
}
