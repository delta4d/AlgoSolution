#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MaxL = 128;
const int MaxN = 128;

struct word
{
	char content[MaxL];
	int pp;
}dic[MaxN];
char squence[MaxL];
char buff[MaxL];
char key[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int cmp(const void *a, const void *b)
{
	word *c = (word *)a;
	word *d = (word *)b;
	return strcmp(c->content, d->content);
}

bool is_same(int n, int k)
{
	int i;
	for (i=0; i<n; ++i)
	{
		if (buff[i] != dic[k].content[i])
			return false;
	}
	return true;
}

void gao(int n)
{
	int i;
	int j;
	int k;
	int maxp;
	int curp;
	for (i=0; i<n; ++i)
	{
		for (j=0; j<strlen(key[i]); ++j)
	}
}

int main()
{
	int test_case;
	int dic_num;
	int word_num;
	int tc;
	int i;
	int j;
	int k;
	int len;
	scanf("%d", &test_case);
	
	for (tc=1; tc<=test_case; ++tc)
	{
		scanf("%d", &dic_num);
		for (i=0; i<dic_num; ++i)
		{
			scanf("%s", dic[i].content);
			scanf("%d", &dic[i].pp);
		}
		qsort(dic, dic_num, sizeof(dic[0]), cmp);
		scanf("%d", &word_num);
		for (k=0; k<word_num; ++k)
		{
			scanf("%s", squence);
			len = strlen(squence);
			for (i=1; i<=len; ++i)
			{
				gao(i);
			}
		}
	}
	
	return 0;
}