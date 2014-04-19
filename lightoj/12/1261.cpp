#include <cstdio>
using namespace std;

int x[30][30], c[30];

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		int n, m, k, p;
		scanf("%d%d%d", &n, &m, &k);
		for (int i=0; i<n; ++i) for (int j=0; j<k; ++j) scanf("%d", x[i]+j);
		bool ok[30]={false};
		scanf("%d", &p);
		for (int i=0; i<p; ++i) {
			scanf("%d", c+i);
			for (int j=0; j<n; ++j) if (!ok[j]) for (int t=0; t<k; ++t) {
				if (x[j][t] == c[i]) {
					ok[j] = true;
					break;
				}
			}
		}
		for (int i=0; i<n; ++i) if (!ok[i]) {
			bool cc = false;
			for (int j=0; j<k; ++j) if (x[i][j] < 0) {
				bool find_one = false;
				for (int t=0; t<p; ++t) if (c[t] + x[i][j] == 0) {
					find_one = true;
					break;
				}
				if (!find_one) {
					cc = true;
					break;
				}
			}
			ok[i] = cc;
		}
//		for (int i=0; i<n; ++i) printf("%d ", ok[i]); puts("");
		for (int i=1; i<n; ++i) ok[i] &= ok[i-1];
		printf("Case %d: %s\n", ++cn, ok[n-1]?"Yes":"No");
	}
	return 0;
}

// 252829	2013-08-18 14:51:13	 1261 - K-SAT Problem	 C++	 0.004	 1092	Accepted
