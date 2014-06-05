#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

using ll = long long;
int const N = 1e5 + 10;

ll v[N];
struct seg_tree {
	ll mx[N<<2], sum[N<<2];

	seg_tree() {
		memset(mx, -1, sizeof(mx));
	}

	void up(int r, int ls, int rs) {
		mx[r] = mx[ls] == -1 ? mx[rs] : (v[mx[ls]] > v[mx[rs]] ? mx[ls] : mx[rs]);
		sum[r] = sum[ls] + sum[rs];
	}

	void readin(int r, int L, int R) {
		if (L > R) return;
		if (L == R) {
			scanf("%I64d", v+L);
			mx[r] = L, sum[r] = v[L];
			return;
		}
		int M = (L + R) >> 1, ls = r << 1, rs = ls ^ 1;
		readin(ls, L, M), readin(rs, M+1, R);
		up(r, ls, rs);
	}

	int query_max(int r, int L, int R, int a, int b) {
		if (a <= L && R <= b) return mx[r];
		int M = (L + R) >> 1, ls = r << 1, rs = ls ^ 1, r1 = -1, r2 = -1;
		if (M >= a) r1 = query_max(ls, L, M, a, b);
		if (M < b) r2 = query_max(rs, M+1, R, a, b);
		return r1 == -1 ? r2 : (v[r1] > v[r2] ? r1 : r2);
	}

	ll query_sum(int r, int L, int R, int a, int b) {
		if (a <= L && R <= b) return sum[r];
		int M = (L + R) >> 1, ls = r << 1, rs = ls ^ 1;
		ll ret = 0;
		if (M >= a) ret += query_sum(ls, L, M, a, b);
		if (M < b) ret += query_sum(rs, M+1, R, a, b);
		return ret;
	}

	void modify(int r, int L, int R, int p, ll x) {
		if (p < L || p > R || L > R) return;
		if (L == R) {
			v[p] = x, mx[r] = p, sum[r] = x;
			return;
		}
		int M = (L + R) >> 1, ls = r << 1, rs = ls ^ 1;
		if (p <= M) modify(ls, L, M, p, x);
		else modify(rs, M+1, R, p, x);
		up(r, ls, rs);
	}
} T;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	T.readin(1, 1, n);
	for (int op,l,r,x,p; m--; ) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &l, &r);
			printf("%I64d\n", T.query_sum(1, 1, n, l, r));
		} else if (op == 2) {
			scanf("%d%d%d", &l, &r, &x);
			while (true) {
				ll idx = T.query_max(1, 1, n, l, r);
				if (v[idx] < x) break;
				T.modify(1, 1, n, idx, v[idx]%x);
			}
		} else {
			scanf("%d%d", &p, &x);
			T.modify(1, 1, n, p, x);
		}
	}
	return 0;
}

// 6782917	 2014-06-02 19:55:51	delta_4d	 D - The Child and Sequence	 GNU C++0x	Accepted	 1076 ms	 7000 KB
