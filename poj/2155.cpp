#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

inline int lowbit(const int x) {
	return x & -x;
}

struct BIT2 {
	int m, n;
	int a[MAXN][MAXN];

	void init(int _m=MAXN, int _n=MAXN) {
		m = _m, n = _n;
		memset(a, 0, sizeof(a));
	}
	void add(int x, int y, const int off) {
		for (int i=x; i<=m; i+=lowbit(i)) for (int j=y; j<=n; j+=lowbit(j)) a[i][j] += off;
	}
	int sum(int x, int y) {
		int tot = 0;	
		for (int i=x; i>0; i-=lowbit(i)) for (int j=y; j>0; j-=lowbit(j)) tot += a[i][j];
		return tot;
	}
	// x1 <= x2, y1 <= y2
	void add_rectangle(int x1, int y1, int x2, int y2, const int off) {
		add(x1, y1, off);
		add(x1, y2+1, off);
		add(x2+1, y1, off);
		add(x2+1, y2+1, off);
	}
} T;

int main() {
	int tc;
	int n, q;
	int x, y;
	int x1, y1, x2, y2;
	char op[2];

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &q);
		T.init(n+10, n+10);	
		while (q--) {
			scanf("%s", op);
			if (op[0] == 'C') {
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);	
				T.add_rectangle(x1, y1, x2, y2, 1);
			} else {
				scanf("%d%d", &x, &y);	
				printf("%d\n", T.sum(x,y)&1);
			}
		}
		if (tc) puts("");
	}

	return 0;
}
