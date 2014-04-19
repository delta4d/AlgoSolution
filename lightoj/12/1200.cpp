#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[10000 + 86];
int p[100], c[100], w[100];

int main() {
	int tc, cn = 0, n, W;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &W);
		int rem = 0;
		for (int i=0; i<n; ++i) scanf("%d%d%d", p+i, c+i, w+i), rem += w[i] * c[i];
		rem = W - rem;
		printf("Case %d: ", ++cn);
		if (rem < 0) {
			puts("Impossible");
		} else {
			memset(f, -1, sizeof(f));
			f[0] = 0;
			for (int i=0; i<n; ++i) {
				for (int j=0; j+w[i]<=rem; ++j) if (f[j] >= 0) {
					if (f[j+w[i]] < 0) f[j+w[i]] = f[j] + p[i];
					else f[j+w[i]] = max(f[j+w[i]], f[j]+p[i]);
				}
			}
			int mx = 0;
			for (int i=0; i<=rem; ++i) mx = max(mx, f[i]);
			printf("%d\n", mx);
		}
	}
	return 0;
}

// 292979	2013-11-29 21:24:56	 1200 - Thief	 C++	 0.124	 1128	Accepted
