#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 101;

unsigned long long f[50000 + 86];
int x[N];

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
		int tot = 0, b2;
		n = fastin<int>();
		for (int i=0; i<n; ++i) tot += (x[i] = fastin<int>());
		b2 = tot >> 1;
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (int i=0; i<n; ++i) for (int j=b2-x[i]; j>=0; --j) if (f[j]) f[j+x[i]] |= f[j] << 1;
		int mn = tot + 1, x, y, a = n >> 1, b = n - a;
		for (int i=1; i<=b2; ++i) if (f[i] & ((1ll << a) | (1ll << b))) {
			int cc = i + i - tot;
			cc < 0 && (cc = -cc);
			if (cc < mn) mn = cc, x = i, y = tot - i;
		}
		if (x > y) swap(x, y);
		printf("Case %d: %d %d\n", ++cn, x, y);
	}
	return 0;
}

// 297902	2013-12-10 23:53:37	 1147 - Tug of War	 C++	 0.516	 1480	Accepted
