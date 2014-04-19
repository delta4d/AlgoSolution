#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;
const int INF = 0x3f3f3f3f;

#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

struct seg_tree {
	int sum[MAXN<<2], v[MAXN<<2];

	void init() {
		memset(v, 0x3f, sizeof(v));
		memset(sum, 0, sizeof(sum));
	}

	void down(int r, int L, int R) {
		if (v[r] == INF) return;
		int ls = LS(r), rs = RS(r), M = (L + R) >> 1;
		v[ls] = v[rs] = v[r];
		if (M - L + 1 > 0) sum[ls] = (M - L + 1) * v[r];
		if (R - M > 0) sum[rs] = (R - M) * v[r];
		v[r] = INF;
	}

	void up(int r) {
		sum[r] = sum[LS(r)] + sum[RS(r)];
	}

	void modify(int r, int L, int R, int a, int b, int c) {
		if (L > R) return;
		if (a <= L && R <= b) {
			v[r] = c, sum[r] = c * (R - L + 1);
			return;
		}
		down(r, L, R);
		int M = (L + R) >> 1;
		if (M >= a) modify(LS(r), L, M, a, b, c);
		if (M < b) modify(RS(r), M+1, R, a, b, c);
		up(r);
	}

	int query(int r, int L, int R, int a, int b) {
		if (L > R) return 0;
		if (a <= L && R <= b) return sum[r];
		down(r, L, R);
		int M = (L + R) >> 1, ret = 0;
		if (M >= a) ret += query(LS(r), L, M, a, b);
		if (M < b) ret += query(RS(r), M+1, R, a, b);
		return ret;
	}
} T;

int main() {
	int tc, cn = 0, n, q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &q);
		T.init();
		printf("Case %d:\n", ++cn);
		for (int op,a,b,c; q--; ) {
			scanf("%d%d%d", &op, &a, &b);
			if (op == 1) {
				scanf("%d", &c);
				T.modify(1, 0, n-1, a, b, c);
			} else {
				int sum = T.query(1, 0, n-1, a, b), tot = b - a + 1;
				int d = __gcd(sum, tot);
				sum /= d, tot /= d;
				if (tot == 1) printf("%d\n", sum);
				else printf("%d/%d\n", sum, tot);
			}
		}
	}
	return 0;
}

// 320054	2014-02-03 22:26:31	 1183 - Computing Fast Average	 C++	 0.432	 4224	Accepted
