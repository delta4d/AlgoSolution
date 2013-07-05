#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

double f[MAXN][MAXN];

int main() {
	int i, j, k;
	int n, s;
	
	while (2 == scanf("%d %d", &n, &s)) {
		memset(f, 0, sizeof(f));
		for (i=n; i>=0; --i) {
			for (j=s; j>=0; --j) {
				if (i == n && j == s) continue;
				f[i][j] = (n * s * 1.0 + f[i+1][j] * (n - i) * j + f[i][j+1] * i * (s - j) + f[i+1][j+1] * (n - i) * (s - j)) / (n * s - i * j);
			}
		}
		printf("%.32lf\n", f[0][0]);
	}
	return 0;
}