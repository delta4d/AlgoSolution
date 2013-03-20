#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 500;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int tot;
int m, n;
struct node {
	int x;
	int y;
	node(int _x=0, int _y=0):x(_x), y(_y) {}
};
typedef vector<node> V;

V virus[MAXN*MAXN+1];
int graph[MAXN][MAXN];

inline bool border(const int x, const int y) {
	return x < m && x >= 0 && y < n && y >= 0;
}

void bfs(const int sx, const int sy, const int type, const int day) {
	int i, j, k;
	int x, y, tx, ty;
	node cc;
	queue<node> q;
	q.push(node(sx, sy));
	while (!q.empty()) {
		cc = q.front();
		q.pop();
		x = cc.x, y = cc.y;
		for (k=0; k<4; ++k) {
			tx = x + dx[k], ty = y + dy[k];
			if (border(tx, ty)) {
				if (graph[tx][ty] < 0 && day + graph[tx][ty] >= 0) {
					graph[tx][ty] = type;
					virus[type].push_back(node(tx, ty));
					--tot;
					q.push(node(tx, ty));
				}
			}
		}
	}
}

void gao() {
	int i, j, k;
	int r, s, t(m*n);
	for (i=1; tot!=0; ++i) {
		for (k=1; k<=t; ++k) {
			for (j=0; j!=virus[k].size(); ++j) {
				bfs(virus[k][j].x, virus[k][j].y, k, i);
			}
		}
	}
}

int main() {
	int i, j, k;
	int r, s, t;
	int q;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &m, &n) != EOF) {
		tot = m * n;
		for (i=0; i<=tot; ++i) virus[i].clear();
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				scanf("%d", graph[i]+j);
				if (graph[i][j] > 0) {
					virus[graph[i][j]].push_back(node(i, j));
					--tot;
				}
			}
		}
		gao();
		scanf("%d", &q);
		for (i=0; i<q; ++i) {
			scanf("%d", &r);
			printf("%d\n", virus[r].size());
		}
	}
	return 0;
}