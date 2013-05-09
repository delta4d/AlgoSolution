#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1024;
const int MOD = 1000000007;

int C[MAXN][MAXN];
int x[MAXN], p2[MAXN];
int y[MAXN], sz;

void init() {
	p2[0] = 1;
	for (int i=1; i<MAXN; ++i) {
		p2[i] = 2ll * p2[i-1] % MOD;
		C[i][0] = C[i][i] = 1;
		for (int j=1; j<i; ++j) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}	
}

int main() {
	int n, m;
	int tot = 1;

	init();
	scanf("%d%d", &n, &m);
	for (int i=0,k; i<m; ++i) scanf("%d", &k), x[k-1] = 1;
	int cc = 0, b = 0;
	for (int i=0; i<n; ++i) {
		if (x[i]) {
			if (b && cc) tot = (long long)tot * p2[cc-1] % MOD;
			if (cc) y[sz++] = cc;
			b = 1, cc = 0;
		} else {
			++cc;
		}
	}	
	if (cc) y[sz++] = cc;
	int sum = 0;
	for (int i=0; i<sz; ++i) sum += y[i];
	for (int i=0; i<sz; ++i) tot = (long long)tot * C[sum][y[i]] % MOD, sum -= y[i];
	printf("%d\n", tot);

	return 0;
}

// 3498753	 Apr 10, 2013 11:56:39 AM	delta_4d	 294C - Shaass and Lights	 GNU C++	Accepted	 31 ms	 4100 KB
