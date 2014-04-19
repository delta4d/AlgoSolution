#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1 << 10;

vector <pair<int, int> > e[N];
vector <int> out;
int d[N];
bool v[N];

void dfs(int u) {
	v[u] = true;
	for (int i=0; i<(int)e[u].size(); ++i) {
		int v = e[u][i].first;
		if (::v[v]) continue;
		dfs(v);
	}
}

void gao(const int n) {
	memset(d, 0x3f, sizeof(d));
	memset(v, false, sizeof(v));
	d[0] = 0;
	for (int i=1; i<n; ++i) {
		for (int j=0; j<n; ++j) for (int k=0; k<(int)e[j].size(); ++k) {
			int u = j, v = e[j][k].first, w = e[j][k].second;
			d[v] = min(d[v], d[u] + w);
		}
	}
	for (int j=0; j<n; ++j) for (int k=0; k<(int)e[j].size(); ++k) {
		int u = j, v = e[j][k].first, w = e[j][k].second;
		if (d[u] + w < d[v]) dfs(u);
	}
	out.clear();
	for (int i=0; i<n; ++i) if (v[i]) out.push_back(i);
	if (out.empty()) {
		puts("impossible");
		return;
	}
	for (int i=0,sz=(int)out.size(); i<sz; ++i) printf("%d%s", out[i], i==sz-1?"\n":" ");
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,u,v,w; i<m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			e[v].push_back(make_pair(u, w));
		}
		printf("Case %d: ", ++cn);
		gao(n);
	}
	return 0;
}

// 317599	2014-01-27 12:07:21	 1108 - Instant View of Big Bang	 C++	 0.228	 1248	Accepted
