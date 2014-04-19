#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-8;
const int M = 1000000;
const int N = 100000000 / M;
double h[M];

double f(int n) {
	double tot = 0;
	if (n >= N) tot = h[n / N - 1];
	for (int i=n/N*N+1; i<=n; ++i) tot += 1.0 / i;
	return tot;
}

int main() {
	for (int i=0; i<M; ++i) {
		if (i) h[i] = h[i-1];
		for (int j=0; j<N; ++j) h[i] += 1.0 / (N * i + j + 1); 
	}
//	double x = 0;
//	for (int i=1; i<1000000; ++i) {
//		x += 1.0 / i;
//		double y = f(i);
//		if (fabs(x - y) > eps) printf("!!!!!!! %d %lf %lf\n", i, x, y);
//	}
//	puts("ok");
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("Case %d: %.10lf\n", ++cn, f(n));
	}
	return 0;
}

// 249639	2013-08-09 13:56:05	 1234 - Harmonic Number	 C++	 1.024	 8900	Accepted
