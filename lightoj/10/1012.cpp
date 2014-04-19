#include <queue>
#include <cstdio>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
char s[21][21];
int m, n;

int gao(int sx, int sy) {
	int tot = 1;
	queue <pair<int, int> > q;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int k=0; k<4; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n || s[tx][ty] != '.') continue;
			s[tx][ty] = 'x';
			++tot;
			q.push(make_pair(tx, ty));
		}
	}
	return tot;
}

int main() {
	int tc, cn = 0, sx, sy;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<m; ++i) {
			scanf("%s", s[i]);
			for (int j=0; j<n; ++j) if (s[i][j] == '@') sx = i, sy = j;
		}
		printf("Case %d: %d\n", ++cn, gao(sx, sy));
	}
	return 0;
}

// 293394	2013-11-30 19:08:14	 1012 - Guilty Prince	 C++	 0.000	 1248	Accepted
