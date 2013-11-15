#include <cstdio>
#include <memory>
#include <cstring>
using namespace std;

#define debug 0
const int MaxN = 11;
const int MaxL = 64;
bool youjie;
bool graph[MaxL][MaxL];
int cake[MaxN];
int tot;
int n;

inline void reset(int x, int y, int k)
{
	for (int i=x; i<x+k; ++i) for (int j=y; j<y+k; ++j) graph[i][j] = false;
}

inline void set(int x, int y, int k)
{
	for (int i=x; i<x+k; ++i) for (int j=y; j<y+k; ++j) graph[i][j] = true;
}

inline bool can_put(int x, int y, int k)
{
	if (x + k - 1 > tot || y + k - 1 > tot) return false;
	for (int i=x; i<x+k; ++i) for (int j=y; j<y+k; ++j) if (graph[i][j]) return false;
	return true;
}

inline void find(int &x, int &y)
{
	for (x=1; x<=tot; ++x) for (y=1; y<=tot; ++y) if (!graph[x][y]) return;
}

void dfs(int d)
{
	int i;
	int j;
	int x;
	int y;
	if (d == n)
	{
		youjie = true;
		return;
	}
	for (i=1; i<MaxN; ++i)
	{
		if (cake[i] > 0)
		{
			find(x, y);
			if (can_put(x, y, i))
			{
				--cake[i];
				set(x, y, i);
				dfs(d+1);
				if (youjie) return;
				++cake[i];
				reset(x, y, i);
			}
		}
	}
}

int main()
{
	int i;
	int j;
	int k;
	int t;
	int tc;
	int sum;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	scanf("%d", &tc);
	for (k=0; k<tc; ++k)
	{
		sum = 0;
		memset(cake, 0, sizeof(cake));
		memset(graph, false, sizeof(graph));
		
		scanf("%d %d", &tot, &n);
		for (i=0; i<n; ++i)
		{
			scanf("%d", &t);
			++cake[t];
			sum += t * t;
		}
		if (tot * tot != sum)
		{
			printf("HUTUTU!\n");
			continue;
		}
		youjie = false;
		dfs(0);
		if (youjie) printf("KHOOOOB!\n");
		else printf("HUTUTU!\n");
	}
	
	return 0;
}
