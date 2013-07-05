#include <cstdio>
#include <memory>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1001;
int x[MAXN], y[MAXN];
int f[MAXN][MAXN];

inline int cmp(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

inline int g(const int a, const int b) {
	if (x[a] == y[b]) return 0;
	return x[a] > y[b] ? 1 : -1;
}

inline int gao(const int n) {
	int i, j, k;
	f[0][0] = 0;
	for (i=1; i<=n; ++i) {
		f[i][i] = f[i-1][i-1] + g(i, i);
		f[i][0] = f[i-1][0] + g(n-i+1, i);
		for (j=1; j<i; ++j) {
			f[i][j] = max(f[i-1][j]+g(n-i+j+1,i), f[i-1][j-1]+g(j,i));
		}
	}
	int res(-INF);
	for (i=0; i<=n; ++i) res = max(res, f[n][i]);
	return res*200;
}

int main() {
	int n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=1; i<=n; ++i) scanf("%d", x+i);
		for (i=1; i<=n; ++i) scanf("%d", y+i);
		qsort(x+1, n, sizeof(x[0]), cmp);
		qsort(y+1, n, sizeof(y[0]), cmp);
		printf("%d\n", gao(n));
		scanf("%d", &n);
	}
	return 0;
}