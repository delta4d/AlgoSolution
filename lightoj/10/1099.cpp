#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 5001;

vector <pair<int, int> > e[N];
int pre[N], suf[N];
bool inq[N];
queue <int> q;

void spfa(int st, int n, int d[]) {
	memset(d, 0x3f, sizeof(int)*n);
	memset(inq, false, sizeof(inq));
	while (!q.empty()) q.pop();
	d[st] = 0, inq[st] = true;
	q.push(st);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = false;
		for (int i=0; i<(int)e[u].size(); ++i) {
			int v = e[u][i].first, w = e[u][i].second;
			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int gao(const int n) {
	int mn = INF, D = pre[n-1];
	for (int i=0; i<n; ++i) for (int k=0; k<(int)e[i].size(); ++k) {
		int j = e[i][k].first, w = e[i][k].second;
		int cc = pre[i] + w + suf[j];
		if (cc > D) mn = min(mn, cc);
		cc = pre[i] + suf[i] + 2 * w;
		if (cc > D) mn = min(mn, cc);
	}
	return mn;
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,u,v,w; i<m; ++i) {
			scanf("%d%d%d", &u, &v, &w), --u, --v;
			e[u].push_back(make_pair(v, w));
			e[v].push_back(make_pair(u, w));
		}
		spfa(0, n, pre);
		spfa(n-1, n, suf);
		printf("Case %d: %d\n", ++cn, gao(n));
	}
	return 0;
}

// 317370	2014-01-27 00:21:18	 1099 - Not the Best	 C++	 0.116	 3916	Accepted
