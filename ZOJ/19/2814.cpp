#include<cstdio>
#include<memory>
using namespace std;

int f[26][26];

int main()
{
	char s[80];
	int i;
	int j;
	int k;
	int len;
	bool flag;
	
	scanf("%s", s);
	
	while (strcmp(s, "*") != 0)
	{
		len = strlen(s);
		flag = true;
		
		for (k=1; k<len; ++k)
		{
			memset(f, 0 ,sizeof(f));
			
			for (i=0; i+k<len; ++i)
			{
				j = i + k;
				
				if (f[s[i]-'A'][s[j]-'A'] == 0)
				{
					f[s[i]-'A'][s[j]-'A'] = 1;
				}
				else
				{
					flag = false;
					break;
				}
			}
			
			if (!flag)
			{
				break;
			}
		}
		
		if (flag)
		{
			printf("%s is surprising.\n", s);
		}
		else
		{
			printf("%s is NOT surprising.\n", s);
		}
		
		scanf("%s", s);
	}
	
	return 0;
}
