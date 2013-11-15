#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50000 + 86;

inline int lowbit(const int x) {
	return x & -x;
}

template <class T>
struct BIT {
	int n;
	T x[MAXN + 1];

	void init(int _n=MAXN) {
		n = _n;
		memset(x, 0, sizeof(x));
	}
	void add(int p, T off) {
		for (; p<=n; p+=lowbit(p)) x[p] += off;
	}
	void add_interval(int l, int r, T off) {
		add(l, off);
		add(r+1, -off);
	}
	T sum(int p) {
		T tot = 0;
		for (; p>=1; p-=lowbit(p)) tot += x[p];
		return tot;
	}
};

BIT <int> T;

int main() {
	int tc, cn = 0;
	char op[10];
	int n;
	int x, y;
	
	scanf("%d", &tc);
	while (tc--) {
		printf("Case %d:\n", ++cn);
		scanf("%d", &n);
		T.init(n+10);
		for (int i=0; i<n; ++i) {
			scanf("%d", &x);
			T.add(i+1, x);
		}
		while (scanf("%s", op) && op[0] != 'E') {
			scanf("%d%d", &x, &y);
			if (op[0] == 'Q') printf("%d\n", T.sum(y)-T.sum(x-1));
			else if (op[0] == 'A') T.add(x, y);
			else T.add(x, -y);
		}
	}
	return 0;
}
