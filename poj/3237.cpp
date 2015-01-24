#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int const N = 1e4 + 10;
int const INF = 0x3f3f3f3f;

struct SegmentTree {
	int mn[N<<2], mx[N<<2], sgn[N<<2];
	void init() {
		memset(mn, 0, sizeof(mn));
		memset(mx, 0, sizeof(mx));
		memset(sgn, 0, sizeof(sgn));
	}
	void upd(int r) {
		sgn[r] ^= 1;
		swap(mn[r], mx[r]);
		mn[r] = -mn[r], mx[r] = -mx[r];
	}
	void up(int r) {
		mn[r] = min(mn[r<<1], mn[r<<1|1]);
		mx[r] = max(mx[r<<1], mx[r<<1|1]);
	}
	void down(int r) {
		if (!sgn[r]) return;
		upd(r<<1), upd(r<<1|1);
		sgn[r] = 0;
	}
	void modify(int r, int L, int R, int p, int x) {
		if (R < p || L > p) return;
		if (L == R) {
			mn[r] = mx[r] = x;
			sgn[r] = 0;
		} else {
			int M = L + (R - L) / 2, ls = r << 1, rs = ls | 1;
			down(r);
			modify(ls, L, M, p, x);
			modify(rs, M+1, R, p, x);
			up(r);
		}
	}
	void negates(int r, int L, int R, int a, int b) {
		if (R < a || L > b || a > b) return;
		if (a <= L && R <= b) {
			upd(r);
		} else {
			int M = L + (R - L) / 2, ls = r << 1, rs = ls | 1;
			down(r);
			negates(ls, L, M, a, b);
			negates(rs, M+1, R, a, b);
			up(r);
		}
	}
	int query(int r, int L, int R, int a, int b) {
		if (R < a || L > b || a > b) return -INF;
		if (a <= L && R <= b) return mx[r];
		down(r);
		int M = L + (R - L) / 2, ls = r << 1, rs = ls | 1;
		return max(query(ls, L, M, a, b), query(rs, M+1, R, a, b));
	}
} T;

vector <int> e[N];
int u[N], v[N], w[N], eid[N];
int fa[N], dep[N], sz[N], hson[N], id[N], tp[N];
int num, n, q;
char op[20];

void dfs(int x, int p, int d) {
	dep[x] = d, fa[x] = p, sz[x] = 1, hson[x] = -1;
	for (int i=0; i<(int)e[x].size(); ++i) {
		int y = e[x][i];
		if (y == p) continue;
		dfs(y, x, d+1);
		sz[x] += sz[y];
		if (hson[x] == -1 || sz[hson[x]] < sz[y]) hson[x] = y;
	}
}

void dfs(int x, int p) {
	tp[x] = p;
	if (x) id[x] = num++;
	if (hson[x] != -1) dfs(hson[x], p);
	for (int i=0; i<(int)e[x].size(); ++i) {
		int y = e[x][i];
		if (y == fa[x] || y == hson[x]) continue;
		dfs(y, y);
	}
}

int query(int a, int b) {
	int ta = tp[a], tb = tp[b], ret = -INF;
	while (ta != tb) {
		if (dep[ta] < dep[tb]) swap(ta, tb), swap(a, b);
		ret = max(ret, T.query(1, 0, n-2, id[ta], id[a]));
		a = fa[ta], ta = tp[a];
	}
	if (dep[a] > dep[b]) swap(a, b);
	if (a != b) ret = max(ret, T.query(1, 0, n-2, id[hson[a]], id[b]));
	return ret;
}

void negates(int a, int b) {
	int ta = tp[a], tb = tp[b];
	while (ta != tb) {
		if (dep[ta] < dep[tb]) swap(ta, tb), swap(a, b);
		T.negates(1, 0, n-2, id[ta], id[a]);
		a = fa[ta], ta = tp[a];
	}
	if (dep[a] > dep[b]) swap(a, b);
	if (a != b) T.negates(1, 0, n-2, id[hson[a]], id[b]);
}

int main() {
	int tc;
	for (scanf("%d", &tc); tc--; ) {
		T.init(), num = 0;
		for (int i=0; i<N; ++i) e[i].clear();
		scanf("%d", &n);
		for (int i=0; i+1<n; ++i) {
			scanf("%d%d%d", u+i, v+i, w+i);
			--u[i], --v[i];
			e[u[i]].push_back(v[i]);
			e[v[i]].push_back(u[i]);
		}
		dfs(0, -1, 0);
		dfs(0, 0);
		for (int i=0; i+1<n; ++i) {
			if (dep[u[i]] < dep[v[i]]) eid[i] = v[i];
			else eid[i] = u[i];
		}
		for (int i=0; i+1<n; ++i) T.modify(1, 0, n-2, id[eid[i]], w[i]);
		for (int a,b; ; ) {
			scanf("%s", op);
			if (op[0] == 'D') break;
			scanf("%d%d", &a, &b);
			if (op[0] == 'Q') printf("%d\n", query(a-1, b-1));
			else if (op[0] == 'C') T.modify(1, 0, n-2, id[eid[a-1]], b);
			else negates(a-1, b-1);
		}
	}
	return 0;
}

// 13812188	delta_4d	3237	Accepted	2648K	844MS	G++	3542B	2015-01-25 00:02:22
