#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30000 + 86;

vector <pair<int, int> > e[N];
int n;
int d[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

void dfs(int root, int parent) {
	for (int i=0; i<(int)e[root].size(); ++i) {
		int child = e[root][i].first, cost = e[root][i].second;
		if (child == parent) continue;
		d[child] = d[root] + cost;
		dfs(child, root);
	}
}

int gao(int root) {
	memset(d, 0, n*sizeof(int));
	dfs(root, -1);
	int mx = -1, idx = -1;
	for (int i=0; i<n; ++i) if (d[i] > mx) mx = d[i], idx = i;
	return idx;
}

int main() {
	int tc, cn = 0;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=1,u,v,w; i<n; ++i) {
			u = fastin<int>(), v = fastin<int>(), w = fastin<int>();
			e[u].push_back(make_pair(v, w));
			e[v].push_back(make_pair(u, w));
		}
		printf("Case %d: %d\n", ++cn, d[gao(gao(0))]);
	}
	return 0;
}

// 295128	2013-12-03 23:08:29	 1094 - Farthest Nodes in a Tree	 C++	 0.196	 5384	Accepted
