#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
int const N = 1e5 + 10;
int const M = 1e9 + 7;
vector <int> e[N];
int dfn[N], low[N];
int st[N], sp;
int cost[N], ts;
bool in[N];
ll min_cost, ways = 1;

void dfs(int x) {
	dfn[x] = low[x] = ++ts;
	st[sp++] = x, in[x] = true;
	for (auto y: e[x]) {
		if (!dfn[y]) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
		if (in[y]) low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		int mn = cost[x], cnt = 1;
		in[x] = false;
		for (; sp>0&&st[sp-1]!=x; --sp) {
			int cc = st[sp-1];
			in[cc] = false;
			if (cost[cc] < mn) mn = cost[cc], cnt = 1;
			else if (cost[cc] == mn) ++cnt;
		}
		--sp;
		ways = ways * cnt % M;
		min_cost += mn;
	}
}

void scc(int n) {
	for (int i=0; i<n; ++i) if (!dfn[i]) dfs(i);
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", cost+i);
	scanf("%d", &m);
	for (int x,y; m--; ) {
		scanf("%d%d", &x, &y);
		e[x-1].push_back(y-1);
	}
	scc(n);
	printf("%I64d %I64d\n", min_cost, ways);
	return 0;
}

// 6537016	 May 3, 2014 11:58:51 AM	delta_4d	 C - Checkposts	 GNU C++0x	Accepted	 139 ms	 8500 KB
