#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500000 + 86;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int f[2][N], x[N];

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		int t = 0;
		for (int i=0; i<n; ++i) x[i] = fastin<int>(), t += x[i];
		memset(f, -1, sizeof(f));
		f[0][0] = 0;
		int cur = 0, nxt = 1;
		for (int i=0; i<n; ++i) {
			nxt = cur ^ 1;
			for (int k=0; k<=t; ++k) {
				if (f[cur][k] >= 0) {
					int a = f[cur][k], b = a + k;
					int aa = a + x[i], bb = b + x[i];
					int d1 = abs(aa - b), d2 = abs(a - bb);
					f[nxt][d1] = max(f[nxt][d1], min(aa, b));
					f[nxt][d2] = max(f[nxt][d2], min(a, bb));
				}
				f[nxt][k] = max(f[nxt][k], f[cur][k]);
			}
			cur = nxt;
		}
		printf("Case %d: ", ++cn);
		if (f[cur][0]) printf("%d\n", f[cur][0]);
		else puts("impossible");
	}
	return 0;
}

// 291718	2013-11-26 18:05:03	 1126 - Building Twin Towers	 C++	 2.432	 6948	Accepted
