/**
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500;

double f[N][N];

void init() {
	for (int i=0; i<N; ++i) f[i][0] = 1, f[0][i] = 0;
	for (int x=1; x<N; ++x) {
		for (int y=1; y<N; ++y) {
			f[x][y] = double(x) / (x + y) * (f[x-1][y] + double(y) / (x + y - 1))
				+ double(y) / (x + y) * (f[x][y-1] + double(x) / (x + y - 1));
		}
	}
//	for (int i=1; i<100; ++i) printf("%d %d => %lf\n", 3, i, (6-f[3][i])*(i+3));
// (2 * x - f(x, y)) * (x + y) is constant for fixed x
}

int main() {
	init();
	int tc, cn = 0, n, s;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &s);
		int x = 3 * n - s, y = n - x;
		printf("Case %d: %.20lf\n", ++cn, f[x][y]);
	}
	return 0;
}
**/
#include <cstdio>
int main() {
	int tc, cn = 0, n, s;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &s);
		int x = 3 * n - s, y = n - x;
		printf("Case %d: %lf\n", ++cn, (2.0*x*y+x)/(x+y));
	}
	return 0;
}

// 321100	2014-02-07 01:15:36	 1274 - Beating the Dataset	 C++	 0.000	 1088	Accepted
