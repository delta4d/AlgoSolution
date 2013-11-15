#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20001;
const int offset = 10001;
const int INF = 0x3f3f3f3f;

struct node {
	int t;
	int w;
	node(int _t=0, int _w=0):t(_t), w(_w) {}
};
vector<node> graph[MAXN];
queue<int> q;
int d[MAXN];

void spfs() {
	int i, j, k;
	int u, v, w;
	q.push(0);
}

int main() {
	int i, j, k;
	int m, n;
	int x, y, w;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &k, &n) != EOF) {
		for (i=0; i<MAXN; ++i) graph[i].clear();
		for (i=0; i<MAXN; ++i) d[i] = INF;
		d[0] = 0;
		for (i=0; i<n; ++i) {
			scanf("%d %d", &x, &y);
			x += offset, y += offset;
			w = y - x + 1 >= k ? k - 1 : y - x;
			graph[x].push_back(node(y, w));
			graph[y].push_back(node(x, w));
		}
		while (!q.empty()) q.pop();
		spfs();
	}
	return 0;
}