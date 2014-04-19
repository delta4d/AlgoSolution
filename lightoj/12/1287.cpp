#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

double f[1<<15][15];
int x[15][15];

inline bool zero(const double x) { return fabs(x) < eps; }

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		memset(x, -1, sizeof(x));
		memset(f, 0, sizeof(f));
		for (int i=0,u,v,w; i<m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			x[u][v] = x[v][u] = w;
		}
		for (int i=(1<<n)-2; i>0; --i) for (int j=0; j<n; ++j) if (i & 1 << j) {
			int c = 0;
			for (int k=0; k<n; ++k) if ((!(i&1<<k)) && x[j][k] != -1) {
				if (!zero(f[i|(1<<k)][k]) || __builtin_popcount(i|(1<<k)) == n) {
					f[i][j] += f[i|(1<<k)][k] + x[j][k];
					++c;
				}
			}
			if (!c) continue;
			f[i][j] += 5;
			f[i][j] /= c;
		}
		printf("Case %d: %.10lf\n", ++cn, f[1][0]);
	}
	return 0;
}

// 275223	2013-10-18 13:18:11	 1287 - Where to Run	 C++	 0.736	 4928	Accepted
