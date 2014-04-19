#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool v[100][2];
vector <int> e[100];
queue <pair<int, int> > q;

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,a,b; i<m; ++i) {
			scanf("%d%d", &a, &b), --a, --b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		memset(v, false, sizeof(v));
		while (!q.empty()) q.pop();
		q.push(make_pair(0, 0));
		v[0][0] = true;
		while (!q.empty()) {
			int a = q.front().first, b = q.front().second; q.pop();
			for (int i=0; i<(int)e[a].size(); ++i) {
				int c = e[a][i];
				if (v[c][1-b]) continue;
				v[c][1-b] = true;
				q.push(make_pair(c, 1-b));
			}
		}
		int tot = 0;
		if (!e[0].empty()) for (int i=0; i<n; ++i) tot += v[i][0];
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 308341	2014-01-06 23:37:17	 1185 - Escape	 C++	 0.044	 1248	Accepted
