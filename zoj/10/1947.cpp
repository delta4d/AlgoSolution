#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 25;

int MAX;
bool visit[MAXN][MAXN];
bool graph[MAXN][MAXN];

int gao(const int x, int cur, const int n) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		if (!visit[x][i] && graph[x][i]) {
			visit[x][i] = visit[i][x] = true;
			gao(i, cur+1, n);
			visit[x][i] = visit[i][x] = false;
		}
	}
	MAX = max(MAX, cur);
}

int gao(const int n) {
	int i, j, k;
	int res(-INF);
	for (i=0; i<n; ++i) {
		MAX = -INF;
		memset(visit, false, sizeof(visit));
		gao(i, 0, n);
		res = max(res, MAX);
	}
	return res;
}

int main() {
	int i, j, k;
	int n, m;
	int x, y;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	while (m != 0 || n != 0) {
		memset(graph, false, sizeof(graph));
		for (i=0; i<m; ++i) {
			scanf("%d %d", &x, &y);
			graph[x][y] = graph[y][x] = true;
		}
		printf("%d\n", gao(n));
		scanf("%d %d", &n, &m);
	}
	return 0;
}