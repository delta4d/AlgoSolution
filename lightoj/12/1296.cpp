#include <cstdio>
using namespace std;

inline int sg(int x) {
	for (; ; x>>=1) if (!(x&1)) return x >> 1;
}

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
		int t = 0;
		for (int i=0; i<n; ++i) t ^= sg(fastin<int>());
		printf("Case %d: %s\n", ++cn, t?"Alice":"Bob");
	}
	return 0;
}

// 258108	2013-08-31 23:13:50	 1296 - Again Stone Game	 C++	 0.012	 1088	Accepted
