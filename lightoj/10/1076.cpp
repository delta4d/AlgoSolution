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

inline bool ok(int cc, int n, int m) {
	int cnt = 0;
	for (int i=0,j; i<n; ) {
		int sum = 0;
		for (j=i; j<n; ++j) {
			sum += x[j];
			if (sum > cc) break;
		}
		i = j, ++cnt;
		if (cnt > m) return false;
	}
	return cnt <= m;
}

int main() {
	int tc, cn = 0, n, m;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), m = fastin<int>();
		int left = 0, right = 0, mid, k = -1;
		for (int i=0; i<n; ++i) x[i] = fastin<int>(), left = max(left, x[i]), right += x[i];
		right = (right + m - 1) / m + left;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (ok(mid, n, m)) right = mid - 1, k = mid;
			else left = mid + 1;
		}
		printf("Case %d: %d\n", ++cn, k);
	}
	return 0;
}

// 259647	2013-09-04 20:45:43	 1076 - Get the Containers	 C++	 0.012	 1092	Accepted
