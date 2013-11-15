#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int NOT_COLORED = -1;
const int NOT_CONNECT = -1;
const int SAME = 0;
const int DIFF = 1;

const int MAXN = 1001;
int graph[MAXN][MAXN];
int vertex[MAXN];
int sum[2];
bool visit[MAXN];
bool consistent;
char buff[80];

void dfs(const int x, const int n) {
	int i, j, k;
	if (!consistent) return;
	for (i=1; i<=n; ++i) {
		if (!visit[i]) {
			if (graph[x][i] == SAME) {
				visit[i] = true;
				if (vertex[i] == NOT_COLORED) {
					vertex[i] = vertex[x];
					++sum[vertex[i]];
					dfs(i, n);
				} else if (vertex[x]^vertex[i]) {
					consistent = false;
					return;
				}
			} else if (graph[x][i] == DIFF) {
				visit[i] = true;
				if (vertex[i] == NOT_COLORED) {
					vertex[i] = vertex[x] ^ 1;
					++sum[vertex[i]];
					dfs(i, n);
				} else if (vertex[x] == vertex[i]) {
					consistent = false;
					return;
				}
			}
		} else {
			if (graph[x][i] == SAME && (vertex[x] ^ vertex[i])) {
				consistent = false;
				return;
			}
			if (graph[x][i] == DIFF && vertex[x] == vertex[i]) {
				consistent = false;
				return;
			}
		}
	}
}

void gao(const int n) {
	int i, j, k;
	int res(0);
	memset(visit, false, sizeof(visit));
	memset(vertex, NOT_COLORED, sizeof(vertex));
	for (i=1; i<=n; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			consistent = true;
			vertex[i] = 0;
			sum[0] = 1, sum[1] = 0;
			dfs(i, n);
			if (!consistent) break;
			res += max(sum[0], sum[1]);
		}
	}
	if (!consistent) puts("Inconsistent");
	else printf("%d\n", res);
}

int main() {
	int x, y, n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &n);
	while (n != 0) {
		consistent = true;
		memset(graph, NOT_CONNECT, sizeof(graph));
		for (i=1; i<=n; ++i) graph[i][i] = SAME;
		for (x=1; x<=n; ++x) {
			scanf("%s %d %s %s", buff, &y, buff, buff);
			if (consistent) {
				if (buff[0] == 't') {
					if (graph[x][y] == DIFF) {
						consistent = false;
						continue;
					}
					graph[x][y] = graph[y][x] = SAME;
				} else {
					if (graph[x][y] == SAME) {
						consistent = false;
						continue;
					}
					graph[x][y] = graph[y][x] = DIFF;
				}
			}
		}
		if (!consistent) puts("Inconsistent");
		else gao(n);
		scanf("%d", &n);
	}
	return 0;
}