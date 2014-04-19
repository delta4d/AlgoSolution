#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int> e[10000], p;
bool v[10000];

void dfs(int x) {
	v[x] = true;
	for (int i=0; i<(int)e[x].size(); ++i) {
		int y = e[x][i];
		if (v[y]) continue;
		dfs(y);
	}
	p.push_back(x);
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,a,b; i<m; ++i) {
			scanf("%d%d", &a, &b), --a, --b;
			e[a].push_back(b);
		}
		p.clear();
		memset(v, false, sizeof(v));
		for (int i=0; i<n; ++i) if (!v[i]) dfs(i);
		int cnt = 0;
		memset(v, false, sizeof(v));
		for (int i=n-1; i>=0; --i) if (!v[p[i]]) dfs(p[i]), ++cnt;
		printf("Case %d: %d\n", ++cn, cnt);
	}
	return 0;
}

// 309790	2014-01-09 22:01:21	 1034 - Hit the Light Switches	 C++	 0.124	 2396	Accepted
