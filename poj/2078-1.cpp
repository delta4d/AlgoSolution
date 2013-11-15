#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 7;

int minc;
int f[MAXN][MAXN];
int sum[MAXN];

inline void rotate(const int d, const int n) {
	int t(f[d][n-1]);
	for (int i=n-1; i>0; --i) {
		f[d][i] = f[d][i-1];
	}
	f[d][0] = t;
}

inline void init(const int n) {
	for (int i=0; i<n; ++i) sum[i] = f[0][i];
}

void dfs(const int n, int depth) {
	int i, j, k;
	int maxc(-INF);
	int cur;
	if (depth == n) {
		for (i=0; i<n; ++i) maxc = max(sum[i], maxc);
		minc = min(maxc, minc);
		return;
	}
	for (i=0; i<n; ++i) {
		rotate(depth, n);
		cur = -INF;
		for (j=0; j<n; ++j) {
			sum[j] += f[depth][j];
			cur = max(sum[j], cur);
		}
		/*if (cur >= minc) {
			for (j=0; j<n; ++j) {
				sum[j] -= f[depth][j];
			}
			return;
		}*/
		dfs(n, depth+1);
		for (j=0; j<n; ++j) {
			sum[j] -= f[depth][j];
		}
	}
}

int main() {
	int n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n > 0) {
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j) {
				scanf("%d", f[i]+j);
			}
		}
		minc = INF;
		init(n);
		dfs(n, 1);
		printf("%d\n", minc);
		scanf("%d", &n);
	}
	return 0;
}