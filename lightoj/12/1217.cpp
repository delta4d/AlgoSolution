#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1 << 10;

int f[N][2], x[N];

int gao(int st, int ed) {
	memset(f, 0, sizeof(f));
	f[st][1] = x[st];
	for (int i=st+1; i<=ed; ++i) {
		f[i][0] = max(f[i-1][0], f[i-1][1]);
		f[i][1] = f[i-1][0] + x[i];
	}
	return max(f[ed][0], f[ed][1]);
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", x+i);
		printf("Case %d: %d\n", ++cn, max(gao(0, n-2), gao(1, n-1)));
	}
	return 0;
}

// 291110	2013-11-25 00:32:24	 1217 - Neighbor House (II)	 C++	 0.008	 1100	Accepted
