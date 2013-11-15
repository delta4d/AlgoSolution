#include <queue>
#include <cstdio>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 100001;
struct edge {
	int t;
	int d;
	edge(int t=-1, int d=-1):t(t), d(d) {}
};
bool operator<(const edge &a, const edge &b) {
	return a.d < b.d;
} 
vector<edge> g[MAXN];
int d[MAXN];

inline void init(const int &n, const int &m, int &s, int &d) {
	int i;
	int src, dst;
	int x, y, w;
	for (i=1; i<=n; ++i) g[i].clear();
	for (i=0; i<m; ++i) {
		scanf("%d %d %d", &x, &y, &w);
		g[x].push_back(edge(y, w));
		g[y].push_back(edge(x, w));
	}
	scanf("%d %d", &src, &dst);
	s = src; d = dst;
}

int gao(const int &n, const int &src, const int &dst) {
	int i, j, k;
	int index;
	int dis;
	int s, w;
	edge ss;
	priority_queue<edge> q;
	vector<edge>::iterator it;
	memset(d, 0, sizeof(d));
	d[src] = INF;
	q.push(edge(src, INF));
	while (!q.empty()) {
		ss = q.top();
		q.pop();
		index = ss.t;
		if (index == dst) return ss.d;
		for (it=g[index].begin(); it!=g[index].end(); ++it) {
			s = (*it).t;
			w = (*it).d;
			dis = min(d[index], w);
			if (dis > d[s]) {
				d[s] = dis;
				q.push(edge(s, d[s]));
			}
		}
	}
	return 0;
}

int main() {
	int n, m;
	int src, dst;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF) {
		init(n, m, src, dst);
		printf("%d\n", gao(n, src, dst));
	}
	return 0;
}
