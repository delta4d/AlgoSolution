#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int D = 1237;
const int MOD = 1000007;
const int MAXN = 16;

const int dv[] = {857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int n;
int h[MAXN], d[MAXN];
bool visit[MAXN];
bool f[MAXN][MAXN];
vector <pair<int, int> > E;
vector <int> tt;
set <int> out;

void dfs_d(int parent, int root) {
	int i, j, k;
	bool leaf(true);
	for (i=0; i<n; ++i) {
		if (i == parent || !f[root][i]) continue;
		dfs_d(root, i);
		if (d[root] == -1) d[root] = d[i] + 1;
		else d[root] = min(d[root], d[i] + 1);
	}
	if (d[root] == -1) d[root] = 0;
}

void dfs_tree(int root) {
	int i, j, k;
	visit[root] = true;
	tt.push_back(root);
	for (i=0; i<n; ++i) {
		if (!visit[i] && f[root][i]) dfs_tree(i);
	}
}

int hash(int parent, int root) {
	int i, j, k;
	int ret;
	vector <int> s;
	bool leaf(true);
	if (h[root] != -1) return h[root];
	for (i=0; i<n; ++i) {
		if (i == parent || !f[root][i]) continue;
		leaf = false;
		s.push_back(hash(root, i));
	}
	if (leaf) {
		return h[root] = dv[d[root]];
	} else {
		sort(s.begin(), s.end());
		ret = s[0];
		for (i=1; i<s.size(); ++i) {
			ret = (ret * dv[d[root]]) ^ s[i];
		}
		return h[root] = ret * D % MOD;
	}
}

bool my(vector <int> &x) {
	if (x.size() != 3) return false;
	if (x[0] == 0 && x[1] == 2 && x[2] == 5) return true;
	//if (x[0] == 0 && x[1] == 5 && x[2] == 7) return true;
	return false;
}

void gao() {
	int i, j, k;
	memset(visit, false, sizeof(visit));
	for (i=0; i<n; ++i) {
		if (visit[i]) continue;
		tt.clear();
		dfs_tree(i);
		for (j=0; j<tt.size(); ++j) {
			memset(h, -1, sizeof(h));
			memset(d, -1, sizeof(d));
			dfs_d(-1, tt[j]);
			//if (my(tt)) {
				k = hash(-1, tt[j]);
			//	printf("%d %d\n", tt[j], k);
			//}
			//if (my(tt)) printf("--- %d\n", k);
			if (out.find(k) != out.end()) break;
		}
		if (j >= tt.size()) {
			out.insert(k);
		//	for (j=0; j<tt.size(); ++j) printf("%d ", tt[j]);
		//	puts("");
		}
	}
}

void dfs(int d) {
	if (d == n - 1) {
		gao();
		return;
	}
	int x = E[d].first, y = E[d].second;
	dfs(d+1);
	f[x][y] = f[y][x] = false;
	dfs(d+1);
	f[x][y] = f[y][x] = true;
}

int main() {
	int i, j, k;
	int x, y;
	int tc, cn(0);
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		E.clear();
		out.clear();
		memset(f, false, sizeof(f));
		for (i=1; i<n; ++i) {
			scanf("%d %d", &x, &y);
			--x, --y;
			E.push_back(make_pair(x, y));
			f[x][y] = f[y][x] = true;
		}
		dfs(0);
		printf("Case #%d: %d\n", ++cn, out.size());
	}
	return 0;
}