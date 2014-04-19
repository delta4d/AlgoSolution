#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

char s[12][12];
int p[12][12];
queue <pair<int, int> > q;

int gao(int sx, int sy, int &rx, int &ry, const int n, const char c) {
	memset(p, -1, sizeof(p));
	while (!q.empty()) q.pop();
	q.push(make_pair(sx, sy));
	p[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		if (s[x][y] == c) return s[rx=x][ry=y]='.', p[x][y];
		for (int k=0; k<4; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n || p[tx][ty] != -1) continue;
			if (s[tx][ty] == '.' || s[tx][ty] == c) {
				p[tx][ty] = p[x][y] + 1;
				q.push(make_pair(tx, ty));
			}
		}
	}
	return -1;
}

int main() {
	int tc, cn = 0, n, m, ax, ay;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n), m = 0;
		for (int i=0; i<n; ++i) {
			scanf("%s", s[i]);
			for (int j=0; s[i][j]; ++j) if ('A' <= s[i][j] && s[i][j] <= 'Z') {
				++m;
				if (s[i][j] == 'A') ax = i, ay = j, s[i][j] = '.';
			}
		}
		int tot = 0, cx = ax, cy = ay;
		for (int i=1; i<m; ++i) {
			int cc = gao(cx, cy, ax, ay, n, 'A'+i);
			if (cc == -1) {
				tot = -1;
				break;
			}
			tot += cc;
			cx = ax, cy = ay;
		}
		printf("Case %d: ", ++cn);
		if (tot == -1) puts("Impossible");
		else printf("%d\n", tot);
	}
	return 0;
}

// 296261	2013-12-06 22:19:21	 1066 - Gathering Food	 C++	 0.004	 1248	Accepted
