#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 201;
int m, n;
bool visit[MAXN];
int graph[MAXN][MAXN];
int low[MAXN], high[MAXN];

inline int gao(const int s, const int t) {
	int i, j, k;
	int min, index;
	memset(visit, false, sizeof(visit));
	low[s] = high[s] = 0;
	visit[s] = true;
	for (k=1; k<n; ++k) {
		min = INF;
		for (i=1; i<=n; ++i) {
			if (!visit[i] && )
		}
	}
}

int main() {
	int i, j, k;
	int q, s, t;
	int x, y, w;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF) {
		for (i=0; i<=n; ++i) for (j=0; j<=n; ++j) graph[i][j] = INF;
		for (i=0; i<m; ++i) {
			scanf("%d %d %d", &x, &y, &w);
			graph[x][y] = graph[y][x] = INF;
		}
		scanf("%d", &q);
		for (i=0; i<q; ++i) {
			scanf("%d %d", &s, &t);
			printf("%d\n", gao(s, t));
		}
	}
	return 0;
}