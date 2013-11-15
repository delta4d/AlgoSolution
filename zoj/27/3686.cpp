#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

struct node {
	bool dirty;
	int tot, cnt;
	node(bool _dirty=false, int _tot=0, int _cnt=0):dirty(_dirty), tot(_tot), cnt(_cnt) {}
	void init(int _tot=0) { tot = _tot, dirty = false, cnt = 0; }
	void neg() { dirty = !dirty, cnt = tot - cnt; }
} T[MAXN<<2];
vector <int> p[MAXN];
int l[MAXN], r[MAXN];
int t;

void dfs(int x) {
	l[x] = t;	
	for (int i=0; i<p[x].size(); ++i) {
		++t;
		dfs(p[x][i]);
	}
	r[x] = t;
}

void init(int x, int L, int R) {
	T[x].init(R-L+1);
	if (L == R) return;
	int M = (L + R) >> 1;
	init(LS(x), L, M);
	init(RS(x), M+1, R);
}

void neg(int x, int L, int R, const int l, const int r) {
	if (l <= L && R <= r) {
		T[x].neg();
		return;
	}	
	int M = (L + R) >> 1;
	if (T[x].dirty) {
		T[x].dirty = false;
		T[LS(x)].neg();
		T[RS(x)].neg();
	}
	if (l <= M) neg(LS(x), L, M, l, r);
	if (r > M) neg(RS(x), M+1, R, l, r);
	T[x].cnt = T[LS(x)].cnt + T[RS(x)].cnt;
}

int query(int x, int L, int R, const int l, const int r) {
	if (l <= L && R <= r) return T[x].cnt;	
	int M = (L + R) >> 1;
	if (T[x].dirty) {
		T[x].dirty = false;
		T[LS(x)].neg();
		T[RS(x)].neg();
	}
	int tot = 0;
	if (l <= M) tot += query(LS(x), L, M, l, r);
	if (r > M) tot += query(RS(x), M+1, R, l, r);
	T[x].cnt = T[LS(x)].cnt + T[RS(x)].cnt;
	return tot;
}

int main() {
	int n, m;
	int x;
	char op[2];

	while (2 == scanf("%d%d", &n, &m)) {
		for (int i=0; i<n; ++i) p[i].clear();
		for (int i=1; i<n; ++i) {
			scanf("%d", &x);
			p[x-1].push_back(i);
		}
		dfs(t=0);
		init(1, l[0], r[0]);
		while (m--) {
			scanf("%s%d", op, &x), --x;	
			if (op[0] == 'o') neg(1, l[0], r[0], l[x], r[x]);
			else printf("%d\n", query(1, l[0], r[0], l[x], r[x]));
		}
		puts("");
	}

	return 0;
}
