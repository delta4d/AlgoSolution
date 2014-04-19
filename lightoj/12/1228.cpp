#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[1<<12][12][13], s[13];
bool e[12][12];

void gao(int n) {
	memset(f, 0, sizeof(f));
	for (int i=0; i<n; ++i) f[1<<i][i][0] = 1;
	for (int mask=1,m=1<<n; mask<m; ++mask) {
		for (int ed=0; ed<n; ++ed) if (mask & 1 << ed) {
			int new_mask = mask ^ (1 << ed);
			for (int pre=0; pre<n; ++pre) if ((pre != ed) && (mask & 1 << pre)) {
				for (int d=0; d<=n; ++d) {
					if (e[ed][pre]) f[mask][ed][d] += (!!d) * f[new_mask][pre][d-1];
					else f[mask][ed][d] += f[new_mask][pre][d];
				}
			}
		}
	}
	memset(s, 0, sizeof(s));
	for (int c=(1<<n)-1,i=0; i<n; ++i) for (int d=0; d<=n; ++d) s[d] += f[c][i][d];
	for (int i=1; i<=n; ++i) s[i] += s[i-1];
}

int main() {
	int tc, cn = 0, n, k, q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &n, &k, &q);
		memset(e, false, sizeof(e));
		for (int i=0,t; i<n; ++i) {
			scanf("%d", &t);
			for (int x; t--; ) {
				scanf("%d", &x);
				e[i][x-1] = true;
			}
		}
		gao(n);
		printf("Case %d:\n", ++cn);
		for (int x; q--; ) {
			scanf("%d", &x);
			printf("%d\n", k?s[x/k]:s[n-1]);
		}
	}
	return 0;
}

// 305047	2013-12-27 22:45:59	 1228 - e-Friends	 C++	 0.116	 3584	Accepted
