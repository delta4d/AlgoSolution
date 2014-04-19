#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1 << 10;
const ll M = 1000000007;

vector <int> E[N];
int C[N][N];
bool has_sup[N];

void init() {
	for (int i=0; i<N; ++i) C[i][0] = C[i][i] = 1;
	for (int i=0; i<N; ++i) for (int j=1; j<i; ++j) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
}

pair <ll, ll> dfs(int root) {
	ll s = 0, w = 1;
	for (int i=(int)E[root].size()-1; i>=0; --i) {
		int cc = E[root][i];
		pair <ll, ll> ret = dfs(cc);
		w = w * ret.second % M;
		w = w * C[s+ret.first][s] % M;
		s += ret.first;
	}
	return make_pair(s+1, w);
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) E[i].clear();
		fill(has_sup, has_sup+n, false);
		for (int i=1,a,b; i<n; ++i) {
			scanf("%d%d", &a, &b), --a, --b;
			E[a].push_back(b);
			has_sup[b] = true;
		}
		int root = 0;
		for (; root<n; ++root) if (!has_sup[root]) break;
		printf("Case %d: %lld\n", ++cn, dfs(root).second);
	}
	return 0;
}

// 256936	2013-08-28 20:12:43	 1382 - The Queue	 C++	 0.152	 5332	Accepted
