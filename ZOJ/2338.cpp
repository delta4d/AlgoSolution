#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long LLU;
const LLU INF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 65;

LLU f[MAXN+1][MAXN+1];
int pre[MAXN+1][MAXN+1];
int q[MAXN][MAXN];
int p[MAXN];
int n, m;
bool visit[MAXN+1];

void gen() { 
	int n, m;
	int i, j, k;

	f[1][3] = 1;
	for (i=2; i<MAXN; ++i) f[i][3] = (f[i-1][3] << 1) + 1;
	for (m=4; m<=MAXN; ++m) {
		for (n=1; n<MAXN; ++n) {
			f[n][m] = f[n][m-1];
			for (k=1; k<n; ++k) {
				LLU temp = (f[k][m] << 1) + f[n-k][m-1];
				if (f[n][m] > temp) {
					f[n][m] = temp;
					pre[n][m] = k;
				}
			}
		}
	}
	for (i=1; i<MAXN; ++i) {
		for (j=4; j<=MAXN; ++j) printf("%lld ", f[i][j]);
		puts("");
	}
}

void init() {
	int i, j, k;
	for (i=0; i<MAXN; ++i) p[i] = 1;
	for (i=1; i<=n; ++i) q[1][i] = n - i + 1;
	p[1] = n + 1;
	memset(visit, false, sizeof(visit));
}

void gao(int src, int nn, int dst, int mm) {
	int i, j, k;
	int ava;

	//printf("src:%d nn:%d dst:%d mm:%d\n", src, nn, dst, mm);

	if (nn == 1) {
		if (p[dst] == 1) printf("move %d from %d to %d\n", q[src][p[src]-1], src, dst);
		else printf("move %d from %d to %d atop %d\n", q[src][p[src]-1], src, dst, q[dst][p[dst]-1]);
		q[dst][p[dst]] = q[src][p[src]-1];
		--p[src], ++p[dst];
		//for (i=1; i<=m; ++i) {
		//	for (j=p[i]-1; j>=1; --j) printf("%d ", q[i][j]);
		//	puts("$");
		//}
		return;
	}
	for (ava=1; ava<=m; ++ava) if (!visit[ava] && ava != dst && ava != src) break;
	k = pre[nn][mm];
	gao(src, k, ava, mm);
	visit[ava] = true;
	gao(src, nn-k, dst, mm-1);
	visit[ava] = false;
	gao(ava, k, dst, mm);
}

int main() {
	int i, j, k;
	int tc;

	gen();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		printf("%llu\n", f[n][m]);
		init();
		gao(1, n, m, m);
		if (tc) puts("");
	}

	return 0;
}
