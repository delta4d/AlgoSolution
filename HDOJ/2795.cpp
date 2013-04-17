#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 86;
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)

struct seg_tree {
	int x[MAXN<<2];

	void init(const int n, const int v) {
		fill(x, x+(n<<2), v);
	}

	void pushup(int r) {
		x[r] = max(x[LS(r)], x[RS(r)]);
	}

	int query(int r, int L, int R, const int w) {
		if (L == R) {
			if (x[r] < w) return -1;
			x[r] -= w;
			return L;
		}	
		int M = (L + R) >> 1, ret = -1;	
		if (x[LS(r)] >= w) ret = query(LS(r), L, M, w);
		else if (x[RS(r)] >= w) ret = query(RS(r), M+1, R, w);
		pushup(r);
		return ret;
	}
} T;

int main() {
	int h, w, n;
	int t;

	while (3 == scanf("%d%d%d", &h, &w, &n)) {
		t = min(n, h);
		T.init(t, w);
		while (n--) {
			scanf("%d", &w);	
			printf("%d\n", T.query(1, 1, t, w));
		}
	}

	return 0;
}
