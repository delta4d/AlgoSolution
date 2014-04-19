#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 10000 + 86;
const int MAXN = 100;
const int INF = 1000000000;

int N, M, C;
int mat[MAXN][MAXN*2], pre[MAXN];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

struct edge {
	int u, v, b, c;
	edge(int _u=0, int _v=0, int _b=0, int _c=0):u(_u), v(_v), b(_b), c(_c) {}
	inline void readin() {
		u = fastin<int>(), v = fastin<int>();
		b = fastin<int>(), c = fastin<int>();
	}
} e[MAXM];

template <class elemType> elemType edmonds(int n, elemType mat[][MAXN * 2], int * pre) {
    elemType ret = 0;
    int c[MAXN * 2][MAXN * 2], L[MAXN * 2], p[MAXN * 2], m = n, t, i, j, k;
    for (i = 0; i < n; L[i] = i, i++);
    do {
        memset(c, 0, sizeof(c));
        memset(p, 0xff, sizeof(p));
        for (t = m, i = 0; i < m; c[i][i] = 1, i++);
        for (i = 0; i < t; i++) {
            if (L[i] == i && pre[i] != -1) {
                for (j = 0; j < m; j++) {
                    if (L[j] == j && i != j && mat[j][i] < INF && (p[i] == -1 || mat[j][i] < mat[p[i]][i])) p[i] = j;
                }
                if ((pre[i] = p[i]) == -1) return -1;
                if (c[i][p[i]]) {
                    for (j = 0; j <= m; mat[j][m] = mat[m][j] = INF, j++);
                    for (k = i; L[k] != m; L[k] = m, k = p[k]) {
                        for (j = 0; j < m; j++) {
                            if (L[j] == j) {
                                if (mat[j][k] - mat[p[k]][k] < mat[j][m]) mat[j][m] = mat[j][k] - mat[p[k]][k];
                                if (mat[k][j] < mat[m][j]) mat[m][j] = mat[k][j];
                            }
                        }
                    }
                    c[m][m] = 1, L[m] = m, m++;
                }
                for (j = 0; j < m; j++) if (c[i][j]) for (k = p[i]; k != -1 && L[k] == k; c[k][j] = 1, k = p[k]);
            }
        }
    } while (t < m);
    for (; m-- > n; pre[k] = pre[m]) {
        for (i = 0; i < m; i++) {
            if (L[i] == m) {
                for (j = 0; j < m; j++) {
                    if (pre[j] == m && mat[i][j] == mat[m][j]) pre[j] = i;
                }
                if (mat[pre[m]][m] == mat[pre[m]][i] - mat[pre[i]][i]) k = i;
            }
        }
    }
    for (i = 0; i < n; i++) if (pre[i] != -1) ret += mat[pre[i]][i];
    return ret;
}

bool ok(int x) {
	memset(pre, 0, sizeof(pre));
	pre[0] = -1;
	for (int i=0; i<N; ++i) fill(mat[i], mat[i]+MAXN*2, INF);
	for (int i=0; i<M; ++i) if (e[i].b >= x) {
		int u = e[i].u, v = e[i].v, c = e[i].c;
		mat[u][v] = min(mat[u][v], c);
	}
	int d = edmonds<int>(N, mat, pre);
	return d < 0 ? false : (d <= C);
}

int main() {
	int tc, cn = 0;
	for (tc=fastin<int>(); tc--; ) {
		N = fastin<int>(), M = fastin<int>(), C = fastin<int>();
		for (int i=0; i<M; ++i) e[i].readin();
		int left = 0, right = 1000000 + 86, mid, p = -1;
		while (left <= right) {
			mid = left + ((right - left) >> 1);
			if (ok(mid)) left = mid + 1, p = mid;
			else right = mid - 1;
		}
		printf("Case %d: ", ++cn);
		if (p == -1) puts("impossible");
		else printf("%d kbps\n", p);
	}
	return 0;
}

// 260709	2013-09-09 13:38:13	 1384 - Stream My Contest	 C++	 0.072	 1364	Accepted
