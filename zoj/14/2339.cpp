#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL MAXN = 500001;

struct node {
	int idx;
	LL val;
	node() {}
	node(int _idx, LL _val):idx(_idx), val(_val) {}
};

int p[MAXN], d[MAXN], f[MAXN<<1][2], root;
priority_queue<node> q;

inline bool operator<(node a, node b) {
	return a.val > b.val;
}

void build_tree(const int n) {
	int i, j, k;
	int r1, r2;
	LL v1, v2;
	int tt;

	memset(f, -1, sizeof(f));
	root = n;
	while (true) {
		r1 = q.top().idx;
		v1 = q.top().val;
		q.pop();
		if (q.empty()) break;
		r2 = q.top().idx;
		v2 = q.top().val;
		q.pop();
		f[root][0] = r1, f[root][1] = r2;
		q.push(node(root, v1+v2));
		++root;
	}
	--root;
}

void calc_depth(LL r, int depth, const int n) {
	LL i, j, k;
	for (i=0; i<2; ++i) {
		if (f[r][i] != -1) {
			calc_depth(f[r][i], depth+1, n);
		} else {
			d[r] = depth;
		}
	}
}

LL gao(const int n) {
	LL i, j, k;
	LL sum(0);
	for (i=0; i<n; ++i) sum += d[i] * p[i];
	return sum;
}

int main() {
	int i, j, k;
	int m, n;
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		while (!q.empty()) q.pop();
		for (i=0; i<n; ++i) {
			scanf("%d", p+i);
			q.push(node(i, LL(p[i])));
		}
		build_tree(n);
		calc_depth(root, 0, n);
		printf("%lld\n", gao(n));
		//for (i=0; i<n; ++i) printf("dd %d ", d[i]); puts("");
		//for (i=n; i<=root; ++i) printf("%d-L%d-R%d  ", i, f[i][0], f[i][1];
		if (tc) puts("");
	}
	return 0;
}
