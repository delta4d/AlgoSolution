#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 111;
const int MAXL = 1000;
int mat[MAXN][MAXN];
int flow[MAXN][MAXN];
int a[MAXL], b[MAXL], c[MAXL];
int visit[MAXN];
vector<int> res;

void max_flow(int n, const int mat[][MAXN], int source, int sink, int flow[][MAXN]) {
	int i, j, k;
	int p, q, t;
	int que[MAXN], pre[MAXN], d[MAXN];
	//if (source == sink) return INF;
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
}

void dfs_s(int s, const int n) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		if (!visit[i] && (mat[s][i] > flow[s][i] || flow[i][s])) {
			visit[i] = 1;
			dfs_s(i, n);
		}
	}
}

void dfs_t(int t, const int n) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		if (!visit[i] && (mat[i][t] > flow[i][t] || flow[t][i])) {
			visit[i] = -1;
			dfs_t(i, n);
		}
	}
}

int main() {
	int i, j, k;
	int m, n, l;
	int s, t;
	int tot;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d %d %d", &n, &m, &l);
	while (n != 0) {
		s = n + m + 1, t = 0;
		k = s + 1;
		for (i=0; i<k; ++i) for (j=0; j<k; mat[i][j++]=0);
		for (i=0; i<l; ++i) {
			scanf("%d %d %d", a+i, b+i, c+i);
			mat[a[i]][b[i]] = max(mat[a[i]][b[i]], c[i]);
		}
		for (i=1; i<=n; ++i) mat[s][i] = INF;
		max_flow(k, mat, s, t, flow);
		for (i=0; i<k; visit[i++]=0);
		visit[s] = 1; dfs_s(s, k);
		visit[t] = -1; dfs_t(t, k);
		res.clear();
		for (i=0; i<l; ++i) {
			if (flow[a[i]][b[i]] == mat[a[i]][b[i]])
			if (visit[a[i]]==1 && visit[b[i]] ==-1) res.push_back(i+1);
		}
		for (i=0; i!=res.size(); ++i) printf("%s%d", i?" ":"", res[i]);
		puts("");
		scanf("%d %d %d", &n, &m, &l);
	}
	return 0;
}