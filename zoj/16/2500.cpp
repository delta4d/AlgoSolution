#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef VI::iterator VII;
const int MAXN = 100;

VI pos[MAXN], neg[MAXN];
bool visit[MAXN];

void dfs(VI f[], const int root, int &cnt) {
	int i, j, k;
	VII it;
	visit[root] = true;
	for (it=f[root].begin(); it!=f[root].end(); ++it) {
		k = *it;
		if (!visit[k]) dfs(f, k, ++cnt);
	}
}

int gao(const int n) {
	int i, j, k(0);
	int x, y, r((n+1)>>1);
	for (i=1; i<=n; ++i) {
		x = 0, y = 0;
		memset(visit, false, sizeof(visit)); dfs(pos, i, x);
		memset(visit, false, sizeof(visit)); dfs(neg, i, y);
		k += x >= r || y >= r ? 1 : 0;
	}
	return k;
}

int main() {
	int tc;
	int r, s, t;
	int m, n;
	int i, j, k;
	int x, y, w;	
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (r=0; r<tc; ++r) {
		scanf("%d %d", &n, &m);
		for (i=1; i<=n; ++i) {
			pos[i].clear();
			neg[i].clear();
		}
		for (i=0; i<m; ++i) {
			scanf("%d %d", &x, &y);
			pos[x].push_back(y);
			neg[y].push_back(x);
		}
		printf("%d\n", gao(n));
	}
	return 0;
}