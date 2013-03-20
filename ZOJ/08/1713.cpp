#include<cstdio>
#include<memory>
using namespace std;

const int MaxL(200);
char s[MaxL];
char f[MaxL];

bool is_vow(char ch)
{
	return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'y');
}

int count_syb(int n)
{
	int i;
	int j;
	int res(0);
	
	for (i=0; i<n; ++i)
	{
		if (is_vow(f[i]))
		{
			while (is_vow(f[i]))
			{
				++i;
			}
			
			++res;
		}
	}
	
	return res;
}

int main(void)
{
	int num_syb[4];
	int i;
	int k;
	int len;
	
	gets(s);
	
	while (strcmp(s, "e/o/i") != 0)
	{
		len = strlen(s);
		i = 0;
		
		while (s[i] != '/')
		{
			++i;
		}
		
		memcpy(f, s, i * sizeof(s[0]));
		num_syb[1] = count_syb(i);
		++i;
		k = i;
		
		while (s[i] != '/')
		{
			++i;
		}
		
		memcpy(f, s+k, (i-k) * sizeof(s[0]));
		num_syb[2] = count_syb(i-k);
		
		memcpy(f, s+i+1, (len-i) * sizeof(s[0]));
		num_syb[3] = count_syb(len-i);
		
		if (num_syb[1] == 5)
		{
			if (num_syb[2] == 7)
			{
				if (num_syb[3] == 5)
				{
					printf("Y\n");
				}
				else
				{
					printf("3\n");
				}
			}
			else
			{
				printf("2\n");
			}
		}
		else
		{
			printf("1\n");
		}
		
		gets(s);
	}
	
	return 0;
}
