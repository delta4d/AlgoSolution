#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;

struct edge {
	LL s, t, w;
	edge() {}
	edge(LL _s, LL _t, LL _w):s(_s), t(_t), w(_w) {}
};

vector<edge> f;
LL d[300];

int main() {
	LL i, j, k;
	LL m, n;
	LL s, t, w;
	LL tc;
	LL start, finish;
	bool circle;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%lld", &tc);
	while (tc--) {
		scanf("%lld", &n);
		scanf("%lld %lld", &start, &finish);
		scanf("%lld", &m);
		f.clear();
		for (i=0; i<m; ++i) {
			scanf("%lld %lld %lld", &s, &t, &w);
			f.push_back(edge(s, t, w));
		}
		for (i=0; i<n; ++i) d[i] = INF;
		d[start] = 0;
		for (i=0; i<n; ++i) {
			circle = false;
			for (k=0; k!=f.size(); ++k) {
				if (d[f[k].t] > d[f[k].s] + f[k].w) {
					d[f[k].t] = d[f[k].s] + f[k].w;
					circle = true;
				}
			}
		}
		if (circle || d[finish] == INF) puts("infinity");
		else printf("%lld\n", d[finish]);
	}
	return 0;
}