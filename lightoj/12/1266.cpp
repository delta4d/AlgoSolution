#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 86;

inline int lowbit(const int x) {
	return x & -x;
}

struct BIT2 {
	int m, n;
	int a[MAXN+10][MAXN+10];

	void init(int _m=MAXN, int _n=MAXN) {
		m = _m, n = _n;
		memset(a, 0, sizeof(a));
	}

	void add(int x, int y, const int off) {
		for (int i=x; i<=m; i+=lowbit(i)) {
			for (int j=y; j<=n; j+=lowbit(j)) a[i][j] += off;
		}
	}

	// x1 <= x2, y1 <= y2
	void add_rectangle(int x1, int y1, int x2, int y2, const int off) {
		add(x1, y1, off);
		add(x1, y2+1, off);
		add(x2+1, y1, off);
		add(x2+1, y2+1, off);
	}

	int sum(int x, int y) {
		int tot = 0;	
		for (int i=x; i>0; i-=lowbit(i)) {
			for (int j=y; j>0; j-=lowbit(j)) tot += a[i][j];
		}
		return tot;
	}
} T;

bool v[MAXN][MAXN];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, q, x, y, x1, y1, x2, y2, op;
	for (tc=fastin<int>(); tc--; ) {
		q = fastin<int>();
		T.init();
		memset(v, false, sizeof(v));
		printf("Case %d:\n", ++cn);
		while (q--) {
			scanf("%d", &op);
			if (op == 0) {
				x = fastin<int>() + 1, y = fastin<int>() + 1;
				if (!v[x][y]) {
					v[x][y] = true;
					T.add(x, y, 1);
				}
			} else {
				x1 = fastin<int>() + 1, y1 = fastin<int>() + 1;
				x2 = fastin<int>() + 1, y2 = fastin<int>() + 1;
				printf("%d\n", T.sum(x2, y2)-T.sum(x2, y1-1)-T.sum(x1-1, y2)+T.sum(x1-1,y1-1));
			}
		}
	}
	return 0;
}

// 259347	2013-09-03 23:38:11	 1266 - Points in Rectangle	 C++	 0.396	 6932	Accepted
