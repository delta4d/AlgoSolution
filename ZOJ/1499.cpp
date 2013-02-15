#include <cstdio>
#include <memory>
#include <cstring>
using namespace std;

#define debug 0
const int INF = 0x7fffffff;
const int MaxL = 88;
char s[MaxL];
int ds[MaxL];
int dt[MaxL];
int f[MaxL];
int out[MaxL];
int len;
int MIN;
int ol;

inline void update(int n)
{
	for (int i=0; i<n; ++i) {out[i] = f[i]; ds[i] = dt[i];}
	MIN = f[n-1];
	ol = n;
}

inline bool need_update(int n)
{
	for (int i=0; i<n; ++i) if (f[i] > out[i]) return true;
	return false;
}

void dfs(int d, int cn, int cs)
{
	int i;
	int j;
	int t;
	if (d < len && cs >= MIN) return;
	if (d == len)
	{
		if (cs < MIN) update(cn);
		else if (cs == MIN) if (need_update(cn)) update(cn);
		return;
	}
	t = 0;
	for (i=d; i<len; ++i)
	{
		t = t * 10 + s[i] - '0';
		if (t > cs)
		{
			f[cn] = t;
			dt[cn] = i;
			dfs(i+1, cn+1, t);
		}
	}
}

int main()
{
	int i;
	int k;
#if debug
	freopen("f:\\in.txt", "r", stdin);
	freopen("f:\\out.txt", "w", stdout);
#endif
	scanf("%s", s);
	while (strcmp(s, "0") != 0)
	{
		len = strlen(s);
		MIN = INF;
		memset(ds, 0, sizeof(ds));
		memset(dt, 0, sizeof(dt));
		ol = 0;
		dfs(0, 0, 0);
		k = 0;
		for (i=0; i<len; ++i)
		{
			printf("%c", s[i]);
			if (i == ds[k] && i != len - 1 && k < ol)
			{
				printf(",");
				++k;
			}
		}
		printf("\n");
		scanf("%s", s);
	}
	
	return 0;
}
