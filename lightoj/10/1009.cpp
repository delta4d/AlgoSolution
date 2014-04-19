#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20000 + 86;

vector <int> e[N];
bool v[N];
int t[2];

void gao(int x, int tag) {
	if (e[x].empty()) return;
	v[x] = true, ++t[tag];
	for (int i=0; i<(int)e[x].size(); ++i) {
		int y = e[x][i];
		if (v[y]) continue;
		gao(y, tag^1);
	}
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		for (int i=0; i<N; ++i) e[i].clear();
		scanf("%d", &n);
		for (int i=0,u,v; i<n; ++i) {
			scanf("%d%d", &u, &v), --u, --v;
			e[u].push_back(v), e[v].push_back(u);
		}
		memset(v, false, sizeof(v));
		int tot = 0;
		for (int i=0; i<N; ++i) if (!v[i]) {
			t[0] = t[1] = 0;
			gao(i, 0);
			tot += max(t[0], t[1]);
		}
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 295076	2013-12-03 21:50:54	 1009 - Back to Underworld	 C++	 0.368	 4064	Accepted
