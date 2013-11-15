#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f3fll;
const LL MAXN = 300;

struct node {
	LL t, w;
	node() {}
	node(LL _t, LL _w):t(_t), w(_w) {}
};

int in[MAXN];
LL d[MAXN];
bool visit[MAXN];
queue<int> q;
vector<node> f[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int s, t, w;
	int start, finish;
	int tc;
	bool circle;
	//freopen("f:\\in.txt", "r", stdin);	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		scanf("%d %d", &start, &finish);
		scanf("%d", &m);
		for (i=0; i<n; ++i) f[i].clear();
		for (i=0; i<m; ++i) {
			scanf("%d %d %d", &s, &t, &w);
			f[s].push_back(node(t, w));
		}
		for (i=0; i<n; ++i) d[i] = INF, in[i] = 0, visit[i] = false;
		d[start] = 0, in[start] = 1, visit[start] = true;
		while (!q.empty()) q.pop();
		q.push(start);
		circle = false;
		while (!q.empty()) {
			s = q.front();
			q.pop();
			visit[s] = false;
			for (i=0; i!=f[s].size(); ++i) {
				if (d[f[s][i].t] > d[s] + f[s][i].w) {
					d[f[s][i].t] = d[s] + f[s][i].w;
					if (!visit[f[s][i].t]) {
						q.push(f[s][i].t);
						visit[f[s][i].t] = true;
						++in[f[s][i].t];
						if (in[f[s][i].t] >= n) {
							circle = true;
							goto done;
						}
					}
				}
			}
		}
		done:;
		if (d[finish] == INF || circle) puts("infinity");
		else printf("%lld\n", d[finish]);
	}
	return 0;
}