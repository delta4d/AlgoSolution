#include <cstdio>
using namespace std;

typedef long long LL;

const LL MAXN = 50;

bool colored[MAXN];
bool f[MAXN][MAXN];

int main() {
	LL m, n;
	LL i, j, k;
	LL x, y;
	LL res, cnt;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%lld %lld", &n, &m), m||n) {
		for (i=0; i<n; colored[i++]=false);
		for (i=0; i<n; ++i) for (j=0; j<n; f[i][j++]=false);
		for (i=1; i<n; ++i) {
			scanf("%lld %lld", &x, &y);
			--x, --y;
			f[x][y] = f[y][x] = true;
		}
		res = 1;
		for (i=0; i<n; ++i) {
			colored[i] = true;
			cnt = 0;
			for (j=0; j<n; ++j) cnt += colored[j] && f[i][j];
			res *= (m - cnt);
		}
		printf("%lld\n", res);
	}
	return 0;
}