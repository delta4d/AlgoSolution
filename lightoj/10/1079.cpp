#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 111;

long double f[MAXN*MAXN];

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		double P, p;
		scanf("%lf", &P), P = 1 - P;
		scanf("%d", &n);
		int mx = n * 101;
		fill(f, f+mx+1, 0), f[0] = 1;
		for (int i=0; i<n; ++i) {
			scanf("%d%lf", &m, &p), p = 1 - p;
			for (int j=mx; j>=0; --j) if (j + m <= mx) f[j+m] = max(f[j+m], f[j]*p);
		}
		for (int i=mx; i>=0; --i) if (f[i] >= P) {
			printf("Case %d: %d\n", ++cn, i);
			break;
		}
	}
	return 0;
}
