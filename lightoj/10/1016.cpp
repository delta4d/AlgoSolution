#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 50000 + 86;

int y[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	T sgn = 1;
	while (c < '0' || c > '9') {
		c = getchar();
		if (c == '-') sgn = -1;
	}
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return sgn * a;
}

int main() {
	int tc, cn = 0, n, w;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), w = fastin<int>();
		for (int i=0; i<n; ++i) fastin<int>(), y[i] = fastin<int>();
		sort(y, y+n);
		int tot = 0;
		for (int i=0; i<n; ) {
			int k = upper_bound(y+i+1, y+n, w+y[i]) - y - 1;
			if (k < 0) break;
			i = k + 1, ++tot;
		}
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 276148	2013-10-20 22:04:33	 1016 - Brush (II)	 C++	 0.116	 1284	Accepted
