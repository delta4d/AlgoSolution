#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 200000000;
const int MAXN = 1000;

int f[MAXN][MAXN];
int d[MAXN];
int r[MAXN];
bool visit[MAXN];

int dfs(int v, int n) {
	int u, sum(0);
	if (r[v] != -1) return r[v];
	for (u=0; u<n; ++u) {
		if (f[u][v] != INF && d[u] > d[v]) sum += dfs(u, n);
	}
	return r[v] = sum;
}

void gao(const int src, const int dst, const int n) {
	int i, j, k;
	int mind, index;
	for (i=0; i<n; ++i) d[i] = INF, visit[i] = false;
	d[src] = 0;
	for (k=0; k<n; ++k) {
		mind = INF;
		for (i=0; i<n; ++i) {
			if (!visit[i] && d[i] < mind) {
				mind = d[i];
				index = i;
			}
		}
		visit[index] = true;
		for (i=0; i<n; ++i) {
			if (!visit[i] && d[index] + f[index][i] < d[i]) {
				d[i] = d[index] + f[index][i];
			}
		}
	}
	if (d[dst] == INF) {
		puts("0");
	} else {
		for (i=0; i<n; ++i) r[i] = -1;
		r[dst] = 1;
		printf("%d\n", dfs(src, n));
	}
}

int main() {
	int i, j, k;
	int m, n;
	int x, y, w;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (scanf("%d", &n), n) {
		scanf("%d", &m);
		for (i=0; i<n; ++i) for (j=0; j<n; ++j) f[i][j] = INF;
		for (i=0; i<m; ++i) {
			scanf("%d %d %d", &x, &y, &w);
			--x, --y;
			f[x][y] = f[y][x] = w;
		}
		gao(1, 0, n);
	}
	return 0;
}