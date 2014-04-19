#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[17][1<<16];
int w[16][16];
int st[17][1<<16], cc[17];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

void init() {
	for (int i=0,s=1<<16; i<s; ++i) {
		int k = __builtin_popcount(i);
		st[k][cc[k]++] = i;
	}
}

int main() {
	init();
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) w[i][j] = fastin<int>();
		memset(f, 0, sizeof(f));
		int s = 1 << n;
		for (int i=1; i<=n; ++i) for (int j=0; j<cc[i]&&st[i][j]<s; ++j) {
			int c = st[i][j];
			for (int k=0; k<n; ++k) if (c & 1 << k) {
				f[i][c] = max(f[i-1][c^(1<<k)]+w[i-1][k], f[i][c]);
			}
		}
		printf("Case %d: %d\n", ++cn, f[n][s-1]);
	}
	return 0;
}

// 289653	2013-11-21 16:45:06	 1011 - Marriage Ceremonies	 C++	 0.244	 9792	Accepted
