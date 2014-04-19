#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10000 + 86;

int x[N], y[N];

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

inline int lat(int x1, int y1, int x2, int y2) {
	int x = abs(x2 - x1), y = abs(y2 - y1);
	if (x > y) swap(x, y);
	if (x == 0) return y + 1;
	return __gcd(x, y) + 1;
}

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) x[i] = fastin<int>(), y[i] = fastin<int>();
		for (int i=1; i<n; ++i) x[i] -= x[0], y[i] -= y[0]; x[0] = y[0] = 0;
		double s = 0;
		for (int i=1; i+1<n; ++i) s += 1.0 * x[i] * y[i+1] - 1.0 * y[i] * x[i+1];
		s = fabs(s) / 2;
		double cc = 0;
		for (int i=0; i<n; ++i) cc += lat(x[i], y[i], x[i==n-1?0:i+1], y[i==n-1?0:i+1]);
		cc -= n;
		long long t = rint(s + 1 - cc / 2);
		printf("Case %d: %lld\n", ++cn, t);
	}
	return 0;
}

// 260671	2013-09-09 10:21:32	 1418 - Trees on My Island	 C++	 0.280	 1164	Accepted
