#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef VI::iterator VII;
const int MAXN = 100;

VI pos[MAXN], neg[MAXN];
int dp[MAXN], dn[MAXN];

int gao(const int n) {
	int i, j, k(0);
	int x, y, r((n+1)>>1);
	for (i=1; i<=n; ++i) {
		x = 0;
		for (j=0; j<pos[i].size(); ++j) 
			x += dp[pos[i][j]];
		if (x + j>= r) {
			++k;
			continue;
		}
		x = 0;
		for (j=0; j<neg[i].size(); ++j) 
			x += dn[neg[i][j]];
		if (x + j >= r) ++k;
	}
	return k;
}

int main() {
	int tc;
	int r, s, t;
	int m, n;
	int i, j, k;
	int x, y, w;	
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (r=0; r<tc; ++r) {
		scanf("%d %d", &n, &m);
		for (i=1; i<=n; ++i) {
			pos[i].clear();
			neg[i].clear();
		}
		memset(dp, 0, sizeof(dp));
		memset(dn, 0, sizeof(dn));
		for (i=0; i<m; ++i) {
			scanf("%d %d", &x, &y);
			pos[x].push_back(y); ++dp[x];
			neg[y].push_back(x); ++dn[y];
		}
		printf("%d\n", gao(n));
	}
	return 0;
}