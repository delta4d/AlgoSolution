#include <cstdio>
#include <memory>
using namespace std;

int res[16][1<<15];
bool visit[1<<15];
bool find;

void dfs(int d, const int &n)
{
	if (d == 1 << n)
	{
		if (res[n][d-1] == 1 << (n-1))
		{
			find = true;
			return;
		}
	}
	int t = (1 << (n-1)) - 1;
	int x1 = (res[n][d-1] & t) << 1;
	int x2 = x1 + 1;
	if (!visit[x1])
	{
		visit[x1] = true;
		res[n][d] = x1;
		dfs(d+1, n);
		if (find) return;
		visit[x1] = false;
	}
	if (!visit[x2])
	{
		visit[x2] = true;
		res[n][d] = x2;
		dfs(d+1, n);
		if (find) return;
		visit[x2] = false;
	}
}

void gen()
{
	for (int i=1; i<16; ++i)
	{
		memset(visit, false, sizeof(visit));
		find = false;
		visit[0] = true;
		dfs(1, i);
	}
}

int main()
{
	int n;
	int k;
	gen();
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	while (n != 0 || k != 0)
	{
		printf("%d\n", res[n][k]);
		scanf("%d %d", &n, &k);
	}
	
	return 0;
}
