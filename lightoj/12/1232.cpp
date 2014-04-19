#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10086;
const int M = 100000007;

int f[N], a[N];

void add(int &a, int b) {
	a += b;
	if (a >= M) a -= M;
}

int main() {
	int tc, cn = 0, n, K;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &K);
		for (int i=0; i<n; ++i) scanf("%d", a+i);
		fill(f, f+K+1, 0);
		f[0] = 1;
		for (int i=0; i<n; ++i) for (int j=0; j+a[i]<=K; ++j) add(f[j+a[i]], f[j]);
		printf("Case %d: %d\n", ++cn, f[K]);
	}
	return 0;
}

// 291105	2013-11-25 00:21:51	 1232 - Coin Change (II)	 C++	 0.612	 1164	Accepted
