#include <cstdio>
using namespace std;

typedef unsigned long long ll;
const int N = 51;

ll f[N][N][2], s[N][N], p[N][N];

void init() {
	f[1][0][0] = f[1][0][1] = 1;
	s[1][0] = p[1][0] = 1;
	for (int i=2; i<N; ++i) {
		for (int j=0; j<i; ++j) {
			f[i][j][0] = (j > 0) * p[i-1][j-1];
			f[i][j][1] = s[i-1][j];
		}
		for (int j=0; j<i; ++j) p[i][j] = (j > 0) * p[i][j-1] + f[i][j][1];
		for (int j=i-1; j>=0; --j) s[i][j] = s[i][j+1] + f[i][j][0];
	}
}

ll gao(int n, int m) {
	if (m) return f[n][m][0];
	if (n <= 2) return 1;
	return f[n-2][0][1];
}

int main() {
	init();
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		printf("Case %d: %llu\n", ++cn, gao(n, m-1));
	}
	return 0;
}

// 258899	2013-09-02 22:14:34	 1173 - The Vindictive Coach	 C++	 0.000	 1168	Accepted
