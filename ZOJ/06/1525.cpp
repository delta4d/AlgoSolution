#include <cstdio>
#include <memory>
using namespace std;

const int MAXN = 121;
int match[MAXN];
bool visit[MAXN];
bool graph[MAXN][MAXN];

bool dfs(const int &x, const int &n) {
	int y;
	for (y=1; y<=n; ++y) {
		if (!visit[y] && graph[x][y]) {
			visit[y] = true;
			if (match[y] == -1 || dfs(match[y], n)) {
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int matching(const int &n) {
	int i;
	int res(0);
	memset(match, -1, sizeof(match));
	for (i=1; i<=n; ++i) {
		memset(visit, false, sizeof(visit));
		if (dfs(i, n)) ++res;
	}
	return res;
}

int main() {
	int tc;
	int n, m;
	int x, y;
	int i, j, k, t;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=0; t<tc; ++t) {
		scanf("%d %d", &n, &m);
		memset(graph, false, sizeof(graph));
		for (i=0; i<m; ++i) {
			scanf("%d %d", &x, &y);
			graph[x][y] = true;
		}
		printf("%d\n", n-matching(n));
	}
	return 0;
}
