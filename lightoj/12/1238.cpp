#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

char s[22][22];
int p[22][22];
int m, n;
queue <pair<int, int> > q;

inline bool in(int x, int y) { return 0 <= x && x < m && 0 <= y && y < n; }

int gao(int sx, int sy) {
	memset(p, -1, sizeof(p));
	while (!q.empty()) q.pop();
	q.push(make_pair(sx, sy));
	p[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		if (s[x][y] == 'h') return p[x][y];
		q.pop();
		for (int k=0; k<4; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (!in(tx, ty) || p[tx][ty] != -1 || s[tx][ty] == '#' || s[tx][ty] == 'm') continue;
			p[tx][ty] = p[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}
	return -1;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &m, &n);
		for (int i=0; i<m; ++i) scanf("%s", s[i]);
		int tot = 0;
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
			if (s[i][j] == 'a' || s[i][j] == 'b' || s[i][j] == 'c') tot = max(tot, gao(i, j));
		}
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 298906	2013-12-12 21:35:52	 1238 - Power Puff Girls	 C++	 0.004	 1248	Accepted
