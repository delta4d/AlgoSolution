#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 86;
const int MOD = 7340033;

long long f[32][MAXN];

void init() {
	for (int i=0; i<32; ++i) f[i][0] = 1;
	for (int i=1; i<32; ++i) {
		long long t[MAXN] = {0};
		for (int j=0; j<MAXN; ++j) for (int k=0; k<=j; ++k) t[j] += f[i-1][k] * f[i-1][j-k];	
		for (int j=0; j<MAXN; ++j) t[j] %= MOD;
		for (int j=0; j+1<MAXN; ++j) for (int k=0; k<=j; ++k) f[i][j+1] += t[k] * t[j-k];
		for (int j=0; j<MAXN; ++j) f[i][j] %= MOD;
	}	
}

int main() {
	init();

	int q;
	int n, k, h;

	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &n, &k);
		for (h=0; n>1&&(n&1); ++h,n>>=1);
		printf("%d\n", f[h][k]);
	}

	return 0;
}
