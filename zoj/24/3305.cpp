#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 34;
int mat[MAXN][MAXN];
int flow[MAXN][MAXN];
int f[MAXN];
/*
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
}*/

int max_flow(int n, const int mat[][MAXN], int source, int sink, int flow[][MAXN]) {
	int i, j, k;
	int p, q, t;
	int que[MAXN], pre[MAXN], d[MAXN];
	if (source == sink) return INF;
	//memset(flow, 0, sizeof(flow));
	for (i=0; i<n; ++i) for (j=0; j<n; flow[i][j++]=0);
	while (true) {
		memset(pre, 0, sizeof(pre));
		pre[t=source] = source + 1;
		d[t] = INF;
		for (p=q=0; p<=q&&!pre[sink]; t=que[p++]) {
			for (i=0; i<n; ++i) {
				if (!pre[i] &&  (j = mat[t][i] - flow[t][i])) {
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
	for (i=j=0; i<n; j+=flow[source][i++]);
	return j;
}

int main() {
	int i, j, k;
	int m, n;
	int s, t;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF) {
		memset(mat, 0, sizeof(mat));
		s = 0, t = (n << 1) + 1;
		for (i=0; i<m; ++i) {
			scanf("%d", &k);
			for (j=0; j<k; scanf("%d", f+(j++)));
			//sort(f, f+k);
			mat[s][f[0]] = 1, mat[f[k-1]][f[k-1]+n] = 1, mat[f[k-1]+n][t] = 1;
			for (j=0; j<k-1; ++j) {
				mat[f[j]][f[j]+n] = 1;
				mat[f[j]+n][f[j+1]] = 1;
			}
		}	
		printf("%d\n", max_flow((n+1)<<1, mat, s, t, flow));
	}
	return 0;
}