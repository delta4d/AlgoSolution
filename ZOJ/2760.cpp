#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int INF = 0x3f3f3f3f;

int mat[MAXN][MAXN];
int flow[MAXN][MAXN];
int graph[MAXN][MAXN];
int d[MAXN][MAXN];

int maxFlow(int n, const int mat[][MAXN], int source, int sink, int flow[][MAXN]) {
    int pre[MAXN], que[MAXN], d[MAXN], p, q, t, i, j;
    
    if (source == sink) return INF;
    for (i=0; i<n; i++) for (j=0; j<n; flow[i][j++]=0);
    
    while (true) {
        for (i=0; i<n; pre[i++]=0);
        pre[t=source] = source + 1;
        d[t] = INF;
        for (p = q = 0; p <= q && !pre[sink]; t = que[p++]) {
            for (i = 0; i < n; i++) {
                if (!pre[i] && (j = mat[t][i] - flow[t][i])) {
                    pre[que[q++] = i] = t + 1;
                    d[i] = d[t] < j ? d[t] : j;
                } else if (!pre[i] && (j = flow[i][t])) {
                    pre[que[q++] = i] = -t - 1;
                    d[i] = d[t] < j ? d[t] : j;
                }
            }
        }
        if (!pre[sink]) break;

        for (i = sink; i != source;) {
            if (pre[i] > 0) {
                flow[pre[i] - 1][i] += d[sink];
                i = pre[i] - 1;
            } else {
                flow[i][-pre[i] - 1] -= d[sink];
                i = -pre[i] - 1;
            }
        }
    }
    for (j = i = 0; i < n; j += flow[source][i++]);
    return j;
}

void gao(const int n, const int s, const int t) {
	int i, j, k;
	if (s == t) {
		puts("inf");
		return;
	}
	for (k=0; k<n; ++k) {
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	memset(mat, 0, sizeof(mat));
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) {
			if (d[s][i] + graph[i][j] + d[j][t] == d[s][t]) mat[i][j] = 1;
		}
	}
	printf("%d\n", maxFlow(n, mat, s, t, flow));
}

int main() {
	int i, j, k;
	int m, n;
	int s, t;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j) {
				scanf("%d", graph[i]+j);
				d[i][j] = graph[i][j];
				if (d[i][j] == -1) d[i][j] = INF;
				if (i == j) d[i][i] = graph[i][i] = 0;
			}
		}
		scanf("%d %d", &s, &t);
		gao(n, s, t);
	}
	return 0;
}