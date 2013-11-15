#include <cstdio>
#include <memory>
using namespace std;

const int MAXN = 61;
typedef long long LL;
LL f[MAXN][4];
LL g[MAXN][4];
LL res[61];

inline void gen() {
	int i, j, k;
	for (i=1; i<4; ++i) f[1][i] = 1;
	for (k=2; k<MAXN; ++k) {
		if (k % 2 == 1) {
			for (i=1; i<=3; ++i) for (j=0; j<i; ++j) f[k][i] += g[k-1][j];
		} else {
			for (i=0; i<=2; ++i) for (j=i+1; j<=3; ++j) g[k][i] += f[k-1][j];
		}
	}
	res[0] = 1;
	for (k=1; k<MAXN; ++k) {
		if (k % 2 == 1) for (i=1; i<=3; ++i) res[k] += f[k][i];
		else for (i=0; i<=2; ++i) res[k] += g[k][i];
	}
}

int main() {
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	gen();
	while (scanf("%d", &n) != EOF) printf("%lld\n", res[n]);
	return 0;
}
