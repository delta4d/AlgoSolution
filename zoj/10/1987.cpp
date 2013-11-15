#include <set>
#include <bitset>
#include <cstdio>
using namespace std;

#define debug 0
#define IN(x) scanf("%d", &x);
#define OUT(x) printf("%d\n", x);
const int MAXSIZE = 36;
int n;
bitset<MAXSIZE>state[MAXSIZE];

inline void init()
{
	for (int i=0; i<MAXSIZE; ++i) state[i].reset();
}

inline void input()
{
	int x;
	int y;
	IN(n);
	for (int i=0; i<n; ++i)
	{
		IN(x); IN(y);
		state[x-1].set(y-1);
	}
}

bool dfs(const int &match, int cur, int sel, bitset<MAXSIZE>mask)
{
	if (mask.count() < match) return false;
	if (sel == match) return true;
	if (sel + MAXSIZE - cur < match) return false;
	return dfs(match, cur+1, sel, mask) || dfs(match, cur+1, sel+1, mask&state[cur]);
}

void solve()
{
	int curn;
	bitset<MAXSIZE>mask;
	mask.set();
	for (curn=2; curn*curn<=n&&dfs(curn, 0, 0, mask); ++curn);
	OUT(curn-1);
}

int main()
{
	int i;
	int tc;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	IN(tc);
	for (i=0; i<tc; ++i)
	{
		init();
		input();
		solve();
	}

	return 0;
}
