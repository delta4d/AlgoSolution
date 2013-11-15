#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MAXN = 300;
const LL INF = 0x3f3f3f3f3f3f3f3fll;

bool visit[MAXN];
bool inf, reach_end;
LL f[MAXN][MAXN];
LL worst_score;
LL s, t, n;

void dfs(LL pos, LL score) {
	LL i, j, k;
	if (inf) return;
	if (pos == t) {
		reach_end = true;
		worst_score = min(worst_score, score);
		return;
	}
	for (i=0; i<n; ++i) {
		if (f[pos][i] != INF) {
			if (visit[i]) {
				if (!inf && score + f[pos][i] != 0) {
					inf = true;
					return;
				}
			} else {
				visit[i] = true;
				dfs(i, score+f[pos][i]);
				if (inf) return;
				visit[i] = false;
			}
		}
	}
}

int main() {
	LL i, j, k;
	LL x, y, w;
	LL m;
	LL tc;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%lld", &tc);
	while (tc--) {
		scanf("%lld", &n);
		for (i=0; i<n; ++i) for (j=0; j<n; ++j) f[i][j] = INF;
		scanf("%lld %lld", &s, &t);
		scanf("%lld", &m);
		for (i=0; i<m; ++i) {
			scanf("%lld %lld %lld", &x, &y, &w);
			f[x][y] = w;
		}
		reach_end = false, inf = false;
		worst_score = INF;
		for (i=0; i<n; ++i) visit[i] = false;
		visit[s] = true;
		dfs(s, 0);
		if (!reach_end || inf) puts("infinity");
		else printf("%lld\n", worst_score);
	}
	return 0;
}