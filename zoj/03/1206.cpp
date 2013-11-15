#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10001;
const int INF = 0x7fffffff;

int f[MAXN][10][10];
int cost[1000];

int main() {
	int i, j, k, t;
	int ri, rj;
	int m, n;
	int num, cst;
	int tot;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &m, &n) != EOF) {
		for (i=0; i<1000; ++i) cost[i] = 0;
		for (i=0; i<m; ++i) {
			scanf("%d %d", &num, &cst);
			cost[num] = cst;
		}
		for (i=0; i<3; ++i) for (j=0; j<10; ++j) for (k=0; k<10; ++k) f[i][j][k] = 0;
		for (i=3; i<=n; ++i) {
			for (j=0; j<10; ++j) {
				for (k=0; k<10; ++k) {
					f[i][j][k] = -INF;
					for (t=0; t<10; ++t) {
						f[i][j][k] = max(f[i][j][k], f[i-1][k][t] + cost[j*100+k*10+t]);
					}
				}
			}
		}
		tot = -INF;
		ri = rj = 0;
		for (i=0; i<10; ++i) {
			for (j=0; j<10; ++j) {
				if (tot < f[n][i][j]) {
					tot = f[n][i][j];
					ri = i, rj = j;
				}
			}
		}
		for (k=n; k>=3; --k)
			for (t=0; t<=9; ++t)
				if (f[k-1][rj][t] + cost[ri*100+rj*10+t] == tot) {
					 tot -= cost[ri*100+rj*10+t];
					 printf("%d", ri);
					 ri = rj, rj = t;
					 break;
		}
	   if (n == 1 || n == 0) puts("0");
	   else printf("%d%d\n", ri, rj);
	}
	return 0;
}