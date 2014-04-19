#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 101;

struct edge {
	int u, v, w;
	edge(int u=0, int v=0, int w=0):u(u), v(v), w(w) {}
};

vector <edge> e;
int d[N];

bool gao(const int n) {
	memset(d, 0, sizeof(d));
	for (int i=1; i<n; ++i) {
		for (int j=0; j<(int)e.size(); ++j) {
			int u = e[j].u, v = e[j].v, w = e[j].w;
			d[v] = min(d[v], d[u] + w);
		}
	}
	for (int j=0; j<(int)e.size(); ++j) {
		int u = e[j].u, v = e[j].v, w = e[j].w;
		if (d[u] + w < d[v]) return true;
	}
	return false;
}

int main() {
	int tc, cn = 0, n, r, p;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &n, &r, &p);
		e.clear();
		for (int i=0,u,v,I,E; i<r; ++i) {
			scanf("%d%d%d%d", &u, &v, &I, &E);
			int w = E * p - I;
			e.push_back(edge(u, v, w));
		}
		printf("Case %d: %s\n", ++cn, gao(n)?"YES":"NO");
	}
	return 0;
}

// 317699	2014-01-27 18:44:11	 1221 - Travel Company	 C++	 0.256	 1604	Accepted
