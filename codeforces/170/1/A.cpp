#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;

bool h[MAXN][MAXN];
bool f[MAXN][MAXN];
bool visit[MAXN];
int m, n, c;

void dfs(int root) {
	visit[root] = true;
	for (int i=0; i<n; ++i) if (!visit[i] && f[root][i]) {
		dfs(i);
	}   
}

int main() {
	int i, j, k;
	int tot(0), nol(0);

	scanf("%d%d", &n, &m);
	for (i=0; i<n; ++i) {
		scanf("%d", &c);
		if (c == 0) ++nol;
		for (j=0; j<c; ++j) {
			scanf("%d", &k);
			h[i][k-1] = true;
		}
	}
	for (i=0; i<n; ++i) for (j=i+1; j<n; ++j) for (k=0; k<m; ++k) {
		if (h[i][k] && h[j][k]) {
			f[i][j] = f[j][i] = true;
			break;
		}
	}
	for (i=0; i<n; ++i) {
		if (!visit[i]) {
			++tot;
			dfs(i);
		}   
	}
	if (tot == nol) printf("%d\n", nol);
	else printf("%d\n", tot-1);

	return 0;
}

// 3222269	 Mar 1, 2013 8:07:49 AM	delta_4d	 277A - Learning Languages	 GNU C++	Accepted	15 ms	0 KB
