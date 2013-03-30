/*
ID: delta 4d
PROG: subset
LANG: C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

long long f[MAXN]={1};

int main() {
#ifndef __DELTA__
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
#endif

	int n;

	scanf("%d", &n);
	
	int t = n * (n + 1) >> 1;
	if (t % 2 == 0) {
		t >>= 1;
		for (int i=1; i<=n; ++i) {
			for (int j=t; j>=0; --j) if (f[j] && j + i <= t) f[j+i] += f[j];	
		}
	}
	printf("%lld\n", f[t]>>1);

	return 0;
}
