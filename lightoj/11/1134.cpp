#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int N = 100000 + 86;

int c[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

inline void add(int &sum, const int mod) {
	sum = (sum + fastin<int>()) % mod;
	++c[sum];
}

int main() {
	int tc, cn = 0, n, m;
	for (tc=fastin<int>(); tc--; ) {
		memset(c, 0, sizeof(c));
		n = fastin<int>(), m = fastin<int>();
		int sum = 0;
		for (int i=0; i<n; ++i) add(sum, m);
		++c[0];
		ll tot = 0;
		for (int i=0; i<m; ++i) tot += (ll)c[i] * (c[i] - 1) >> 1;
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 292990	2013-11-29 22:00:36	 1134 - Be Efficient	 C++	 0.096	 1476	Accepted
