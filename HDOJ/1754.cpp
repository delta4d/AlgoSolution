#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 86;
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

struct seg_stree {
	int x[MAXN<<2];

	void init() {
		memset(x, 0, sizeof(x));
	}

	void pushdown(int r) {
		
	}

	void pushup(int r) {
		x[r] = max(x[LS(r)], x[RS(r)]);	
	}

	void modify(int r, int L, int R, const int p, const int v) {
		if (L == R) {
			x[r] = v;
			return;
		}	
		int M = (L + R) >> 1;
		if (p <= M) modify(LS(r), L, M, p, v);
		else modify(RS(r), M+1, R, p, v);
		pushup(r);
	}

	int query(int r, int L, int R, const int a, const int b) {
		if (a <= L && R <= b) {
			return x[r];
		}	
		int M = (L + R) >> 1;
		int mx = 0;
		if (a <= M) mx = max(mx, query(LS(r), L, M, a, b));
		if (b > M) mx = max(mx, query(RS(r), M+1, R, a, b));
		return mx;
	}
} T;

int main() {
	int n, m;
	int a, b;
	char op[2];

	while (2 == scanf("%d%d", &n, &m)) {
		T.init();
		for (int i=1; i<=n; ++i) {
			scanf("%d", &a);
			T.modify(1, 1, n, i, a);
		}
		while (m--) {
			scanf("%s%d%d", op, &a, &b);
			if (op[0] == 'Q') {
				printf("%d\n", T.query(1, 1, n, a, b));	
			} else {
				T.modify(1, 1, n, a, b);	
			}
		}
	}

	return 0;
}
