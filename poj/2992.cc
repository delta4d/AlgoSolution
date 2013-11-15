#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MAXN = 1024;

bool isp[MAXN];
LL p[MAXN];
LL cnt[500][500];

LL c(LL n, LL k) {
	LL ret(0), t(k);
	while (n >= k) {
		ret += n / k;
		k *= t;
	}
	return ret;
}

void init() {
	LL m, n;
	LL i, j, k(0);
	for (i=2; i<MAXN; ++i) if (!isp[i]) {
		p[k++] = i;
		for (j=i<<1; j<MAXN; j+=i) isp[j] = true;
	}
	for (n=1; n<=431; ++n) {
		for (k=2; k<=n; ++k) {
			cnt[n][k] = c(n, k);
		}
	}
}

LL gao(LL n, LL k) {
	LL i, j;
	LL tot(1);
	
	for (i=0; p[i]<=n; ++i) {
//		printf("%d %d %d\n", c(n, p[i]), c(k, p[i]), c(n-k, p[i]));
		tot *= cnt[n][p[i]] - cnt[k][p[i]] - cnt[n-k][p[i]] + 1;
	}
	return tot;
}

int main() {
	LL i, j, k;
	LL m, n;
	
	init();
	while (2 == scanf("%lld %lld", &n, &k)) {
		printf("%lld\n", gao(n, k));
	}
	return 0;
}