#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int inf = 100000000;
int n, s, t;
int flow[110][110], mat[110][110], gap[110], dist[110];
int map[110][110];

int find_path(int p, int limit = 1 << 30 - 1) {
	if (p == n - 1)
		return limit;
	for (int i = 0; i < n; i++) {
		if (dist[p] == dist[i] + 1 && map[p][i] > 0) {
			int t = find_path(i, min(limit, map[p][i]));
			if (t < 0)
				return t;
			if (t > 0) {
				map[p][i] -= t;
				map[i][p] += t;
				return t;
			}
		}
	}
	int label = n;
	for (int i = 0; i < n; i++)
		if (map[p][i] > 0) label = min(label, dist[i] + 1);
	if (--gap[dist[p]] == 0 || dist[0] >= n) return -1;
	++gap[dist[p] = label];
	return 0;
}

int iSAP() {
	gap[0] = n;
	int maxflow = 0, t = 0;
	while ((t = find_path(0)) >= 0)
		maxflow += t;
	return maxflow;
}

void buildgraph() {
	memcpy(mat, flow, sizeof(flow));
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (mat[i][k] == inf) continue;
			for (int j = 1; j <= n; j++) {
				if (mat[k][j] == inf) continue;
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= n; i++) {
		if (mat[s][i] == inf) continue;
		for (int j = 1; j <= n; j++) {
			if (mat[j][t] == inf) continue;
			map[i][j] = (flow[i][j] != inf && mat[s][i] + flow[i][j] + mat[j][t] == mat[s][t]);
		}
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		memset(flow, 0, sizeof(flow));
		memset(gap, 0, sizeof(gap));
		memset(dist, 0, sizeof(dist));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &flow[i][j]);
				if (i == j)
					flow[i][j] = 0;
				else if (flow[i][j] == -1)
					flow[i][j] = inf;
			}
		scanf("%d%d", &s, &t);
		s++;
		t++;
		if (s == t)
			printf("inf\n");
		else {
			buildgraph();
			map[0][s] = inf;
			map[t][n + 1] = inf;
			n = n + 2;
			printf("%d\n", iSAP());
		}
	}
	return 0;
}
