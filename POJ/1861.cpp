#include <queue>
#include <cstdio>
#include <memory>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
struct edge {
	int x;
	int y;
	int w;
	edge(int x=0, int y=0, int w=0):x(x), y(y), w(w) {}
};

inline bool operator<(const edge &a, const edge &b) {
	return a.w > b.w;	
}
typedef priority_queue<edge> PQE;
PQE q, e;
int f[MAXN];

int find_root(const int x) {
	if (f[x] < 0) return x;
	return f[x] = find_root(f[x]);
}

inline bool	Union(const int x, const int y) {
	int rx(find_root(x));
	int ry(find_root(y));
	if (rx == ry) return false;
	f[rx] += f[ry];
	f[ry] = f[y] = rx;
	return true;
}

void kruskal(const int &n) {
	int i, j, k;
	int cnt(0);
	int max_w(-1);
	edge ss;
	while (!e.empty()) e.pop();
	memset(f, -1, sizeof(f));
	while (cnt < n - 1) {
		ss = q.top(); //printf("%d\n", ss.w);
		q.pop();
		if (Union(ss.x, ss.y)) {
			e.push(ss);
			max_w = max(ss.w, max_w);
			++cnt;
		}
	}
	printf("%d\n", max_w);
	printf("%d\n", n-1);
	while (!e.empty()) {
		ss = e.top();
		e.pop();
		printf("%d %d\n", ss.x, ss.y);
	}
}

int main () {
	int n, m;
	int x, y, w;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF) {
		while (!q.empty()) q.pop();
		for (i=0; i<m; ++i) {
			scanf("%d %d %d", &x, &y, &w);
			q.push(edge(x, y, w));
		}
		kruskal(n);
	}
	return 0;
}