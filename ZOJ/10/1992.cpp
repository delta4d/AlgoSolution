#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 202;
const int INF = 0x3f3f3f3f;
int mat[MAXN][MAXN];
int flow[MAXN][MAXN];
int d[MAXN];

int max_flow(int n, const int mat[][MAXN], int source, int sink, int flow[][MAXN]) {
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
	int x, y, w;
	int m, n;
	int s, t;
	int tc;
	int tot;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		memset(mat, 0, sizeof(mat));
		memset(d, 0, sizeof(d));
		s = 0, t = n + 1, tot = 0;
		for (i=0; i<m; ++i) {
			scanf("%d %d %d", &x, &y, &w);
			++d[x], --d[y];
			if (w != 1) ++mat[x][y];
		}
		for (i=1; i<=n; ++i) {
			if (d[i] & 0x1) break;
			d[i] >>= 1;
			if (d[i] > 0) {
				mat[s][i] = d[i];
				tot += d[i];
			} else {
				mat[i][t] = -d[i];
			}
		}
		if (i <= n) {
			puts("impossible");
		} else {
			if (tot == max_flow(n+2, mat, s, t, flow)) puts("possible");
			else puts("impossible");
		}
	}
	return 0;
}