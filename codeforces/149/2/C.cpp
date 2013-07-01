#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

const int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};

struct node {
	int x, y, p;
	node(int _x=0, int _y=0, int _p=0):x(_x), y(_y), p(_p) {}
};

map <int, set<int> > e;
set <pair<int, int> > v;
queue <node> q;

int main() {
	int sx, sy, tx, ty;
	int m;

	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	scanf("%d", &m);
	for (int r, a, b; m--; ) {
		scanf("%d%d%d", &r, &a, &b);
		for (int i=a; i<=b; ++i) e[r].insert(i);
	}
	q.push(node(sx, sy, 0));
	v.insert(make_pair(sx, sy));
	while (!q.empty()) {
		node tt = q.front();
		q.pop();
		int x = tt.x, y = tt.y, p = tt.p;
		if (x == tx && y == ty) return printf("%d\n", p), 0;
		for (int k=0; k<8; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (v.find(make_pair(tx, ty)) != v.end() || e[tx].find(ty) == e[tx].end()) continue;
			q.push(node(tx, ty, p+1));
			v.insert(make_pair(tx, ty));
		}
	}
	puts("-1");

	return 0;
}

// 3999977	 Jul 1, 2013 6:28:24 PM	delta_4d	 C - King's Path	 GNU C++	Accepted	 156 ms	 7900 KB
