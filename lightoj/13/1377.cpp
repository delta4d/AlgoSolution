#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int N = 201;
const int INF = 0x3f3f3f3f;

char s[N][N];
int m, n, star, sx, sy, ex, ey;
queue <pair<int, int> > q;
int d[N][N], err;
vector <pair<int,int> > a, b;

void bfs() {
	while (!q.empty()) q.pop();
	memset(d, 0xff, sizeof(d));
	q.push(make_pair(sx, sy));
	d[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int k=0; k<4; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n || s[tx][ty] == '#' || s[tx][ty] == '*' || d[tx][ty] != -1) continue;
			d[tx][ty] = d[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}
	err = d[ex][ey];
}

int back(int sx, int sy, vector <pair<int,int> > &a) {
	a.clear();
	while (!q.empty()) q.pop();
	memset(d, 0xff, sizeof(d));
	q.push(make_pair(sx, sy));
	d[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int k=0; k<4; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n || s[tx][ty] == '#' || d[tx][ty] != -1) continue;
			d[tx][ty] = d[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}
	int mn = INF;
	for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (s[i][j] == '*' && d[i][j] != -1) {
		if (d[i][j] < mn) mn = d[i][j], a.clear(), a.push_back(make_pair(i, j));
		else if (d[i][j] == mn) a.push_back(make_pair(i, j));
	}
	return mn;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &m, &n);
		star = 0;
		for (int i=0; i<m; ++i) {
			scanf("%s", s[i]);
			for (int j=0; j<n; ++j) {
				if (s[i][j] == 'P') sx = i, sy = j;
				else if (s[i][j] == 'D') ex = i, ey = j;
				else if (s[i][j] == '*') ++star;
			}
		}
		bfs();
		printf("Case %d: ", ++cn);
		if (star <= 1) {
			if (err == -1) puts("impossible");
			else printf("%d\n", d[ex][ey]);
		} else {
			int ma = back(sx, sy, a), mb = back(ex, ey, b);
			int mn = err == -1 ? INF : err;
			if (a.size() > 1 || b.size() > 1) {
				mn = min(mn, ma+mb+1);
			} else if (a.size() == 1 && b.size() == 1) {
				if (a[0] != b[0]) mn = min(mn, ma+mb+1);
				else mn = min(mn, ma+mb+2);
			}
			if (mn < INF) printf("%d\n", mn);
			else puts("impossible");
		}
	}
	return 0;
}

// 308758	2014-01-08 01:06:51	 1377 - Blade and Sword	 C++	 0.064	 1448	Accepted
