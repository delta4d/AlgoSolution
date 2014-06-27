#include <bits/stdc++.h>
using namespace std;

int const N = 1 << 8;
int const M = N * N;
int const INF = 0x3f3f3f3f;
struct Flow {
	int s, t, n;
	int flow[N][N];
	int pre[N];
	bool v[N];

	Flow(int f[][N], int s, int t, int n):s(s), t(t), n(n) {
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
			flow[i][j] = f[i][j];
		}
	}
	bool arg_path() {
		memset(v, false, sizeof(v));
		queue <int> q;
		q.push(s); v[s] = true;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			if (x == t) return true;
			for (int y=0; y<n; ++y) if (!v[y] && flow[x][y]) {
				q.push(y);
				v[y] = true, pre[y] = x;
			}
		}
		return false;
	}
	bool run() {
		while (true) {
			if (!arg_path()) break;
			int mn = INF;
			for (int i=t; i!=s; i=pre[i]) mn = min(mn, flow[pre[i]][i]);
			for (int i=t; i!=s; i=pre[i]) {
				int j = pre[i];
				flow[j][i] -= mn, flow[i][j] += mn;
			}
		}
		for (int i=0; i<n; ++i) if (flow[s][i]) return false;
		for (int i=0; i<n; ++i) if (flow[i][t]) return false;
		return true;
	}
};
int d[N], mat[N][N], id[N][N];
int a[M], b[M], l[M], r[M], out[M];

int main() {
#ifdef ONLINE_JUDGE
	freopen("cooling.in", "r", stdin);
	freopen("cooling.out", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	memset(id, -1, sizeof(id));
	for (int i=0; i<m; ++i) {
		scanf("%d%d%d%d", a+i, b+i, l+i, r+i), --a[i], --b[i];
		d[a[i]] -= l[i], d[b[i]] += l[i];
		mat[a[i]][b[i]] = r[i] - l[i], id[a[i]][b[i]] = i;
	}
	for (int i=0; i<n; ++i) {
		if (d[i] < 0) mat[i][n+1] = -d[i];
		else if (d[i] > 0) mat[n][i] = d[i];
	}
	Flow f(mat, n, n+1, n+2);
	if (!f.run()) return puts("NO"), 0;
	puts("YES");
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (id[i][j] != -1) {
		out[id[i][j]] = f.flow[j][i] + l[id[i][j]];
	}
	for (int i=0; i<m; ++i) printf("%d\n", out[i]);
	return 0;
}

// 6968308	 2014-06-27 12:52:56	delta_4d	 B - Reactor Cooling	 GNU C++0x	Accepted	312 ms	2368 KB
