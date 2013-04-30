#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 36;

long long f[MAXN][MAXN];
long long x[MAXN][MAXN];

void init() {
	f[0][0] = 1;
	for (int n=1; n<MAXN; ++n) for (int h=0; h<MAXN; ++h) {
		for (int k=0; k<n; ++k) for (int i=0; i<h-1; ++i) {
			f[n][h] += f[k][i] * f[n-1-k][h-1] * 2;
		}
		for (int k=0; k<n; ++k) f[n][h] += f[k][h-1] * f[n-1-k][h-1];
	}
	for (int i=1; i<MAXN; ++i) for (int j=1; j<MAXN; ++j) {
		for (int k=j; k<MAXN; ++k) x[i][j] += f[i][k];
	}
}

int main() {
	init();

	int n, h;
	scanf("%d%d", &n, &h);
	printf("%I64d\n", x[n][h]);

	return 0;
}

// 3653691	 Apr 30, 2013 12:16:32 PM	delta_4d	 D - How many trees?	 GNU C++	Accepted	31 ms	0 KB
