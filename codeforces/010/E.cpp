#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int n, x[444], mn = INF;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	for (int i=0; i<n; ++i) for (int j=i; j<n; ++j) {
		int c = 1, t = x[i] - 1, p = 0;
		for (int k=0; k<=j; ++k) c += t / x[k], p += t / x[k] * x[k], t %= x[k];
		t = p + x[j]; for (int k=0; k<n; ++k) c -= t / x[k], t %= x[k];
		if (c < 0) mn = min(mn, p + x[j]);
	}
	printf("%d\n", mn==INF?-1:mn);
	return 0;
}

// 3660623	 May 2, 2013 6:24:20 PM	delta_4d	 E - Greedy Change	 GNU C++	Accepted	359 ms	0 KB
