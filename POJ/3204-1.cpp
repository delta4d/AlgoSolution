#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 500;
const int MAXM = 5000;

int mat[MAXN][MAXN];
int flow[MAXN][MAXN];
int a[MAXM], b[MAXM], c[MAXM];
int visit[MAXN];

int max_flow(int n, const int mat[][MAXN], int source, int sink, int flow[][MAXN]) {
	int i, j, k;
	int p, q, t;
	int que[MAXN], pre[MAXN], d[MAXN];
	if (source == sink) return INF;
	for (i=0; i<n; ++i) for (j=0; j<n; flow[i][j++]=0);
	while (true) {
		for (i=0; i<n; pre[i++]=0);
		pre[t=source] = source + 1;
		d[t] = INF;
		for (p=q=0; p<=q&&!pre[sink]; t=que[p++]) {
			for (i=0; i<n; ++i) {
				if (!pre[i] && (j = mat[t][i] - flow[t][i])) {
					pre[que[q++]=i] = t + 1;
					d[i] = min(d[t], j);
				} else if (!pre[i] && (j = flow[i][t])) {
					pre[que[q++]=i] = -t - 1;
					d[i] = min(d[t], j);
				}
			}
		}
		if (!pre[sink]) break;
		for (i=sink; i!=source; ) {
			if (pre[i] > 0) {
				flow[pre[i]-1][i] += d[sink];
				i = pre[i] - 1;
			} else {
				flow[i][-pre[i]-1] -= d[sink];
				i = -pre[i] - 1;
			}
		}
	}
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) {
		if (flow[i][j] <= 0) flow[i][j] = -flow[j][i];
		flow[i][j] = mat[i][j] - flow[i][j];
	}
	return 0;
}

void dfs_s(int s, const int n) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		if (!visit[i] && flow[s][i] > 0) {
			visit[i] = 1;
			dfs_s(i, n);
		}
	}
}

void dfs_t(int t, const int n) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		if (!visit[i] && flow[i][t] > 0) {
			visit[i] = -1;
			dfs_t(i, n);
		}
	}
}

int main() {
	int i, j, k;
	int m, n;	
	int s, t;
	int res;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (i=0; i<n; ++i) for (j=0; j<n; mat[i][j++]=0);
		s = 0, t = n - 1;
		for (i=0; i<m; ++i) {
			scanf("%d %d %d", a+i, b+i, c+i);
			mat[a[i]][b[i]] = max(mat[a[i]][b[i]], c[i]);
		}
		max_flow(n, mat, s, t, flow);
		for (i=0; i<n; visit[i++]=0);
		visit[s] = 1; dfs_s(s, n);
		visit[t] = -1; dfs_t(t, n);
		res = 0;
		for (i=0; i<m; ++i) {
			if (!flow[a[i]][b[i]])
			if (visit[a[i]] && visit[b[i]] && visit[a[i]]!=visit[b[i]]) ++res;
		}
		printf("%d\n", res);
		puts("");
	}
	return 0;
}