// how many partions of n

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1000000;
const LL MAXN = 55555;

LL f[2][MAXN];
LL sum[MAXN];

int main() {
	LL i, j, k(0), t;
	LL m, n;
	
	for (i=0; i<MAXN; ++i) f[0][i] = 1;
	for (j=2; j<MAXN; ++j) {
		t = k ^ 1;
		f[t][j] = 1;
		for (i=j+1; i<MAXN; ++i) {
			f[t][i] = (f[k][i-1] + f[t][i-j]) % MOD;
			sum[i] = (sum[i] + f[t][i]) % MOD;
		}
		for (i=0; i<MAXN; ++i) f[k][i] = 0;
		k = t;
	}
//	for (i=2; i<MAXN; ++i) printf("%lld ", sum[i]+2); puts("");
	for (i=0; i<MAXN; ++i) if ((sum[i] + 2) % MOD == 0) break;
	printf("%lld\n", i);
	return 0;
}