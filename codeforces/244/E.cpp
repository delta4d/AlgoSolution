#include <cstdio>
#include <algorithm>
using namespace std;

using ll = long long;
int const N = 1e6 + 10;
ll const INF = 0x3f3f3f3f3f3f3f3f3fll;

ll x[N];
int n, m;

ll f(int p) {
	ll ret = 0, rem = 0;
	for (int i=0; i<p; ++i) {
		++rem;
		if (rem == m) ret += (x[p] - x[i-rem+1]) << 1, rem = 0;
	}
	if (rem) ret += (x[p] - x[p-rem]) << 1, rem = 0;
	for (int i=n-1; i>p; --i) {
		++rem;
		if (rem == m) ret += (x[i+rem-1] - x[p]) << 1, rem = 0;
	}
	if (rem) ret += (x[p+rem] - x[p]) << 1, rem = 0;
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) scanf("%I64d", x+i);
	ll mn = INF;
	for (int i=-1; i<=1; ++i) if (0<=i+n/2 && i+n/2<n) mn = min(mn, f(i+n/2));
	if (mn == INF) mn = 0;
	printf("%I64d\n", mn);
	return 0;
}

// 6537929	 May 3, 2014 2:23:02 PM	delta_4d	 E - Police Patrol	 GNU C++0x	Accepted	 264 ms	 7800 KB
