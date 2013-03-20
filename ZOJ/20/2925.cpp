#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 16;
const int MAXN = 512;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
char f[MAXN][MAXN];
bool visit[MAXN][MAXN];

struct node {
	int x;
	int y;
	char dir;
	node(int x=0, int y=0, char dir='x'):x(x), y(y), dir(dir) {}
};

inline bool border(const int m, const int n, const int x, const int y) {
	return x < m && x >=0 && y < n && y >= 0;
}

void gao(const int m, const int n, const int sx, const int sy, const char d) {
	int i, j, k;
	int x, y, tx, ty;
	char dir;
	queue<node> q;
	node tt;
	
	memset(visit, false, sizeof(visit));
	q.push(node(sx, sy, d));
	visit[sx][sy] = true;
	f[sx][sy] = d;
	while (!q.empty()) {
		tt = q.front();
		q.pop();
		x = tt.x, y = tt.y, dir = tt.dir;
		switch (dir) {
			case 'W': {
				tx = x - 1, ty = y - 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'V'));
						f[tx][ty] = 'V';
					}
				}
				tx = x, ty = y - 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'W'));
						f[tx][ty] = 'W';
					}
				}
				tx = x + 1, ty = y - 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'J'));
						f[tx][ty] = 'J';
					}
				}
			} break;
			case 'N': {
				tx = x - 1, ty = y - 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'V'));
						f[tx][ty] = 'V';
					}
				}
				tx = x - 1, ty = y;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'N'));
						f[tx][ty] = 'N';
					}
				}
				tx = x - 1, ty = y + 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'Y'));
						f[tx][ty] = 'Y';
					}
				}
			} break;
			case 'S': {
				tx = x + 1, ty = y - 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'J'));
						f[tx][ty] = 'J';
					}
				}
				tx = x + 1, ty = y;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'S'));
						f[tx][ty] = 'S';
					}
				}
				tx = x + 1, ty = y + 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'Q'));
						f[tx][ty] = 'Q';
					}
				}
			} break;
			case 'E': {
				tx = x - 1, ty = y + 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'Y'));
						f[tx][ty] = 'Y';
					}
				}
				tx = x, ty = y + 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'E'));
						f[tx][ty] = 'E';
					}
				}
				tx = x + 1, ty = y + 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'Q'));
						f[tx][ty] = 'Q';
					}
				}
			} break;
			case 'V': {
				tx = x, ty = y - 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'W'));
						f[tx][ty] = 'W';
					}
				}
				tx = x - 1, ty = y - 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'V'));
						f[tx][ty] = 'V';
					}
				}
				tx = x - 1, ty = y;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'N'));
						f[tx][ty] = 'N';
					}
				}
			} break;
			case 'Y': {
				tx = x - 1, ty = y;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'N'));
						f[tx][ty] = 'N';
					}
				}
				tx = x - 1, ty = y + 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'Y'));
						f[tx][ty] = 'Y';
					}
				}
				tx = x, ty = y + 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'E'));
						f[tx][ty] = 'E';
					}
				}
			} break;
			case 'Q': {
				tx = x, ty = y + 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'E'));
						f[tx][ty] = 'E';
					}
				}
				tx = x + 1, ty = y + 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'Q'));
						f[tx][ty] = 'Q';
					}
				}
				tx = x + 1, ty = y;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'S'));
						f[tx][ty] = 'S';
					}
				}
			} break;
			case 'J': {
				tx = x + 1, ty = y;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'S'));
						f[tx][ty] = 'S';
					}
				}
				tx = x + 1, ty = y - 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'J'));
						f[tx][ty] = 'J';
					}
				}
				tx = x, ty = y - 1;
				if (border(m, n, tx, ty) && !visit[tx][ty]) {
					if (f[tx][ty] == 'X') {
						visit[tx][ty] = true;
						q.push(node(tx, ty, 'W'));
						f[tx][ty] = 'W';
					}
				}
			} break;
			default : break;
		}
	}
}

int main() {
	int m, n;
	int i, j, k;
	int x, y;
	char dir[MAXL];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	while (true) {
		for (i=0; i<m; ++i) scanf("%s", f[i]);
		scanf("%d %d %s", &x, &y, dir);
		--x, --y;
		gao(m, n, x, y, dir[0]);
		for (i=0; i<m; ++i) puts(f[i]);
		if (scanf("%d %d", &m, &n) == EOF) break;
		puts("");
	}
	return 0;
}