#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

int a[MAXN];
queue <int> q;
vector <int> e[MAXN];
vector <int> o;

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i=0,u,v; i<m; ++i) {
		scanf("%d%d", &u, &v), --u, --v;
		e[u].push_back(v), e[v].push_back(u);
	}
	for (int i=0; i<n; ++i) {
		scanf("%d", a+i);
		if (!a[i]) q.push(i);
	}
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		if (a[k] != 0) continue;
		o.push_back(k);
		--a[k];
		for (int i=0; i<(int)e[k].size(); ++i) {
			--a[e[k][i]];
			if (a[e[k][i]] == 0) q.push(e[k][i]);
		}
	}
	for (int i=0; i<n; ++i) if (a[i] == 0) return puts("-1"), 0;
	sort(o.begin(), o.end());
	printf("%d\n", (int)o.size());
	for (int i=0; i<(int)o.size(); ++i) printf("%d ", o[i]+1); puts("");

	return 0;
}

// 4000081	 Jul 1, 2013 6:54:08 PM	delta_4d	 D - Dispute	 GNU C++	Accepted	 125 ms	 4100 KB
