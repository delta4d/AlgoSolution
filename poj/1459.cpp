#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int INF = 0x3f3f3f3f;

int mat[MAXN][MAXN];
int flow[MAXN][MAXN];

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

int main() {
	int i, j, k;
	int m, n;
	int nc, np;
	int u, v, z;
	int s, t;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d %d %d", &n, &np, &nc, &m) != EOF) {
		s = 0, t = n + 1;
		memset(mat, 0, sizeof(mat));
		for (i=0; i<m; ++i) {
			scanf(" (%d,%d)%d", &u, &v, &z);
			++u, ++v;
			mat[u][v] = z;
		}
		for (i=0; i<np; ++i) {
			scanf(" (%d)%d", &u, &z);
			mat[s][u+1] = z;
		}
		for (i=0; i<nc; ++i) {
			scanf(" (%d)%d", &u, &z);
			mat[u+1][t] = z;
		}
		printf("%d\n", maxFlow(n+2, mat, s, t, flow));
	}
	return 0;
}