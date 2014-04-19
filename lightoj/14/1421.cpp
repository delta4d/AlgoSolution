#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 86;
const int INF = 0x3f3f3f3f;

int x[N], t[N], d[N];

void gao(const int n, bool reverse) {
	fill(t, t+n+1, INF);
	int L = 1;
	t[1] = x[0];
	if (!reverse) d[0] = min(d[1], 1);
	else d[n-1] = min(d[n-1], 1);
	for (int i=1; i<n; ++i) {
		int left = 1, right = L, mid, cc=0;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (t[mid] < x[i]) left = mid + 1, cc = mid;
			else right = mid - 1;
		}
		++cc;
		t[cc] = min(t[cc], x[i]);
		L = max(L, cc);
		if (!reverse) d[i] = min(d[i], cc);
		else d[n-1-i] = min(d[n-1-i], cc);
	}
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", x+i);
		fill(d, d+n, INF);
		gao(n, false);
		for (int i=0; i+i<n; ++i) swap(x[i], x[n-i-1]);
		gao(n, true);
		int mx = 0;
		for (int i=0; i<n; ++i) mx = max(mx, 2*d[i]-1);
		printf("Case %d: %d\n", ++cn, mx);
	}
	return 0;
}

// 295705	2013-12-05 03:11:53	 1421 - Wavio Sequence	 C++	 0.324	 2260	Accepted
