#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10000 + 86;

int sg[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
} 

void init() {
	for (int i=3; i<N; ++i) {
		bool v[200] = {false};
		for (int j=1; j+j<i; ++j) v[sg[j]^sg[i-j]] = true;
		for (int j=0; ; ++j) if (!v[j]) { sg[i] = j; break; }
	}
	int mx = 0;
	for (int i=0; i<N; ++i) mx = max(mx, sg[i]);
}

int main() {
	init();
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		int t = 0;
		for (int i=0,x; i<n; ++i) x=fastin<int>(), t ^= sg[x];
		printf("Case %d: %s\n", ++cn, t?"Alice":"Bob");
	}
	return 0;
}

// 258082	2013-08-31 21:53:38	 1199 - Partitioning Game	 C++	 0.048	 1128	Accepted
