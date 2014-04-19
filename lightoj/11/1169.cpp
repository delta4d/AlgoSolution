#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1 << 10;

int a[N][2], b[N][2], f[N][2];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) a[i][0] = fastin<int>();
		for (int i=0; i<n; ++i) a[i][1] = fastin<int>();
		for (int i=1; i<n; ++i) b[i][0] = fastin<int>();
		for (int i=1; i<n; ++i) b[i][1] = fastin<int>();
		f[0][0] = a[0][0], f[0][1] = a[0][1];
		for (int i=1; i<n; ++i) {
			f[i][0] = min(f[i-1][0], f[i-1][1] + b[i][1]) + a[i][0];
			f[i][1] = min(f[i-1][1], f[i-1][0] + b[i][0]) + a[i][1];
		}
		printf("Case %d: %d\n", ++cn, min(f[n-1][0], f[n-1][1]));
	}
	return 0;
}

// 292986	2013-11-29 21:51:30	 1169 - Monkeys on Twin Tower	 C++	 0.004	 1112	Accepted
