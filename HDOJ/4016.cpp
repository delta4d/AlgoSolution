#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;
const long long INF = 0x7FFFFFFFFFFFFFFFLL;

int n, k;
long long f[MAXN];
long long x[MAXN];
long long res;

void dfs(int s, int d, long long cc) {
	res = min(res, cc);
	if (d == k || s == n) return;
	if ((cc & x[s]) >= res) return;
	dfs(s+1, d+1, cc&f[s]);
	dfs(s+1, d, cc);
}

int main() {
	int tc, cn(0);

//	freopen("in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &k);
		for (int i=0; i<n; ++i) scanf("%I64d", f+i);
		sort(f, f+n);
		x[n-1] = f[n-1];
		for (int i=n-2; i>=0; --i) x[i] = f[i] & x[i+1];
		res = INF;
		dfs(0, 0, INF);
		printf("Case #%d: %I64d\n", ++cn, res);
	}
	return 0;
}