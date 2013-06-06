#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct node {
	int x, y;
	int d;

	node(int _x=0, int _y=0, int _d=0):x(_x), y(_y), d(_d) {}
};

queue <node> q;
bool v[101][100001];
int n, a[101];

int bfs(int r1, int c1, int r2, int c2) {
	q.push(node(r1, c1, 0));
	v[r1][c1] = true;
	while (!q.empty()) {
		node t = q.front();
		q.pop();
		int x = t.x, y = t.y, d = t.d;
		if (x == r2 && y == c2) return d;
		for (int k=0; k<4; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (tx < 0 || tx >= n) continue;
			ty = min(max(0, ty), a[tx]);
			if (v[tx][ty]) continue;
			q.push(node(tx, ty, d+1));
			v[tx][ty] = true;
		}
	}
	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int r1, c1, r2, c2;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	printf("%d\n", bfs(r1-1, c1-1, r2-1, c2-1));

	return 0;
}

// 3823759	 Jun 5, 2013 10:09:13 AM	delta_4d	 C - Text Editor	 GNU C++	Accepted	 171 ms	 10100 KB
