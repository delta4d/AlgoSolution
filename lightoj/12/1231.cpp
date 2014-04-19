#include <cstdio>
#include <cstring>
using namespace std;

const int M = 100000007;

int f[1<<10];
int a[100], c[100];

inline void add(int &a, int b) {
	a += b;
	if (a >= M) a -= M;
}

int main() {
	int tc, cn = 0, n, K;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &K);
		for (int i=0; i<n; ++i) scanf("%d", a+i);
		for (int i=0; i<n; ++i) scanf("%d", c+i);
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (int i=0; i<n; ++i) for (int k=K; k>=0; --k) {
			for (int j=1; j<=c[i]; ++j) if (k + a[i] * j <= K) add(f[k+j*a[i]], f[k]);
		}
		printf("Case %d: %d\n", ++cn, f[K]);
	}
	return 0;
}

// 291186	2013-11-25 13:07:33	 1231 - Coin Change (I)	 C++	 0.180	 1092	Accepted
