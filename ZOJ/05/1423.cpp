#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int MaxL = 100;

bool is_op;
bool match;
char buff[MaxL];
char f[MaxL];

int find(int p)
{
	int left(0);
	int right(0);
	int i;
	is_op = false;
	
	for (i=p; ; ++i)
	{
		if (buff[i] == '(')
		{
			++left;
			continue;
		}
		if (buff[i] == ')')
		{
			++right;
			if (right == left)
			{
				return i;
			}
			continue;
		}
		if (buff[i] == '-' || buff[i] == '+')
		{
			is_op = true;
		}
	}
}

int main(void)
{
	int test_case;
	int i;
	int j;
	int k;
	int len;
	
	scanf("%d", &test_case);
	getchar();
	
	for (k=0; k<test_case; ++k)
	{
		gets(f);
		
		len = strlen(f);
		j = 0;
		for (i=0; i<len; ++i)
		{
			if (f[i] != ' ')
			{
				buff[j] = f[i];
				++j;
			}
		}
		
		len = j;
		for (i=0; i<len; ++i)
		{
			if (buff[i] == '(')
			{
				if (i == 0 || buff[i-1] != '-' && i > 0)
				{
					buff[find(i)] = ' ';
					buff[i] = ' ';
				}
				else if (buff[i-1] == '-' && i > 0)
				{
					int t = find(i);
					if (!is_op)
					{
						buff[i] = ' ';
						buff[t] = ' ';
					}
				}
			}
		}
		
		for (i=0; i<len; ++i)
		{
			if (buff[i] != ' ')
			{
				printf("%c", buff[i]);
			}
		}
		
		printf("\n");
	}
		
	return 0;
}
