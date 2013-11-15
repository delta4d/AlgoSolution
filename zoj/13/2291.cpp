#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 21;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
char graph[MAXN][MAXN];
char temp[MAXN][MAXN];
int m, n;
int doorx[5], doory[5];
int cnt[5];
struct pos {
	int x;
	int y;
	pos(int _x=0, int _y=0):x(_x), y(_y) {}
};

inline bool border(const int x, const int y) {
	return x < m && x >= 0 && y < n && y >= 0;
}

bool bfs(const int sx, const int sy) {
	int i, j, k;
	int x, y, tx, ty;
	queue<pos> q;
	pos tt;
	q.push(pos(sx, sy));
	temp[sx][sy] = 'X';
	while (!q.empty()) {
		tt = q.front();
		q.pop();
		x = tt.x, y = tt.y;
		for (k=0; k<4; ++k) {
			tx = x + dx[k], ty = y + dy[k];
			if (border(tx, ty)) {
				if (temp[tx][ty] == 'X') {
					continue;
				} else if (temp[tx][ty] <= 'e' && temp[tx][ty] >= 'a') {
					i = temp[tx][ty] - 'a';
					--cnt[i];
					if (cnt[i] == 0) {
						graph[doorx[i]][doory[i]] = '.';
						temp[doorx[i]][doory[i]] = '.';
					}
					temp[tx][ty] = 'X';
					graph[tx][ty] = '.';
					q.push(pos(tx, ty));
				} else if (temp[tx][ty] <= 'E' && temp[tx][ty] >= 'A') {
					continue;
				} else if (temp[tx][ty] == 'G') {
					return true;
				} else if (temp[tx][ty] == '.') {
					temp[tx][ty] = 'X';
					q.push(pos(tx, ty));
				}
			}
		}
	}
	return false;
}

bool gao(const int sx, const int sy) {
	for (int i=0; i<5; ++i) {
		memcpy(temp, graph, sizeof(graph));
		if (bfs(sx, sy)) return true;
	}
	return bfs(sx, sy);
}

int main() {
	int i, j, k;
	int sx, sy;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	while (m != 0 || n != 0) {
		memset(cnt, 0, sizeof(cnt));
		for (i=0; i<m; ++i) {
			scanf("%s", graph[i]);
			for (j=0; j<n; ++j) {
				if (graph[i][j] == 'S') {
					sx = i, sy = j;
				} else if (graph[i][j] <= 'E' && graph[i][j] >= 'A') {
					doorx[graph[i][j]-'A'] = i, doory[graph[i][j]-'A'] = j;
				} else if (graph[i][j] <= 'e' && graph[i][j] >= 'a') {
					++cnt[graph[i][j]-'a'];
				}
			}
		}
		puts(gao(sx, sy)?"YES":"NO");
		scanf("%d %d", &m, &n);
	}
	return 0;
}