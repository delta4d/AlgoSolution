#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

double const eps = 1e-7;

double p[111];

inline bool is0(double x) {
	return fabs(x) < eps;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%lf", p+i);
	sort(p, p+n);
	reverse(p, p+n);
	if (is0(p[0]-1)) {
		printf("1\n");
		return 0;
	}
	double pi = 1, sum = 0, mx = 0;
	for (int i=0; i<n; ++i) {
		pi *= 1 - p[i];
		sum += p[i] / (1 - p[i]);
		mx = max(mx, pi*sum);
	}
	printf("%.20lf\n", mx);
	return 0;
}

// 6918142	 2014-06-19 20:27:17	delta_4d	 B - Andrey and Problem	 GNU C++0x	Accepted	 31 ms	 0 KB
