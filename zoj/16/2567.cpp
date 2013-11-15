#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 610;
const int MAXM = 90000;
int mat[MAXN][MAXN];
int flow[MAXN][MAXN];
int rem[MAXN];
int x[MAXM], y[MAXM];

int max_flow(int n, const int mat[][MAXN], int source, int sink, int flow[][MAXN]) {
	int i, j, k;
	int p, q, t;
	int que[MAXN], pre[MAXN], d[MAXN];
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
	freopen("f:\\out.txt", "w", stdout);
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) if (mat[i][j] > 0) printf("%d %d %d\n", i, j, mat[i][j]);
	puts("");
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) if (flow[i][j] > 0) printf("%d %d %d\n", i, j, flow[i][j]);
	for (i=j=0; i<n; j+=flow[source][i++]) 
		if (flow[source][i] < mat[source][i]) return -1;
	return j;
}

int main() {
	int m, n, p;
	int i, j, k;
	int s, t;
	int S, T;
	int tot;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d %d", &m, &n, &p) != EOF) {
		s = 0, t = n + m + 1;
		S = t + 1, T = t + 2;
		for (i=0; i<=T; rem[i++]=0);
		rem[s] = -(m << 1), rem[t] = n << 1;
		for (i=1; i<=m; rem[i++]=2);
		for (i; i<t; rem[i++]=-2);
		for (i=0; i<=T; ++i) for (j=0; j<=T; mat[i][j++]=0);
		for (i=0; i<p; ++i) {
			scanf("%d %d", x+i, y+i);
			y[i] += m;
			mat[x[i]][y[i]] = 1;
		}
		for (i=1; i<=m; mat[s][i++]=INF);
		for (i; i<t; mat[i++][t]=INF);
		for (i=0; i<=T; ++i) {
			if (rem[i] >= 0) mat[S][i] = rem[i];
			else mat[i][T] = -rem[i];
		}
		tot = max_flow(n+m+4, mat, S, T, flow);
		if (tot == -1) {
			puts("-1");
		} else {
			vector<int> res;
			for (i=0; i<p; ++i) {
				if (flow[x[i]][y[i]] == 1) res.push_back(i+1);
			}
			printf("%d\n", res.size());
			for (i=0; i!=res.size(); ++i) printf("%s%d", i?" ":"", res[i]);
			puts("");
		}
	}
	return 0;
}