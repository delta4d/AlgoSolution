#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30000 + 86;

int h[N], q[N], t[N], L[N];

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
		int tail = 0, mx = 0;
		for (int i=0; i<n; ++i) {
			h[i] = fastin<int>();
			for (; tail>0&&q[tail-1]>=h[i]; --tail);
			L[i] = tail <= 0 ? -1 : t[tail-1];
			q[tail] = h[i], t[tail++] = i;
		}
		tail = 0;
		for (int i=n-1; i>=0; --i) {
			for (; tail>0&&q[tail-1]>=h[i]; --tail);
			int R = tail <= 0 ? n : t[tail-1];
			mx = max(mx, h[i]*(R-L[i]-1));
			q[tail] = h[i], t[tail++] = i;
		}
		printf("Case %d: %d\n", ++cn, mx);
	}
	return 0;
}

// 293820	2013-12-01 13:25:56	 1083 - Histogram	 C++	 0.056	 1556	Accepted
