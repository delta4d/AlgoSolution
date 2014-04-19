#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1 << 10;

vector <int> e[N];
int cc[N], cnt[N];
bool v[N];

void dfs(int x) {
	++cnt[x], v[x] = true;
	for (int i=0; i<(int)e[x].size(); ++i) {
		int y = e[x][i];
		if (!v[y]) dfs(y);
	}
}

int main() {
	int tc, cn = 0, K, N, M;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &K, &N, &M);
		for (int i=0; i<K; ++i) scanf("%d", cc+i), --cc[i];
		for (int i=0; i<N; ++i) e[i].clear();
		for (int i=0,u,v; i<M; ++i) {
			scanf("%d%d", &u, &v);
			e[u-1].push_back(v-1);
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i=0; i<K; ++i) {
			memset(v, false, sizeof(v));
			dfs(cc[i]);
		}
		int tot = 0;
		for (int i=0; i<N; ++i) tot += cnt[i] == K;
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 296832	2013-12-08 21:06:57	 1111 - Best Picnic Ever	 C++	 0.024	 1248	Accepted
