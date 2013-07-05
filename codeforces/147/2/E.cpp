#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

template <int MAXN>
struct MinCostMaxFlow {
	struct Edge {
		int v, f, c, p; // endpoint, flow, cost, position of back edge
		Edge(int _v=0, int _f=0, int _c=0, int _p=0):v(_v), f(_f), c(_c), p(_p) {}
	};

	vector <Edge> e[MAXN];
	int n, source, sink;
	int mincost, maxflow;
	int d[MAXN], cnt[MAXN];            // dis, inq times
	int pre[MAXN], pp[MAXN], uv[MAXN]; // pre endpoint, back edge position, capacity
	bool inq[MAXN];                    // is it inq

	void init(int _n, int _source, int _sink) {
		mincost = 0, maxflow = 0;
		n = _n, source = _source, sink = _sink;
		for (int i=0; i<n; ++i) e[i].clear();
	}

	void add_edge(int a, int b, int c, int w) { // endpoints a b, capacity c, w cost/unit
		e[a].push_back(Edge(b, c, w, (int)e[b].size()));
		e[b].push_back(Edge(a, 0, -w, (int)e[a].size()-1));
	}

	// 0: ok, find an argument path
	// -1: can not find an argument path
	// -2: there is a negative loop
	int spfa() {
		fill(cnt, cnt+n, 0);
		fill(uv, uv+n, 0);
		fill(d, d+n, INF);
		fill(inq, inq+n, false);
		fill(pre, pre+n, -1);
		fill(pp, pp+n, -1);

		queue <int> q;
		d[source] = 0, inq[source] = true, cnt[source] = 1;
		q.push(source);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			inq[u] = false;
			for (int i=0; i<(int)e[u].size(); ++i) {
				Edge cc = e[u][i];
				int v = cc.v, f = cc.f, c = cc.c;
				if (f > 0 && d[u] + c < d[v]) {
					d[v] = d[u] + c;
					pre[v] = u, pp[v] = cc.p, uv[v] = f;
					if (!inq[v]) {
						q.push(v);
						++cnt[v];
						if (cnt[v] > n) return -2;
						inq[v] = true;
					}
				}
			}
		}
		return d[sink] == INF ? -1 : 0;
	}
	
	int run() {
		while (spfa() == 0) {
			int minf = INF;
			for (int v=sink; v!=source; v=pre[v]) minf = min(minf, uv[v]); 
			for (int v=sink,u=pre[v]; v!=source; v=u,u=pre[v]) {
				int j = pp[v], i = e[v][j].p;
				e[u][i].f -= minf, e[v][j].f += minf;
			}
			mincost += minf * d[sink], maxflow += minf;
		}
		return 0;
	}
};

const int MAXN = 200;
MinCostMaxFlow <MAXN> mcmf;
char s[111], t[111];

int main() {
	int n;

	scanf("%s%d", t, &n);
	int S = 0, T = n + 27;
	mcmf.init(T+1, S, T);
	for (int i=1,c; i<=n; ++i) {
		scanf("%s%d", s, &c);
		mcmf.add_edge(S, i, c, 0);
		int cnt[26]={0};
		for (int k=0; s[k]; ++k) ++cnt[s[k]-'a'];
		for (int k=0; k<26; ++k) if (cnt[k]) mcmf.add_edge(i, k+1+n, cnt[k], i);
	}
	int sz = 0, cnt[26]={0};
	for (int i=0; t[i]; ++i) ++cnt[t[i]-'a'], ++sz;
	for (int i=0; i<26; ++i) if (cnt[i]) mcmf.add_edge(i+1+n, T, cnt[i], 0);
	mcmf.run();
	printf("%d\n", mcmf.maxflow == sz ? mcmf.mincost : -1);

	return 0;
}

// 4009147	 Jul 4, 2013 8:38:01 AM	delta_4d	 E - Build String	 GNU C++	Accepted	 15 ms	 300 KB
