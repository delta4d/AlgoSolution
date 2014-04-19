#include <cstdio>
using namespace std;

int r[100000 + 86];

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
		for (int i=1; i<=n; ++i) r[i] = fastin<int>();
		int mx = 0;
		for (int i=n; i>0; --i) {
			int c = r[i] - r[i-1];
			if (mx == c) ++mx;
			else if (mx < c) mx = c;
		}
		printf("Case %d: %d\n", ++cn, mx);
	}
	return 0;
}

// 276332	2013-10-21 14:09:19	 1425 - The Monkey and the Oiled Bamboo	 C++	 0.180	 1476	Accepted
