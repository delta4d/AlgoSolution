#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int const INF = 0x3f3f3f3f;
int const N = 1 << 9;
int d[N][N], c[N], cnt[N];
vector <int> e[100001];
bool v[100001];
int vv[100001];
int n, m, k, t = 1;

inline int T(int x) { return lower_bound(c, c+k, x) - c; }

void dfs(int x) {
	v[x] = true, --cnt[T(x)], vv[T(x)] = t;
	for (auto y: e[x]) if (!v[y] && (!vv[T(y)] || vv[T(y)] == t)) dfs(y);
}

bool ok() {
	for (int i=1; i<=n; ++i) if (!v[i] && !vv[T(i)]) dfs(i), vv[T(i)] = ++t;
	for (int i=0; i<k; ++i) if (cnt[i]) return false;
	return true;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i=0; i<k; ++i) scanf("%d", c+i), cnt[i] = c[i];
	for (int i=1; i<k; ++i) c[i] += c[i-1];
	for (int i=0; i<k; ++i) fill(d[i], d[i]+k, INF), d[i][i] = 0;
	for (int u,v,x; m--; ) {
		scanf("%d%d%d", &u, &v, &x);
		int a = T(u), b = T(v);
		if (a != b) d[a][b] = d[b][a] = min(d[a][b], x);
		if (!x) e[u].push_back(v), e[v].push_back(u);
	}
	if (!ok()) return puts("No"), 0;
	for (int t=0; t<k; ++t) for (int i=0; i<k; ++i) for (int j=0; j<k; ++j) d[i][j] = min(d[i][j], d[i][t]+d[t][j]);
	for (int i=0; i<k; ++i) for (int j=0; j<k; ++j) if (d[i][j] >= INF) d[i][j] = -1;
	puts("Yes");
	for (int i=0; i<k; ++i) for (int j=0; j<k; ++j) printf("%d%s", d[i][j], j==k-1?"\n":" ");
	return 0;
}

// 6561819	 May 6, 2014 3:15:51 PM	delta_4d	 D - Dima and Bacteria	 GNU C++0x	Accepted	 234 ms	 4700 KB
