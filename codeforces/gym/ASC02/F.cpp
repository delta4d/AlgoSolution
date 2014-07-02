#include <bits/stdc++.h>
using namespace std;

int const N = 400;
int const INF = 0x3f3f3f3f;

struct edge {
	int a, b, c;
};
vector <edge> e;
vector <int> ed[N];
int dep[N], pre[N], eid[N][N];
int lx[N], ly[N], mx[N], my[N], w[N][N], d;
bool vx[N], vy[N];

void dfs(int r, int p=-1) {
	pre[r] = p;
	for (auto c: ed[r]) {
		if (c == p) continue;
		dep[c] = dep[r] + 1;
		dfs(c, r);
	}
}

bool argu(int x, int const n) {
	vx[x] = true;
	for (int y=0; y<n; ++y) if (!vy[y]) {
		if (lx[x] + ly[y] == w[x][y]) {
			vy[y] = true;
			if (my[y] == -1 || argu(my[y], n)) {
				mx[x] = y, my[y] = x;
				return true;
			}
		} else {
			d = min(d, lx[x]+ly[y]-w[x][y]);
		}
	}
	return false;
}

void KM(int const m, int const n) {
	for (int i=0; i<m; ++i) {
		lx[i] = -INF;
		for (int j=0; j<n; ++j) lx[i] = max(lx[i], w[i][j]);
	}
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	for (int k=0; k<m; ++k) {
		memset(vx, false, sizeof(vx));
		memset(vy, false, sizeof(vy));
		d = INF;
		if (argu(k, n)) continue;
		for (int i=0; i<m; ++i) if (vx[i]) lx[i] -= d;
		for (int i=0; i<n; ++i) if (vy[i]) ly[i] += d;
		--k;
	}
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("roads.in", "r", stdin);
	freopen("roads.out", "w", stdout);
#endif
	int m, n;
	scanf("%d%d", &n, &m);
	for (int i=0,a,b,c; i<m; ++i) {
		scanf("%d%d%d", &a, &b, &c), --a, --b;
		eid[a][b] = eid[b][a] = i;
		e.push_back({a, b, c});
		if (i <= n - 2) ed[a].push_back(b), ed[b].push_back(a);
	}
	int nx = n - 1, ny = m - nx;
	bool swaped = false;
	if (nx > ny) swap(nx, ny), swaped = true;
	int root = e.front().a;
	dfs(root);
	for (int i=n-1; i<m; ++i) {
		int a = e[i].a, b = e[i].b, c = e[i].c, k;
		for (int pa=a,pb=b; pa!=pb; ) {
			if (dep[pa] > dep[pb]) {
				k = eid[pa][pre[pa]];
				pa = pre[pa];
			} else {
				k = eid[pb][pre[pb]];
				pb = pre[pb];
			}
			if (swaped) w[i-n+1][k] = -c + e[k].c;
			else w[k][i-n+1] = -c + e[k].c;
		}
	}
	KM(nx, ny);
	int out[N];
	for (int i=0; i<nx; ++i) {
		if (swaped) out[i+n-1] = e[i+n-1].c + lx[i];
		else out[i] = e[i].c - lx[i];
	}
	for (int i=0; i<ny; ++i) {
		if (swaped) out[i] = e[i].c - ly[i];
		else out[i+n-1] = e[i+n-1].c + ly[i];
	}
	for (int i=0; i<m; ++i) printf("%d\n", out[i]);
	return 0;
}

// 6995306	 2014-07-02 09:19:16	delta_4d	 F - Roads	 GNU C++0x	Accepted	30 ms	1592 KB
