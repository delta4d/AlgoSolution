#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 201;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int m, n;
char s[N][N];
int f[N][N];
int e[N][N], sx, sy;
vector <pair<int, int> > fire;
queue <pair<int, int> > q;

inline bool in(int x, int y) { return 0 <= x && x < m && 0 <= y && y < n; }

void expand_fire() {
	for (int i=0; i<m; ++i) fill(f[i], f[i]+n, INF);
	while (!q.empty()) q.pop();
	for (int i=0; i<(int)fire.size(); ++i) {
		q.push(fire[i]);
		f[fire[i].first][fire[i].second] = 0;
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int k=0; k<4; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (!in(tx, ty) || s[tx][ty] == '#' || f[tx][ty] < INF) continue;
			f[tx][ty] = f[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}
}

int escape(int sx, int sy) {
	memset(e, -1, sizeof(e));
	while (!q.empty()) q.pop();
	q.push(make_pair(sx, sy));
	e[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		int p = e[x][y];
		for (int k=0; k<4; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (!in(tx, ty)) return p + 1;
			if (s[tx][ty] == '#' || e[tx][ty] != -1 || f[tx][ty] <= p + 1) continue;
			e[tx][ty] = p + 1;
			q.push(make_pair(tx, ty));
		}
	}
	return -1;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &m, &n);
		fire.clear();
		for (int i=0; i<m; ++i) {
			scanf("%s", s[i]);
			for (int j=0; j<n; ++j) {
				if (s[i][j] == 'F') fire.push_back(make_pair(i, j));
				else if (s[i][j] == 'J') sx = i, sy = j;
			}
		}
		expand_fire();
		int t = escape(sx, sy);
		printf("Case %d: ", ++cn);
		if (t == -1) puts("IMPOSSIBLE");
		else printf("%d\n", t);
	}
	return 0;
}

// 300626	2013-12-17 22:42:38	 1175 - Jane and the Frost Giants	 C++	 0.088	 2132	Accepted
