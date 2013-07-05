#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;
const int INF = 0x3f3f3f3f;

int x[MAXN], y[MAXN];

int main() {
	int mn = INF, mx = -INF;
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d%d", x+i, y+i);
		mn = min(mn, x[i]), mx = max(mx, y[i]);
	}
	for (int i=0; i<n; ++i) {
		if (x[i] == mn && y[i] == mx) return printf("%d\n", i+1), 0;
	}
	puts("-1");

	return 0;
}

// 3999001	 Jul 1, 2013 1:58:37 PM	delta_4d#	 B - Big Segment	 GNU C++	Accepted	 62 ms	 800 KB
