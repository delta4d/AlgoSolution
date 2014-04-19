#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1 << 10;

int x[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

inline bool ok(int cc, int n, int k) {
	++k;
	int cnt = 0;
	for (int i=0,j; i<=n; i=j) {
		int tot = 0;
		for (j=i; j<=n; ++j) {
			tot += x[j];
			if (tot > cc) break;
		}
		++cnt;
		if (cnt > k) return false;
	}
	return cnt <= k;
}

int main() {
	int tc, cn = 0, n, k;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), k = fastin<int>();
		x[n+1] = 0;
		for (int i=0; i<=n; ++i) x[i] = fastin<int>();
		int left = 0, right = 0, mid, p = -1;
		for (int i=0; i<=n; ++i) left = max(left, x[i]), right += x[i];
		while (left <= right) {
			mid = (left + right) >> 1;
			if (ok(mid, n, k)) right = mid - 1, p = mid;
			else left = mid + 1;
		}
		printf("Case %d: %d\n", ++cn, p);
		int cnt = 0;
		for (int i=0,j; i<=n; i=j) {
			int tot = 0;
			for (j=i; j<=n; ++j) {
				tot += x[j];
				if (tot > p || n - j + cnt < k) break;
			}
			++cnt;
			printf("%d\n", tot-x[j]);
		}
	}
	return 0;
}

// 260055	2013-09-05 22:56:34	 1048 - Conquering Keokradong	 C++	 0.044	 1092	Accepted
