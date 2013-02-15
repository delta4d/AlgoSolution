#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define debug 0
const int MaxL = 100;
const int MaxN = 2000;
struct word
{
	char content[MaxL];
	int time;
};
word term[MaxN];
word doc[MaxN];
char buff[MaxL];
char temp[MaxL];

inline bool legal(char c)
{
	return (c <= '9' && c >= '0') || (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'); 
}

inline char tran(char c)
{
	if (c <= 'Z' && c >= 'A') return c - 'A' + 'a';
	return c;
}

inline void modify()
{
	int i;
	int k(0);
	int len(strlen(buff));
	for (i=0; i<len; ++i)
	{
		if (legal(buff[i]))
		{
			temp[k] = tran(buff[i]);
			++k;
		}
	}
	temp[k] = '\0';
	strcpy(buff, temp);
}

void insert(word *f, int &n)
{
	int i;
	modify();
	if (strlen(buff) == 0) return;
	for (i=0; i<n; ++i)
	{
		if (strcmp(f[i].content, buff) == 0) 
		{
			++f[i].time;
			return;
		}
	}
	strcpy(f[n].content, buff);
	f[n].time = 1;
	++n;
	return;
}

void calc_score(int tn, int dn)
{
	int i;
	int j;
	double res(0);
	for (i=0; i<tn; ++i)
	{
		for (j=0; j<dn; ++j)
		{
			if (strcmp(term[i].content, doc[j].content) == 0)
			{
				res += sqrt(term[i].time*doc[j].time);
				break;
			}
		}
	}
	printf("%.2lf\n", res);
}

int main()
{
	int i;
	int j;
	int k;
	int tc;
	int tn;
	int dn;
	int test_case;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	scanf("%d", &test_case);
	for (tc=0; tc<test_case; ++tc)
	{
		tn = 0;
		scanf("%s", buff);
		while (strcmp(buff, "----------") != 0)
		{
			insert(term, tn);
			scanf("%s", buff);
		}
		scanf("%s", buff);
		while (strcmp(buff, "----------") != 0)
		{
			dn = 0;
			while (strcmp(buff, "----------") != 0)
			{
				insert(doc, dn);
				scanf("%s", buff);
			}
			calc_score(tn, dn);
			scanf("%s", buff);
		}
		if (tc != test_case - 1) printf("\n");
	}
	
	return 0;
}
