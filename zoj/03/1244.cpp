#include<cstdio>
#include<memory>

using namespace std;

const int MaxL = 26;

bool f[MaxL];
bool find;
char buff[10];

int main(void)
{
	int n;
	int i;
	int j;
	int last;
	int case_num = 1;
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		getchar();
		memset(f, false, sizeof(f));
		f[0] = true;
		
		for (i=0; i<n; ++i)
		{
			gets(buff);
			
			f[buff[0]-'a'] = f[buff[4]-'a'];
		}
		
		printf("Program #%d\n", case_num);
		find = false;
		
		for(i=0; i<MaxL; ++i)
		{
			if (f[i])
			{
				find = true;
				printf("%c ", i + 'a');
			}			
		}
		
		if (!find)
		{
			printf("none");
		}
		
		printf("\n\n");
		++case_num;
		scanf("%d", &n);
	}
	
	return 0;
}
