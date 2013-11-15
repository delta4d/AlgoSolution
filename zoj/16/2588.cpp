#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int NOT_VISITED = -1;
const int PAR_VISITED = 0;
const int ALL_VISITED = 1;
const int MAXN = 10001;
int m, n;
int ancestor[MAXN], c[MAXN], d[MAXN];
struct node {
	int dst;
	int index;
	node(int d=0, int i=0):dst(d), index(i) {}
};
struct edge {
	int x;
	int y;
	edge(int x=0, int y=0):x(x), y(y) {}
};
vector<int> res;
vector<node> e[MAXN];
set<edge> all, dup;

bool operator<(const edge &a, const edge &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

inline void input() {
	int x, y;
	int i, j, k;
	scanf("%d %d", &n, &m);
	all.clear(); dup.clear();
	for (i=1; i<=n; ++i) e[i].clear();
	for (i=1; i<=m; ++i) {
		scanf("%d %d", &x, &y);
		if (x > y) swap(x, y);
		edge tt(x, y);
		if (all.find(tt) == all.end()) {
			all.insert(tt);
			e[x].push_back(node(y, i));
			e[y].push_back(node(x, i));
		} else {
			dup.insert(tt);
		}
	}
}

void dfs(const int root, const int parent, int depth) {
	int i, j, k;
	c[root] = PAR_VISITED;
	d[root] = depth;
	ancestor[root] = depth;
	
	for (i=0; i!=e[root].size(); ++i) {
		k = e[root][i].dst;
		if (k == parent) continue;
		if (c[k] == PAR_VISITED) {
			ancestor[root] = min(ancestor[root], d[k]);
		} else if (c[k] == NOT_VISITED) {
			dfs(k, root, depth+1);
			ancestor[root] = min(ancestor[root], ancestor[k]);
			if (ancestor[k] > d[root]) {
				int tk(k), tr(root);
				if (tk > tr) swap(tk, tr);
				if (dup.find(edge(tk, tr)) == dup.end()) res.push_back(e[root][i].index);
			}
		}
	}
	c[root] = ALL_VISITED;
}

void gao() {
	int i, j, k;
	res.clear();
	memset(c, NOT_VISITED, sizeof(c));
	dfs(1, -1, 1);
	printf("%d\n", k = res.size());
	if (k == 0) return;
	sort(res.begin(), res.end());
	for (i=0; i<k-1; ++i) printf("%d ", res[i]);
	printf("%d\n", res[i]);
}

int main() {
	int i, j, k;
	int tc;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		input();
		gao();
		if (tc != 0) puts("");
	}
	return 0;
}