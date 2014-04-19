#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 111;
const int C = 100;

int v[MAXN];

double sum(double p, const int N) {
	double tot = 0;
	for (int i=0; i<N; ++i) tot += p * v[i] * C / sqrt(1 - p * p * v[i] * v[i]);
	return tot;
}

int main() {
	int tc, cn = 0, N, D;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &N, &D);
		double left = 0, right = 1, mid, p = -1, si;
		for (int i=0; i<N; ++i) scanf("%d", v+i), right = min(right, 1.0/v[i]);
		for (int i=0; i<50; ++i) {
			mid = (left + right) / 2;
			double S = sum(mid, N);
			if (S >= D) right = mid, p = mid;
			else left = mid;
		}
		double t = 0;
		for (int i=0; i<N; ++i) {
			si = p * v[i] * C / sqrt(1 - p * p * v[i] * v[i]);
			t += sqrt(si * si + C * C) / v[i];
		}
		printf("Case %d: %.10lf\n", ++cn, t);
	}
	return 0;
}

// 260817	2013-09-09 21:10:20	 1391 - Speed Zones	 C++	 0.004	 1100	Accepted
