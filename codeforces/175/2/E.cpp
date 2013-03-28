#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 1 << 10;
const int MOD = 1000000007;

int f[MAXN][MAXN][4];
int C[MAXN][MAXN];
int F[MAXN], p[MAXN]={1};

void add(int &a, int b) {
	a += b;
	(a >= MOD) && (a -= MOD);
}

int main() {
	int n, k;

	scanf("%d%d", &n, &k);

	for (int i=0,j; i<=n; ++i) for (C[i][0]=C[i][i]=1,j=1; j<i; ++j) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	for (int i=1; i<=n; ++i) p[i] = ((LL)i * p[i-1]) % MOD;

	f[0][0][1] = 1;
	for (int i=0; i<n; ++i) for (int j=0; j<=i; ++j) for (int s=0; s<4; ++s) {
		if (s % 2 == 0) add(f[i+1][j+1][s/2], f[i][j][s]);
		if (i + 2 <= n) add(f[i+1][j+1][s/2+2], f[i][j][s]);
		if (i + 1 >= j) add(f[i+1][j][s/2], f[i][j][s]);
	}

	for (int i=0; i<=n; ++i) {
		for (int j=0; j<4; ++j) add(F[i], f[n][i][j]);
		F[i] = ((LL)F[i] * p[n-i]) % MOD;
	}

	for (int i=n-1; i>=0; --i) for (int j=i+1; j<=n; ++j) add(F[i], MOD-(LL)F[j]*C[j][i]%MOD);
	
	printf("%d\n", F[k]);

	return 0;
}

// 3416316	 Mar 28, 2013 7:48:40 PM	delta_4d	 285E - Positions in Permutations	 GNU C++	Accepted	78 ms	20500 KB
