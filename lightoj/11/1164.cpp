#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

struct seg_tree {
	long long sum[MAXN<<2], add[MAXN<<2];

	void init() {
		memset(sum, 0, sizeof(sum));
		memset(add, 0, sizeof(add));
	}

	void down(int r, int L, int R) {
		if (!add[r]) return;
		int ls = LS(r), rs = RS(r), M = (L + R) >> 1;
		add[ls] += add[r], add[rs] += add[r];
		if (M - L + 1 > 0) sum[ls] += add[r] * (M - L + 1);
		if (R - M > 0) sum[rs] += add[r] * (R - M);
		add[r] = 0;
	}

	void up(int r) {
		sum[r] = sum[LS(r)] + sum[RS(r)];
	}

	void modify(int r, int L, int R, int a, int b, int c) {
		if (L > R) return;
		if (a <= L && R <= b) {
			add[r] += c, sum[r] += 1ll * c * (R - L + 1);
			return;
		}
		down(r, L, R);
		int M = (L + R) >> 1;
		if (M >= a) modify(LS(r), L, M, a, b, c);
		if (M < b) modify(RS(r), M+1, R, a, b, c);
		up(r);
	}

	long long query(int r, int L, int R, int a, int b) {
		if (L > R) return 0;
		if (a <= L && R <= b) return sum[r];
		down(r, L, R);
		long long ret = 0;
		int M = (L + R) >> 1;
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
		for (int op,x,y,v; q--; ) {
			scanf("%d%d%d", &op, &x, &y);
			if (op == 0) scanf("%d", &v);
			if (op == 0) T.modify(1, 0, n-1, x, y, v);
			else printf("%lld\n", T.query(1, 0, n-1, x, y));
		}
	}
	return 0;
}

// 320037	2014-02-03 21:34:38	 1164 - Horrible Queries	 C++	 0.388	 7352	Accepted
