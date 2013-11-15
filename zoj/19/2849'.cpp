#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 500;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
int m, n;
struct virus {
	int x;
	int y;
	int type;
	int attack;
	virus(int x=0, int y=0, int t=0, int a=0):x(x), y(y), type(t), attack(a) {}
};

bool operator<(const virus &a, const virus &b) {
	if (a.attack != b.attack) return a.attack > b.attack;
	return a.type > b.type;
}

priority_queue<virus> q;
int graph[MAXN][MAXN];
int num[MAXN*MAXN+1];

int main() {
	int i, j, k;
	int r, s, t;
	int x, y, tx, ty;
	virus cc;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &m, &n) != EOF) {
		while (!q.empty()) q.pop();
		memset(num, 0, sizeof(num));
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				scanf("%d", graph[i]+j);
				if (graph[i][j] > 0) {
					++num[graph[i][j]];
					q.push(virus(i, j, graph[i][j], 1));
				}
			}
		}
		while(!q.empty()) {
			cc = q.top();
			q.pop();
			x = cc.x, y = cc.y;
			t = -INF;
			for (k=0; k<4; ++k) {
				tx = x + dx[k], ty = y + dy[k];
				if (tx < m && tx >= 0 && ty < n && ty >= 0) {
					if (graph[tx][ty] < 0) {
						if (graph[tx][ty] + cc.attack >= 0) {
							graph[tx][ty] = cc.type;
							++num[cc.type];
							q.push(virus(tx, ty, cc.type, cc.attack));
						} else {
							if (graph[tx][ty] > t) t = graph[tx][ty];
						}
					}
				}
			}
			if (t != -INF) q.push(virus(x, y, cc.type, -t));
		}
		//for (i=0; i<m; ++i) for (j=0; j<n; ++j) ++num[graph[i][j]];
		scanf("%d", &s);
		for (i=0; i<s; ++i) {
			scanf("%d", &r);
			printf("%d\n", num[r]);
		}
	}
	return 0;
}