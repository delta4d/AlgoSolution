#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;
#define LS(x) ((x) << 1)
#define RS(x) (LS(x) ^ 1)
#define MID(L, R) (((L) + (R)) >> 1)

struct seg_tree {
	struct node {
		bool dirty, mix;
		int type;	
		node(bool _dirty=false, bool _mix=false, int _type=0):dirty(_dirty), type(_type) {}
		void init(int _type, bool _dirty=false, bool _mix=false) { dirty = _dirty, type = _type, mix = _mix; }
		void update(int _type) { dirty = true, mix = false, type = _type; }
	} x[MAXN<<2];	

	void init(int r, int L, int R) {
		x[r].init(1);
		if (L == R) return;
		int M = MID(L, R);
		init(LS(r), L, M);
		init(RS(r), M+1, R);
	}

	void pushdown(int r) {
		x[r].dirty = false, x[r].mix = false;
		x[LS(r)].update(x[r].type);
		x[RS(r)].update(x[r].type);
	}

	void pushup(int r) {
		if (!x[LS(r)].mix && !x[RS(r)].mix && x[LS(r)].type == x[RS(r)].type) x[r].mix = false, x[r].type = x[LS(r)].type;
		else x[r].mix = true;
	}

	void update(int r, int L, int R, const int a, const int b, const int v) {
		if (a <= L && R <= b) {
			x[r].update(v);	
			return;
		}	
		if (x[r].dirty) pushdown(r);
		int M = MID(L, R);
		if (a <= M) update(LS(r), L, M, a, b, v);
		if (b > M) update(RS(r), M+1, R, a, b, v);
		pushup(r);
	}

	int query(int r, int L, int R, const int a, const int b) {
		if (!x[r].mix && a <= L && R <= b) {
			return x[r].type * (R - L + 1);
		}	
		if (x[r].dirty) pushdown(r);
		int M = MID(L, R), tot = 0;
		if (a <= M) tot += query(LS(r), L, M, a, b);
		if (b > M) tot += query(RS(r), M+1, R, a, b);
		return tot;
	}
} T;

int main() {
	int tc, cn = 0;
	int n, q;
	int x, y, z;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &q);
		T.init(1, 1, n);
		while (q--) {
			scanf("%d%d%d", &x, &y, &z);
			T.update(1, 1, n, x, y, z);
		}
		printf("Case %d: The total value of the hook is %d.\n", ++cn, T.query(1, 1, n, 1, n));
	}

	return 0;
}
