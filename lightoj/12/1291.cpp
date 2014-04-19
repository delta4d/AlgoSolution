#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 86;

enum COLOR { WHITE, GRAY, BLACK };

vector <int> e[MAXN], f[MAXN];
int dep[MAXN], anc[MAXN];
COLOR color[MAXN];
int id[MAXN], num;
int d[MAXN];
set <pair<int, int> > edge;

void dfs(int x, int p, int d) {
	dep[x] = d, anc[x] = d, color[x] = GRAY;
	for (int i=0,y; i<(int)e[x].size(); ++i) {
		y = e[x][i];
		if (y == p) continue;
		if (color[y] == GRAY) anc[x] = min(anc[x], dep[y]);
		if (color[y] == WHITE) dfs(y, x, d+1), anc[x] = min(anc[x], anc[y]);
		if (anc[y] <= dep[x]) f[x].push_back(y), f[y].push_back(x);
	}
	color[x] = BLACK;
}

void dfs(int x) {
	id[x] = num;
	for (int i=0; i<(int)f[x].size(); ++i) {
		int y = f[x][i];
		if (id[y] == -1) dfs(y);
	}
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) e[i].clear(), f[i].clear();
		for (int a,b,i=0; i<m; ++i) {
			scanf("%d%d", &a, &b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		memset(color, WHITE, sizeof(color));
		dfs(0, -1, 0);
		memset(id, -1, sizeof(id));
		num = 0;
		for (int i=0; i<n; ++i) if (id[i] == -1) {
			dfs(i);
			++num;
		}
		edge.clear();
		memset(d, 0, sizeof(d));
		for (int i=0; i<n; ++i) {
			int a = id[i];
			for (int j=0; j<(int)e[i].size(); ++j) {
				int b = id[e[i][j]];
				if (a == b) continue;
				if (edge.find(make_pair(a, b)) != edge.end()) continue;
				++d[a], ++d[b];
				edge.insert(make_pair(a, b));
			}
		}
		int cnt = 0;
		for (int i=0; i<num; ++i) if (d[i] == 2) ++cnt;
		printf("Case %d: %d\n", ++cn, (cnt+1)>>1);
	}
	return 0;
}

// 320465	2014-02-05 00:13:10	 1291 - Real Life Traffic	 C++	 0.288	 4648	Accepted
