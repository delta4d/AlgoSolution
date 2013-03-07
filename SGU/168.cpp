#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

int f[MAXN][MAXN];

int main() {
	int i, j, k;
	int m, n;
	
	while (2 == scanf("%d %d", &m, &n)){
		for (i=0; i<m; ++i) for (j=0; j<n; ++j) scanf("%d", f[i] + j);
		for (j=n-1, i=m-1; i>=0; --i) f[i][j] = (i == m - 1 ? f[i][j] : min(f[i][j], f[i+1][j]));
		for (j=n-2; j>=0; --j) for (i=m-1; i>=0; --i) {
			f[i][j] = min(min(f[i][j], f[i][j+1]), i == m - 1 ? f[i-1][j+1] : min(f[i+1][j], f[i-1][j+1]));
		}
		for (i=0; i<m; ++i) for (j=0; j<n; ++j) printf("%d%c", f[i][j], j == n - 1 ? '\n' : ' ');
	}
	return 0;
}