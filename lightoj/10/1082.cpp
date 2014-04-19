#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 86;
const int INF = 0x3f3f3f3f;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}
#define LS(x) ((x)<<1)
#define RS(x) (LS(x)^1)
struct seg_tree {
	int mn[N<<2];

	void init(int n=N<<2) {
		fill(mn, mn+n, INF);
	}

	void add(int r, int L, int R, int p, int v) {
		int M = (L + R) >> 1;
		mn[r] = min(mn[r], v);
		if (L >= R) return;
		if (p <= M) add(LS(r), L, M, p, v);
		else add(RS(r), M+1, R, p, v);
	}

	int query(int r, int L, int R, int a, int b) {
		if (a <= L && R <= b) return mn[r];
		int M = (L + R) >> 1, ret = INF;
		if (M >= a) ret = min(ret, query(LS(r), L, M, a, b));
		if (M < b) ret = min(ret, query(RS(r), M+1, R, a, b));
		return ret;
	}

	void info(int r, int L, int R) {
		printf("%d: [%d, %d] = %d\n", r, L, R, mn[r]);
		if (L >= R) return;
		int M = (L + R) >> 1;
		info(LS(r), L, M);
		info(RS(r), M+1, R);
	}
} T;

int main() {
	int tc, cn = 0, n, q;
	for (tc=fastin<int>(); tc--; ) {
		T.init();
		n = fastin<int>(), q = fastin<int>();
		for (int i=0; i<n; ++i) T.add(1, 0, n-1, i, fastin<int>());
//		T.info(1, 0, n-1);
		printf("Case %d:\n", ++cn);
		for (int i=0; i<q; ++i) {
			int a = fastin<int>(), b = fastin<int>();
			printf("%d\n", T.query(1, 0, n-1, a-1, b-1));
		}
	}
	return 0;
}

// 293426	2013-11-30 19:42:02	 1082 - Array Queries	 C++	 0.408	 2668	Accepted
