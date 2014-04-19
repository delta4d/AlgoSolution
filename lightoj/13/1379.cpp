#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10000 + 86;
const int INF = 0x3f3f3f3f;

vector <pair<int,int> > e[N], re[N];
int d[N], rd[N];
priority_queue <pair<int,int> > q;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

void gao(vector<pair<int,int> >e[], int d[], int s, int n) {
	fill(d, d+n, INF);
	d[s] = 0;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		int c = -q.top().first, x = q.top().second;
		q.pop();
		if (c != d[x]) continue;
		for (int i=0; i<(int)e[x].size(); ++i) {
			int y = e[x][i].first, w = e[x][i].second;
			if (c + w < d[y]) {
				d[y] = c + w;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}

int main() {
	int tc, cn = 0, n, m, s, t, p;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), m = fastin<int>();
		s = fastin<int>() - 1, t = fastin<int>() - 1, p = fastin<int>();
		for (int i=0; i<n; ++i) e[i].clear(), re[i].clear();
		for (int i=0,u,v,w; i<m; ++i) {
			u = fastin<int>() - 1, v = fastin<int>() - 1, w = fastin<int>();
			e[u].push_back(make_pair(v, w));
			re[v].push_back(make_pair(u, w));
		}
		gao(e, d, s, n);
		gao(re, rd, t, n);
		int mx = -1;
		for (int i=0; i<n; ++i) for (int j=0; j<(int)e[i].size(); ++j) {
			int u = i, v = e[i][j].first, w = e[i][j].second;
			if (d[u] + rd[v] + w <= p) mx = max(mx, w);
		}
		printf("Case %d: %d\n", ++cn, mx);
	}
	return 0;
}

// 287532	2013-11-14 23:33:43	 1379 - Toll Management	 C++	 0.268	 4012	Accepted
