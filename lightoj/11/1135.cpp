#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

inline int LS(const int x) { return x << 1; }
inline int RS(const int x) { return LS(x) ^ 1; }

struct seg_tree {
	struct node {
		int v[3], cnt;

		void init() {
			v[0] = 1, v[1] = v[2] = cnt = 0;
		}
	} f[MAXN<<3];

	void up(int r) {
		int ls = LS(r), rs = RS(r);
		f[r].cnt = 0;
		for (int i=0; i<3; ++i) f[r].v[i] = 0;
		for (int i=0; i<3; ++i) {
			f[r].v[(i+f[ls].cnt)%3] += f[ls].v[i];
			f[r].v[(i+f[rs].cnt)%3] += f[rs].v[i];
		}
	}

	void down(int r) {
		if (!f[r].cnt) return;
		int ls = LS(r), rs = RS(r), v[3] = {0}, cnt = f[r].cnt;
		for (int i=0; i<3; ++i) v[(i+cnt)%3] = f[r].v[i];
		for (int i=0; i<3; ++i) f[r].v[i] = v[i];
		f[ls].cnt += cnt, f[rs].cnt += cnt, f[r].cnt = 0;
	}

	void init(int r, int L, int R) {
		if (L > R) return;
		if (L == R) {
			f[r].init();
			return;
		}
		int M = (L + R) >> 1;
		init(LS(r), L, M);
		init(RS(r), M+1, R);
		up(r);
	}

	void add(int r, int L, int R, int a, int b) {
		if (L > R) return;
		if (a <= L && R <= b) {
			++f[r].cnt;
			return;
		}
		down(r);
		int M = (L + R) >> 1;
		if (M >= a) add(LS(r), L, M, a, b);
		if (M < b) add(RS(r), M+1, R, a, b);
		up(r);
	}

	int sum(int r, int L, int R, int a, int b) {
		if (L > R) return 0;
		down(r);
		if (a <= L && R <= b) {
			return f[r].v[0];
		}
		int M = (L + R) >> 1, ret = 0;
		if (M >= a) ret += sum(LS(r), L, M, a, b);
		if (M < b) ret += sum(RS(r), M+1, R, a, b);
		return ret;
	}

	void info(int r, int L, int R) {
		if (L > R) return;
		printf("-- %d [%d, %d] ", r, L, R);
		for (int i=0; i<3; ++i) printf("%d ", f[r].v[i]);
		printf("%d\n", f[r].cnt);
		if (L >= R) return;
		int M = (L + R) >> 1;
		info(LS(r), L, M);
		info(RS(r), M+1, R);
	}
} T;

int main() {
	int tc, cn = 0, n, q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &q);
		T.init(1, 0, n-1);
//		T.info(1, 0, n-1);
		printf("Case %d:\n", ++cn);
		for (int op,a,b; q--; ) {
			scanf("%d%d%d", &op, &a, &b);
			if (op == 0) T.add(1, 0, n-1, a, b);
			else printf("%d\n", T.sum(1, 0, n-1, a, b));
//			T.info(1, 0, n-1);
		}
	}
	return 0;
}

// 319858	2014-02-02 23:06:12	 1135 - Count the Multiples of 3	 C++	 0.492	 13620	Accepted
