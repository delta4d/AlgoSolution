#include <cstdio>
using namespace std;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
} 

int main() {
	int tc, cn = 0, m, n;
	for (tc=fastin<int>(); tc--; ) {
		m = fastin<int>(), n = fastin<int>();
		int t = 0, x;
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
			x = fastin<int>();
			if ((i + j + m + n) & 1) t ^= x;
		}
		printf("Case %d: %s\n", ++cn, t?"win":"lose");
	}
	return 0;
}

// 258042	2013-08-31 20:49:41	 1393 - Crazy Calendar	 C++	 0.064	 1088	Accepted
