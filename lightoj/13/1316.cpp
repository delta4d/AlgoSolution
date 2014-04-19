#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 501;

vector <pair<int, int> > e[MAXN];
int d[16][MAXN], p[15];
int f[1<<15][15];
bool inq[MAXN], st, ed;
queue <int> q;

void spfa(int st, int n, int d[]) {
	while (!q.empty()) q.pop();
	memset(inq, false, sizeof(inq));
	fill(d, d+n, -1);
	d[st] = 0;
	q.push(st);
	inq[st] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = false;
		for (int i=0; i<(int)e[u].size(); ++i) {
			int v = e[u][i].first, w = e[u][i].second;
			if (d[v] == -1 || d[u] + w < d[v]) {
				d[v] = d[u] + w;
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
}

void gao(const int n, const int s) {
	for (int i=0; i<s; ++i) spfa(p[i], n, d[i]);
	spfa(0, n, d[s]);
	if (d[s][n-1] == -1) {
		puts("Impossible");
		return;
	}
	int m = 1 << s, mn = d[s][n-1], t = 0;
	memset(f, -1, sizeof(f));
	for (int i=0; i<s; ++i) f[1<<i][i] = d[s][p[i]];
	for (int mask=0; mask<m; ++mask) for (int i=0; i<s; ++i) {
		if (f[mask][i] == -1) if (mask & 1 << i) {
			int next_mask = mask ^ (1 << i);
			for (int j=0; j<s; ++j) if (next_mask & 1 << j) {
				if (f[next_mask][j] == -1 || d[j][p[i]] == -1) continue;
				int cc = f[next_mask][j] + d[j][p[i]];
				f[mask][i] = f[mask][i] == -1 ? cc : min(f[mask][i], cc);
			}
		}
		if (f[mask][i] == -1 || d[i][n-1] == -1) continue;
		int cc = f[mask][i] + d[i][n-1], tt = __builtin_popcount(mask);
		if (tt > t) t = tt, mn = cc;
		else if (tt == t) mn = min(mn, cc);
	}
	printf("%d %d\n", t, mn);
}

int main() {
	int tc, cn = 0, n, m, s;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &n, &m, &s);
		for (int i=0; i<MAXN; ++i) e[i].clear();
		for (int i=0; i<s; ++i) scanf("%d", p+i);
		for (int i=0,u,v,w; i<m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			e[u].push_back(make_pair(v, w));
		}
		printf("Case %d: ", ++cn);
		gao(n, s);
	}
	return 0;
}

// 317072	2014-01-26 12:49:33	 1316 - A Wedding Party	 C++	 0.188	 3340	Accepted
