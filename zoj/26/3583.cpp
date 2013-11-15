#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;

bool org[MAXN][MAXN];
bool f[MAXN][MAXN];
int m, n, s, t;
queue <int> q;
bool visit[MAXN], mark[MAXN];

bool gao(const int root) {
	int i, j, k;
	int tt;
	
	while (!q.empty()) q.pop();
	q.push(root);
	mark[root] = true;
	while (!q.empty()) {
		tt = q.front();
		q.pop();
		for (i=0; i<n; ++i) {
			if (f[tt][i] && !mark[i]) {
				mark[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	int i, j, k;
	int x, y;
	int tot;
	
//	freopen("in.txt", "r", stdin);
	
	while (4 == scanf("%d %d %d %d", &n, &m, &s, &t)) {
		memset(org, false, sizeof(org));
		for (i=0; i<m; ++i) {
			scanf("%d %d", &x, &y);
			org[x][y] = org[y][x] = true;
		}
		memset(visit, false, sizeof(visit));
		for (tot=k=0; k<n; ++k) {
			for (i=0; i<n; ++i) for (j=0; j<n; ++j) f[i][j] = org[i][j];
			for (i=0; i<n; ++i) f[i][k] = f[k][i] = false;
			memset(mark, false, sizeof(mark));
			if (s != k) gao(s);
			if (t != k) gao(t);
			for (i=0; i<n; ++i) if (i != k && !mark[i]) visit[i] = true;
		}
		visit[s] = visit[t] = false;
		for (i=0; i<n; ++i) if (visit[i]) ++tot;
		printf("%d\n", tot);
	}
	return 0;
}