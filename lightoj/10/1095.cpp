#include <cstdio>
using namespace std;

typedef long long ll;

const int N = 1 << 10;
const int M = 1000000007;

ll C[N][N], f[N][N];

void init() {
	for (int i=0; i<N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j=1; j<i; ++j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
	}
	f[0][0] = 1;
	for (int i=1; i<N; ++i) f[i][0] = f[i-1][0] * i % M;
	for (int i=0; i<N; ++i) for (int j=1; j<N; ++j) {
		f[i][j] = (j - 1) * (f[i][j-2] + f[i][j-1]) % M;
		f[i][j] = (f[i][j] + i * f[i][j-1]) % M;
	}
}

int main() {
	init();
	int tc, cn = 0, n, m, k;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &n, &m, &k);
		ll tot = C[m][k] * f[n-m][m-k] % M;
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 255260	2013-08-25 01:37:29	 1095 - Arrange the Numbers	 C++	 0.040	 17472	Accepted
