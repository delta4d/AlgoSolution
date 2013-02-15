#include <queue>
#include <cstdio>
#include <memory>
using namespace std;

#define WALL '*'
const int MAXN = 51;
const int dx[5] = {-1, 0, 1, 0, 0};
const int dy[5] = {0, -1, 0, 1, 0};
int m, n, d;
int sx, sy, ex, ey, fx, fy;
char order[MAXN];
char graph[MAXN][MAXN];
bool visit[MAXN][MAXN][MAXN];
struct node {
	int x;
	int y;
	int step;
	int depth;
	int dir;
	node(int x=0, int y=0, int s=0, int de=0, int di=0):x(x), y(y),step(s), depth(de), dir(di) {}
}dog[MAXN];

inline void init_dog() {
	int i, j, k;
	dog[0].x = fx, dog[0].y = fy, dog[0].dir = 0;
	for (i=0; i<d; ++i) {
		if (order[i] == 'G') {
			dog[i+1].x = dog[i].x + dx[dog[i].dir];
			dog[i+1].y = dog[i].y + dy[dog[i].dir];
			dog[i+1].dir = dog[i].dir;
		} else if (order[i] == 'L') {
			dog[i+1].x = dog[i].x, dog[i+1].y = dog[i].y;
			dog[i+1].dir = (dog[i].dir == 3 ? 0 : dog[i].dir + 1);
		} else {
			dog[i+1].x = dog[i].x, dog[i+1].y = dog[i].y;
			dog[i+1].dir = (dog[i].dir == 0 ? 3 : dog[i].dir - 1);
		}
	}
}

inline bool in(const int x, const int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}

inline bool legal(const int tx, const int ty, const int k) {
	int i, j;
	int x(dog[k].x), y(dog[k].y), d(dog[k].dir);
	while (graph[x][y] != WALL && in(x, y)) {
		if (x == tx && y == ty) return false;
		x += dx[d], y += dy[d];
	}
	return true;
}

bool bfs(int &len) {
	int step, depth;
	int i, j, k;
	int x, y, tx, ty;
	queue<node> q;
	node ss, t;
	memset(visit, false, sizeof(visit));
	visit[sx][sy][0] = true;
	q.push(node(sx, sy, 0, 0, -1));
	while (!q.empty()) {
		ss = q.front();
		q.pop();
		if (ss.x == ex && ss.y == ey) {
			len = ss.step;
			return true;
		}
		for (k=0; k<5; ++k) {
			tx = ss.x + dx[k], ty = ss.y + dy[k];
			step = ss.step + 1, depth = ss.depth + 1;
			//if (depth == d + 1) depth = 0;
			if (in(tx, ty) && legal(tx, ty, depth) && graph[tx][ty] != WALL && 
				!visit[tx][ty][depth] && (tx != dog[depth].x || ty != dog[depth].y)) {
				if (tx == ex && ty == ey) {
					len = step;
					return true;
				}
				visit[tx][ty][depth] = true;
				if (depth == d) depth = 0;
				q.push(node(tx, ty, step, depth, -1));
			}
		}
	}
	return false;
}

int main() {
	int cn(0);
	int len;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	while (true) {
		scanf("%d %d %d %d %d %d %d", &sx, &sy, &ex, &ey, &fx, &fy, &d);
		--sx, --sy, --ex, --ey, --fx, --fy;
		scanf("%s", order);
		init_dog();
		for (i=0; i<m; ++i) scanf("%s", graph[i]);
		printf("Case %d:\n", ++cn);
		if (bfs(len)) printf("Minimal time is: %d\n", len);
		else printf("No way out\n");
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0) break;
		puts("");
	}
	return 0;
}
