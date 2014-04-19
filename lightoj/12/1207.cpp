#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 86;
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

bool v[MAXN];

struct seg_tree {
	int color[MAXN<<2];

	void init() {
		memset(color, -1, sizeof(color));
		memset(v, false, sizeof(v));
	}

	void down(int r) {
		if (color[r] == -1) return;
		color[LS(r)] = color[RS(r)] = color[r];
		color[r] = -1;
	}

	void modify(int r, int L, int R, int a, int b, int c) {
		if (L > R) return;
		if (a <= L && R <= b) {
			color[r] = c;
			return;
		}
		down(r);
		int M = (L + R) >> 1;
		if (M >= a) modify(LS(r), L, M, a, b, c);
		if (M < b) modify(RS(r), M+1, R, a, b, c);
	}

	void query(int r, int L, int R) {
		if (L > R) return;
		if (L == R) {
			if (color[r] != -1) v[color[r]] = true;
			return;
		}
		down(r);
		int M = (L + R) >> 1;
		query(LS(r), L, M);
		query(RS(r), M+1, R);
	}
} T;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		T.init();
		for (int a,b,i=0; i<n; ++i) {
			scanf("%d%d", &a, &b);
			T.modify(1, 0, 2*n, a, b, i);
		}
		T.query(1, 0, 2*n);
		int tot = 0;
		for (int i=0; i<n; ++i) tot += v[i];
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 320102	2014-02-04 00:21:46	 1207 - Posters for Election	 C++	 0.440	 4412	Accepted
