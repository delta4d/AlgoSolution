#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 86;
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

struct seg_tree {
	struct node {
		int left, ln;
		int right, rn;
		int mx;
		node(int _left=0, int _ln=0, int _right=0, int _rn=0, int _mx=0):
			left(_left), ln(_ln), right(_right), rn(_rn), mx(_mx) {}
		void init() { left = ln = right = rn = mx = 0; }
		void init(int _left, int _ln, int _right, int _rn, int _mx) {
			left = _left, ln = _ln;
			right = _right, rn = _rn;
			mx = _mx;
		}
	} f[MAXN<<2];

	node up(node &a, node &b) {
		if (a.left == 0) return b;
		if (b.left == 0) return a;
		int left = a.left, ln = a.ln, right = b.right, rn = b.rn, mx = max(a.mx, b.mx);
		if (a.right == b.left) mx = max(mx, a.rn + b.ln);
		if (a.left == b.left) ln += b.ln;
		if (a.right == b.right) rn += a.rn;
		mx = max(mx, max(ln, rn));
		return node(left, ln, right, rn, mx);
	}

	void init(int r, int L, int R) {
		f[r].init();
		if (L == R) {
			int x;
			scanf("%d", &x);
			f[r].init(x, 1, x, 1, 1);
			return;
		}
		int M = (L + R) >> 1;
		init(LS(r), L, M);
		init(RS(r), M+1, R);
		f[r] = up(f[LS(r)], f[RS(r)]);
	}

	node query(int r, int L, int R, int a, int b) {
		if (L > R) return node();
		if (a <= L && R <= b) return f[r];
		int M = (L + R) >> 1;
		node ll, rr;
		if (M >= a) ll = query(LS(r), L, M, a, b);
		if (M < b) rr = query(RS(r), M+1, R, a, b);
		return up(ll, rr);
	}
} T;

int main() {
	int tc, cn = 0, n, c, q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &n, &c, &q);
		printf("Case %d:\n", ++cn);
		T.init(1, 1, n);
		for (int a, b; q--; ) {
			scanf("%d%d", &a, &b);
			printf("%d\n", T.query(1, 1, n, a, b).mx);
		}
	}
	return 0;
}

// 320261	2014-02-04 11:55:34	 1339 - Strongest Community	 C++	 0.424	 8920	Accepted
