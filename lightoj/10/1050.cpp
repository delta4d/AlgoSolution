#include <cstdio>
using namespace std;

const int N = 1 << 9;

double f[N][N];

void init() {
	for (int i=0; i<N; ++i) f[0][i] = i & 1, f[i][0] = 1 ^ (i & 1);
	for (int i=1; i<N; ++i) for (int j=1; j<N; ++j) {
		if ((i + j) & 1) {
			f[i][j] = i * (1 - f[i-1][j]) + j * (1 - f[i][j-1]);
			f[i][j] /= i + j;
		} else {
			f[i][j] = 1 - f[i][j-1];
		}
	}
}

int main() {
	init();
	int tc, cn = 0, r, b;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &r, &b);
		printf("Case %d: %.15lf\n", ++cn, f[r][b]);
	}
	return 0;
}

// 290660	2013-11-23 17:48:32	 1050 - Marbles	 C++	 0.016	 3136	Accepted
