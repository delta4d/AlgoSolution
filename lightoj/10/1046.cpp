#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f;
const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int c[11][11], f[11][11], m, n;
char s[11][11];
queue <pair<int, int> > q;

void bfs(int sx, int sy, const int d) {
	memset(f, -1, sizeof(f));
	q.push(make_pair(sx, sy));
	f[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int k=0; k<8; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n || f[tx][ty] != -1) continue;
			f[tx][ty] = f[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}
	for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
		c[i][j] += f[i][j] == -1 ? INF : (f[i][j] + d - 1) / d;
	}
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &m, &n);
		for (int i=0; i<m; ++i) scanf("%s", s[i]);
		memset(c, 0, sizeof(c));
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (s[i][j] != '.') bfs(i, j, s[i][j]-'0');
		int mn = INF * 100 + 1;
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) mn = min(mn, c[i][j]);
		printf("Case %d: %d\n", ++cn, mn>=INF?-1:mn);
	}
	return 0;
}

// 307463	2014-01-04 22:55:31	 1046 - Rider	 C++	 0.012	 1248	Accepted
