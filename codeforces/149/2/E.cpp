#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 400000 + 86;
const int B = 20;

#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

struct seg_tree {
	int f[MAXN][B], e[MAXN];

	void read(int r, int L, int R) {
		if (L == R) {
			int x;
			scanf("%d", &x);
			for (int i=0; i<B; ++i) if (x & 1 << i) f[r][i] = 1;
			return;
		}
		int M = (L + R) >> 1;
		read(LS(r), L, M);
		read(RS(r), M+1, R);
		for (int i=0; i<B; ++i) f[r][i] = f[LS(r)][i] + f[RS(r)][i];
	}

	void pushdown(int r, int L, int R) {
		if (!e[r]) return;
		int ls = LS(r), rs = RS(r), M = (L + R) >> 1;
		for (int i=0; i<B; ++i) if (e[r] & 1 << i) f[ls][i] = M - L + 1 - f[ls][i];
		for (int i=0; i<B; ++i) if (e[r] & 1 << i) f[rs][i] = R - M - f[rs][i];
		e[ls] ^= e[r], e[rs] ^= e[r], e[r] = 0;
	}

	void pushup(int r) {
		int ls = LS(r), rs = RS(r);
		for (int i=0; i<B; ++i) f[r][i] = f[ls][i] + f[rs][i];
	}

	void xx(int r, int L, int R, const int a, const int b, const int x) {
		if (a <= L && R <= b) {
			for (int i=0; i<B; ++i) if (x & 1 << i) f[r][i] = R - L + 1 - f[r][i]; 
			e[r] ^= x;
			return;
		}
		pushdown(r, L, R);
		int M = (L + R) >> 1;
		if (M >= a) xx(LS(r), L, M, a, b, x);
		if (M < b) xx(RS(r), M+1, R, a, b, x);
		pushup(r);
	}

	LL sum(int r, int L, int R, const int a, const int b) {
		if (a <= L && R <= b) {
			LL tot = 0;
			for (int i=0; i<B; ++i) tot += (LL)(1 << i) * f[r][i];
			return tot;
		}
		pushdown(r, L, R);
		LL ret = 0;
		int M = (L + R) >> 1;
		if (M >= a) ret += sum(LS(r), L, M, a, b);
		if (M < b) ret += sum(RS(r), M+1, R, a, b);
		pushup(r);
		return ret;
	}
} T;

int main() {
	int n, m;

	scanf("%d", &n);
	T.read(1, 0, n-1);
	scanf("%d", &m);
	for (int i=0,t,a,b,x; i<m; ++i) {
		scanf("%d%d%d", &t, &a, &b), --a, --b;
		if (t == 2) scanf("%d", &x);
		if (t == 1) printf("%I64d\n", T.sum(1, 0, n-1, a, b));
		else T.xx(1, 0, n-1, a, b, x);
	}

	return 0;
}

// 3999478	 Jul 1, 2013 4:19:59 PM	delta_4d	 E - XOR on Segment	 GNU C++	Accepted	 484 ms	 32900 KB
