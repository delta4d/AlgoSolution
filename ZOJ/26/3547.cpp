#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
const LL rev = 233333335;

LL p4(LL n) {
	LL ret;
	
	ret = (n * n) % MOD;
	return (ret * ret) % MOD;
}

LL sum4(LL n) {
//	(6n^5+15n^4+10n^3-n)/30
	LL ret;
	LL x[6];
	
	x[0] = 1;
	for (int i=1; i<6; ++i) x[i] = x[i-1] * n % MOD;
	ret = 6 * x[5] % MOD;
	ret = (ret + 15 * x[4]) % MOD;
	ret = (ret + 10 * x[3]) % MOD;
	ret = (ret - x[1]) % MOD;
	ret = ret * rev % MOD;
	return ret;
}

LL gao(LL n) {
	LL i, j, k;
	LL ret(0);
	LL p[20];
	LL mask;
	LL next;
	LL x(n);
	int cnt;

	ret = sum4(n);
	if (n == 1) return 1;
	for (k=0,i=2; i*i<=n; ++i) {
		if (n % i == 0) {
			p[k++] = i;
			do {n /= i; } while (n % i == 0);
		}
	}
	if (n != 1) p[k++] = n;	
	for (next=mask=(1<<k)-1; next; next=(next-1)&mask) {
		for (j=1,cnt=i=0; i<k; ++i) {
			if (next & (1 << i)) {
				j *= p[i];
				++cnt;
			}
		}
	//	printf("---- %lld\n", j);
		if (cnt & 1) ret = (ret - (p4(j)* sum4(x/j)) % MOD) % MOD;
		else ret = (ret + (p4(j)* sum4(x/j)) % MOD) % MOD;
		if (ret < 0) ret += MOD;
	}
	return ret;
}

int main() {
	int tc;
	LL n;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld", &n);
		printf("%lld\n", gao(n));
	}
	return  0;
}
