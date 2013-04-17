#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50000 + 86;

#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

struct seg_tree {
	int x[MAXN<<2];

	void init() {
		memset(x, 0, sizeof(x));
	}

	void pushdown() {
		
	}

	void pushup(int r) {
		x[r] = x[LS(r)] + x[RS(r)];	
	}

	void add(int r, int L, int R, const int k, const int off) {
		if (L == R) {
			x[r] += off;
			return;
		}	
		int M = (R + L) >> 1;
		if (k <= M) add(LS(r), L, M, k, off);
		else add(RS(r), M+1, R, k, off);
		pushup(r);
	}

	int sum(int r, int L, int R, const int a, const int b) {
		if (a <= L && R <= b) {
			return x[r];		
		}		
		int M = (L + R) >> 1, tot = 0;
		if (a <= M) tot += sum(LS(r), L, M, a, b);
		if (b > M) tot += sum(RS(r), M+1, R, a, b);
		return tot;
	}
} T;

int main() {
	int tc, cn = 0;
	int n, x;
	int l, r;
	char op[10];

	scanf("%d", &tc);
	while (tc--) {
		printf("Case %d:\n", ++cn);
		T.init();
		scanf("%d", &n);	
		for (int i=0; i<n; ++i) {
			scanf("%d", &x);
			T.add(1, 1, n, i+1, x);
		}
		while (scanf("%s", op) && op[0] != 'E') {
			scanf("%d%d", &l, &r);
			if (op[0] == 'Q') {
				printf("%d\n", T.sum(1, 1, n, l, r));	
			} else {
				if (op[0] == 'S') r = -r;	
				T.add(1, 1, n, l, r);
			}
		}
	}

	return 0;
}
