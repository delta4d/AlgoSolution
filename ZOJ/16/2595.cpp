#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[101][100000];

int gen(int n, int m) {
	int i, j;
	if (f[n][m] != -1) return f[n][m];
	if (f[n][m-1] == -1) j = f[n][m-1] = gen(n, m-1);
	if (f[n-1][j] == -1) return f[n][m] = f[n-1][j] = gen(n-1, j);
}

void gen() {
	int i, j, k;
	memset(f, -1, sizeof(f));
	for (i=1; i<=100; ++i) f[1][i] = i << 1, f[i][1] = 2;
	for (i=2; i<=100; ++i) {
		for (j=2; j<=100; ++j) {
			f[i][j] = gen(i, j);
		}
	}
	for (i=1; i<=100; ++i) {
		for (j=1; j<=100; ++j) printf("%d ", f[i][j]);
		puts("");
	}
}

int main() {
	int i, j, k;
	int n, m, t;
	
	freopen("f:\\in.txt", "r", stdin);
	freopen("f:\\out.txt", "w", stdout);
	gen();

	return 0;
}