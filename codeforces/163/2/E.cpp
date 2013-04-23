#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;
const int MOD = 1000000007;
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

int C[6][6];
int p[MAXN][6];
int s[MAXN][6];

inline int sgn(const int x) {
	return x & 1 ? -1 : 1;
}

void init() {
	for (int i=0; i<6; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j=1; j<i; ++j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	}
	p[0][0] = 1;
	for (int i=1; i<MAXN; ++i) {
		p[i][0] = 1;
		for (int j=1; j<6; ++j) p[i][j] = (long long)i * p[i][j-1] % MOD;
		for (int j=0; j<6; ++j) s[i][j] = (s[i-1][j] + p[i][j]) % MOD;
	}
}

struct seg_tree {
	int x[MAXN<<2][6];
	int v[MAXN<<2];

	void init() {
		memset(v, -1, sizeof(v));
	}

	void pushup(int r) {
		for (int i=0; i<6; ++i)	x[r][i] = (x[LS(r)][i] + x[RS(r)][i]) % MOD;
	}

	void pushdown(int r, int L, int R) {
		if (v[r] == -1) return;
		int M = (L + R) >> 1;
		v[LS(r)] = v[RS(r)] = v[r];
		for (int i=0; i<6; ++i) {
			x[LS(r)][i] = (long long)v[r] * (s[M][i] - s[L-1][i]) % MOD;
			if (x[LS(r)][i] < 0) x[LS(r)][i] += MOD;
			x[RS(r)][i] = (long long)v[r] * (s[R][i] - s[M][i]) % MOD;
			if (x[RS(r)][i] < 0) x[RS(r)][i] += MOD;
		}
		v[r] = -1;
	}

	void modify(int r, int L, int R, const int a, const int b, const int k) {
		if (a <= L && R <= b) {
			v[r] = k;
			for (int i=0; i<6; ++i) {
				x[r][i] = (long long)k * (s[R][i] - s[L-1][i]) % MOD;
				if (x[r][i] < 0) x[r][i] += MOD;
			}
			return;
		}	
		pushdown(r, L, R);
		int M = (L + R) >> 1;
		if (a <= M) modify(LS(r), L, M, a, b, k);
		if (b > M) modify(RS(r), M+1, R, a, b, k);
		pushup(r);
	}

	int query(int r, int L, int R, const int a, const int b, const int k) {
		if (a <= L && R <= b) {
			int tot = 0, off = a - 1;
			for (int j=0; j<=k; ++j) {
				int cc = (long long)C[k][j] * p[off][k-j] % MOD;
				cc = (long long)cc * x[r][j] * sgn(k-j) % MOD;
				tot = (tot + cc) % MOD;
				if (tot < 0) tot += MOD;
			}
			return tot;
		}	
		pushdown(r, L, R);
		int M = (L + R) >> 1;
		int c1 = 0, c2 = 0;
		if (a <= M) c1 = query(LS(r), L, M, a, b, k);
		if (b > M) c2 = query(RS(r), M+1, R, a, b, k);
		return (c1 + c2) % MOD;
	}

	void info(int r, int L, int R) {
		printf("%d = [%d, %d] %d\n", r, L, R, v[r]);
		for (int i=0; i<6; ++i) printf("%d ", x[r][i]); puts("");
		if (L == R) return;
		int M = (L + R) >> 1;
		info(LS(r), L, M);
		info(RS(r), M+1, R);
	} 
} T;

int main() {
	init();
	T.init();

	int n, m;
	int l, r, x;
	char op[2];

	scanf("%d%d", &n, &m);
	for (int i=1,j; i<=n; ++i) {
		scanf("%d", &j);
		T.modify(1, 1, n, i, i, j);
	}
//	T.info(1, 1, n);
	while (m--) {
		scanf("%s%d%d%d", op, &l, &r, &x);	
		if (op[0] == '=') T.modify(1, 1, n, l, r, x);
		else printf("%d\n", T.query(1, 1, n, l, r, x));
	}

	return 0;
}

// 3609937	 Apr 23, 2013 12:24:22 PM	delta_4d	 266E - More Queries to Array.. Accepted	 1375 ms	 15600 KB GNU C++
