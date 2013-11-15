#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50 * 50;

int f[MAXN];
bool visit[MAXN];

int polya(const int n, const int c) {
	int i, j, k;
	int ret;
	
	memset(visit, false, sizeof(visit));
	for (i=0; i<n; ++i) {
		if (!visit[i]) {
			dfs(i, n);
		}
	}
}

int gao(const int n, const int c) {
	int i, j, k;
	int ret;
	
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) {
			f[i] = j;
			for (k=0; k<n; ++k) f[i*n+k] = j * n + k;
			ret += polya(n*(n-1)>>1, c);
		}
	}
}

int main() {
	int i, j, k;
	int m, n;
	int c;
	
	for (n=3; n<=50; ++n) {
		printf("{");
		for (c=1; c<=26; ++c) printf("%d, ", gao(n, c));
		printf("},\n");
	}
	return 0;
}