#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 101;

long double p[N][N];
long double d[N];
bool v[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

double gao(const int n) {
	fill(d, d+n, 0);
	fill(v, v+n, false);
	d[0] = 1;
	for (int k=0; k<n; ++k) {
		double mx = 0;
		int idx = -1;
		for (int i=0; i<n; ++i) if (!v[i] && d[i] > mx) mx = d[i], idx = i;
		v[idx] = true;
		for (int i=0; i<n; ++i) if (!v[i]) d[i] = max(d[i], d[idx] * p[idx][i]);
	}
	return d[n-1];
}

int main() {
	int tc, cn = 0, n, m, s, k;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), m = fastin<int>(), s = fastin<int>(), k = fastin<int>();
		for (int i=0; i<n; ++i) fill(p[i], p[i]+n, 0);
		for (int i=0,x,y,pi; i<m; ++i) {
			x = fastin<int>(), y = fastin<int>(), pi = fastin<int>();
			p[x][y] = p[y][x] = pi / 100.0;
		}
		printf("Case %d: %.10lf\n", ++cn, s*2.0*k/gao(n));
	}
	return 0;
}
