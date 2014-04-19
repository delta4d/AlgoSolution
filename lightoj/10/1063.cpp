#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 86;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector <int> e[MAXN];
int anc[MAXN], color[MAXN], dep[MAXN];
bool cut[MAXN];

void dfs(int x, int p, int d) {
	int tot = 0;
	anc[x] = d, color[x] = GRAY, dep[x] = d;
	for (int i=0; i<(int)e[x].size(); ++i) {
		int y = e[x][i];
		if (color[y] == GRAY) anc[x] = min(anc[x], dep[y]);
		if (color[y] == WHITE) {
			++tot;
			dfs(y, x, d+1);
			anc[x] = min(anc[x], anc[y]);
			if (p == -1 && tot > 1) cut[x] = true;
			if (p != -1 && anc[y] >= dep[x]) cut[x] = true;
		}
	}
	color[x] = BLACK;
}

int gao(const int n) {
	memset(cut, false, sizeof(cut));
	memset(color, WHITE, sizeof(color));
	dfs(0, -1, 0);
	int tot = 0;
	for (int i=0; i<n; ++i) tot += cut[i];
	return tot;
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,u,v; i<m; ++i) {
			scanf("%d%d", &u, &v), --u, --v;
			e[u].push_back(v), e[v].push_back(u);
		}
		printf("Case %d: %d\n", ++cn, gao(n));
	}
	return 0;
}

// 319816	2014-02-02 20:49:22	 1063 - Ant Hills	 C++	 0.036	 2272	Accepted
