#include <cmath>
#include <cstdio>
using namespace std;

int X, Y, Z, K;

double gao() {
	double ret = 0;
	double tot = X * Y * Z;
	tot = tot * tot;
	for (int x=0; x<X; ++x) for (int y=0; y<Y; ++y) for (int z=0; z<Z; ++z) {
		int x1 = x + 1, x2 = X - x, y1 = y + 1, y2 = Y - y, z1 = z + 1, z2 = Z - z;
		double cc =
			+ 8.0 * x1 * x2 * y1 * y2 * z1 * z2
			- 4.0 * x1 * x2 * y1 * y2
			- 4.0 * y1 * y2 * z1 * z2
			- 4.0 * z1 * z2 * x1 * x2
			+ 2.0 * x1 * x2
			+ 2.0 * y1 * y2
			+ 2.0 * z1 * z2
			- 1.0;
		double p = cc / tot, q = 1 - p;
		ret += (1 - pow(q - p, K)) / 2;
	}
	return ret;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d%d", &X, &Y, &Z, &K);
		printf("Case %d: %lf\n", ++cn, gao());
	}
	return 0;
}

// 321247	2014-02-07 16:04:39	 1284 - Lights inside 3D Grid	 C++	 0.484	 1088	Accepted
