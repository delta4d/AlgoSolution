#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 16111;

vector <int> out;
vector <int> f[MAXN];
int dp[MAXN], cnt[MAXN], mn;
int n;

void dfs(int parent, int root) {
	int i, j, k;
	int sum(0);
	bool leaf(true);
	
	if (cnt[root] != -1) return;
	for (i=0; i<f[root].size(); ++i) {
		if (f[root][i] == parent) continue;
		leaf = false;
		dfs(root, f[root][i]);
		sum += cnt[f[root][i]];
		dp[root] = max(dp[root], cnt[f[root][i]]);
	}
	cnt[root] = leaf ? 1 : sum + 1;
	dp[root] = max(dp[root], n - cnt[root]);
	mn = min(mn, dp[root]);
}

int main() {
	int i, j, k;
	int x, y;

	scanf("%d", &n);
	for (i=1; i<n; ++i) {
		scanf("%d %d", &x, &y);
		--x, --y;
		f[x].push_back(y);
		f[y].push_back(x);
	}
	mn = 0x3f3f3f3f;
	memset(dp, -1, sizeof(dp));
	memset(cnt, -1, sizeof(cnt));
	dfs(-1, 0);
	for (i=0; i<n; ++i) if (dp[i] == mn) out.push_back(i+1);
	printf("%d %d\n", mn, out.size());
	for (i=0; i<out.size(); ++i) printf("%d%s", out[i], i+1==out.size()?"\n":" ");

	return 0;
}