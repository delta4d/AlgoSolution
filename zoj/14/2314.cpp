#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 202;
const int MAXM = 20000;
int mat[MAXN][MAXN];
int flow[MAXN][MAXN];
int rem[MAXN];
int x[MAXM], y[MAXM], l[MAXM];

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
	for (i=j=0; i<n; j+=flow[source][i++]) 
		if (flow[source][i] < mat[source][i]) return -1;
	return j;
}

int main() {
	int i, j, k;
	int tc;
	int m, n;
	int s, t;
	int u, v, c;
	int tot;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		s = 0, t = n + 1;
		for (i=0; i<=t; rem[i++]=0);
		for (i=0; i<=t; ++i) for (j=0; j<=t; mat[i][j++]=0);
		for (i=0; i<m; ++i) {
			scanf("%d %d %d %d", x+i, y+i, l+i, &c);
			rem[x[i]] -= l[i];
			rem[y[i]] += l[i];
			mat[x[i]][y[i]] = c - l[i];
		}
		for (i=0; i<=t; ++i) {
			if (rem[i] > 0) mat[s][i] = rem[i];
			else mat[i][t] = -rem[i];
		}
		tot = max_flow(n+2, mat, s, t, flow);
		if (tot == -1) {
			puts("NO");
		} else {
			puts("YES");
			for (i=0; i<m; ++i) printf("%d\n", flow[x[i]][y[i]]+l[i]);
		}
		puts("");
	}
	return 0;
}