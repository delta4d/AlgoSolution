#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 101;
char graph[MAXN][MAXN];
int f[MAXN<<1][MAXN][MAXN];

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int t;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		//printf("%d %d\n", n, m);
		for (i=0; i<m; ++i) scanf("%s", graph[i]);
		//for (i=0; i<n; ++i) puts(graph[i]); puts("");
		memset(f, 0, sizeof(f));
		f[0][0][0] = (graph[0][0] == '*');
		for (i=0; i<m+n-1; ++i) {
			for (j=0; j<n&&j<=i; ++j) {
				for (k=0; k<n&&k<=i; ++k) {
					if (i == 0 && j == 0 && k == 0) continue;
					if (graph[i-j][j] == '#' || graph[i-k][k] == '#') {
						f[i][j][k] = 0;	
						continue;
					}		
					t = f[i-1][j][k];
					if (j > 0) t = max(t, f[i-1][j-1][k]);
					if (k > 0) t = max(t, f[i-1][j][k-1]);
					if (j > 0 && k > 0) t = max(t, f[i-1][j-1][k-1]);
					if (graph[i-j][j] == '*') ++t;
					if (graph[i-k][k] == '*') ++t;
					if (graph[i-j][j] == '*' && j == k) --t;
					f[i][j][k] = t;
				}
			}
		}
		//for (i=0; i<m+n-1; ++i) for (j=0; j<n; ++j) for (k=0; k<n; printf("(%d, %d, %d)", i, j, k), ++k);
		printf("%d\n", f[m+n-2][n-1][n-1]);
	}
	return 0;
}
