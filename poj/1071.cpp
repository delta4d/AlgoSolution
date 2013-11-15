#include <cstdio>
#include <memory>
using namespace std;

#define debug 0
const int MaxN = 100;
const int MaxL = 1000;
int f[MaxN][MaxN];
int l[MaxL];
int g[MaxL];
char d[MaxL][2];
int n;
int m;
int no;
bool gaoding;

bool kezou(int x, int y, int step, char dir)
{
	int i;
	int j;
	switch (dir)
	{
		case 'R': for (i=1; i<=step; ++i) if (y + i >= n || f[x][y+i] == 1) return false; return true;
		case 'L': for (i=1; i<=step; ++i) if (y - i < 0  || f[x][y-i] == 1) return false; return true;
		case 'U': for (i=1; i<=step; ++i) if (x - i < 0  || f[x-i][y] == 1) return false; return true;
		case 'D': for (i=1; i<=step; ++i) if (x + i >= n || f[x+i][y] == 1) return false; return true;
		default: throw "kezou() error !"; break;
	}
}

void gao(int x, int y, int n)
{
	int i;
	if (n == no)
	{
		gaoding = true;
		return;
	}
	for (i=l[n]; i<=g[n]; ++i)
	{
		switch (d[n][0])
		{
			case 'R': if (kezou(x, y, i, 'R')) gao(x, y+i, n+1); if (gaoding) return; break;
			case 'L': if (kezou(x, y, i, 'L')) gao(x, y-i, n+1); if (gaoding) return; break;
			case 'U': if (kezou(x, y, i, 'U')) gao(x-i, y, n+1); if (gaoding) return; break;
			case 'D': if (kezou(x, y, i, 'D')) gao(x+i, y, n+1); if (gaoding) return; break;
			default: throw "gao() error !"; break;
		}
	}
}

int main()
{
	int i;
	int j;
	int k;
	int tc;
	int res;
	int test_case;

#if debug
	freopen("f:\\in.txt", "r", stdin);
	freopen("f:\\out1.txt", "w", stdout);
#endif
	scanf("%d", &test_case);
	
	for (tc=0; tc<test_case; ++tc)
	{
		scanf("%d %d", &m, &n);
		for (i=0; i<m; ++i)
		{
			for (j=0; j<n; ++j)
			{
				scanf("%d", &f[i][j]);
			}
		}
		no = 0;
		scanf("%d %d", l+no, g+no);
		while (l[no] != 0 || g[no] != 0)
		{
			scanf("%s", d[no]);
			++no;
			scanf("%d %d", l+no, g+no);
		}
		res = 0;
		for (i=0; i<m; ++i)
		{
			for (j=0; j<n; ++j)
			{
				if (f[i][j] == 0)
				{
					gaoding = false;
					gao(i, j, 0);
					if (gaoding)
					{
						++res;
						//printf("%d %d\n", i, j);
					}
				}
			}
		}
		printf("%d\n", res);
	}
	
	return 0;
}