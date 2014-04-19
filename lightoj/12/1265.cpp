#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1 << 10;

double f[N][N];

void init() {
	for (int i=0; i<N; ++i) f[0][i] = 1;
	for (int i=1; i<N; ++i) for (int j=0; j<N; ++j) {
		double tot = (i + j + 1) * (i + j);
		double p1 = 2 * i * j / tot, p2 = j * (j - 1) / tot, p3 = 2 * j / tot, p4 = i * (i - 1) / tot;
		double t = 0;
		if (j > 0) t += p1 * f[i][j-1];
		if (i > 1) t += p4 * f[i-2][j];
		p2 = 1 - p2;
		f[i][j] = t / (p2 - p3);
		if (j > 0) f[i][j] = max(f[i][j], (t + p3 * f[i][j-1]) / p2);
	}
}

int main() {
	init();
	int tc, cn = 0, a, b;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &a, &b);
		printf("Case %d: %.10lf\n", ++cn, f[a][b]);
	}
	return 0;
}

// 254760	2013-08-23 14:31:47	 1265 - Island of Survival	 C++	 0.068	 9280	Accepted
