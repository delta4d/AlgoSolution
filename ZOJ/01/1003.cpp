#include <cstdio>
using namespace std;

#define debug 0
const int MAX = 100;
bool suc;
bool dec;
int x;
int y;

void dfs(int x, int y, int div)
{
	//if (dec) return;
	if (x == 1 && y == 1)
	{
		dec = true;
		return;
	}
	if (y == 1)
	{
		suc = true;
		//return;
	}
	while (div <= MAX && (div <= x || div <= y))
	{
		if (x % div == 0) dfs(x/div, y, div+1);
		if (dec) return;
		if (y % div == 0) dfs(x, y/div, div+1);
		if (dec) return;
		++div;
	}
}

void solve()
{
	if (x < y) x ^= y ^= x ^= y;
	suc = dec = false;
	dfs(x, y, 2);
	if (!dec && suc) printf("%d\n", y);
	else printf("%d\n", x);
}

int main()
{
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	while (scanf("%d %d", &x, &y) != EOF)
	{
		solve();
	}
	
	return 0;
}
