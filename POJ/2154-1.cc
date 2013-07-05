#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef int LL;

const int MAXN = 1000000;

LL N, P;
int p[MAXN];
bool isp[MAXN];

void init() {
	int i, j, k(0);
	
	memset(isp, true, sizeof(isp));
	for (i=2; i<MAXN; ++i) {
		if (isp[i]) {
			p[k++] = i;
			for (j=i<<1; j<MAXN; j+=i) isp[j] = false;
		}
	}
}

LL euler(const LL x) {
	LL ret(x), t(x);
	for (LL i=0; p[i]*p[i]<=t; ++i) {
		if (t % p[i] == 0) {
			ret -= ret / p[i];
			for (; t % p[i] == 0; t /= p[i]);
		}
	}
	if (t != 1) ret -= ret / t;
	return ret % P;
}

LL f(LL x, LL e, const LL P) {
	LL ret(1);
	x %= P;
	while (e) {
		if (e & 1) ret = ret * x % P;
		e >>= 1;
		x = x * x % P;
	}
	return ret;
}

int main() {
	LL tot;
	LL tc;
	
	init();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &N, &P);
		tot = 0;
		for (LL i=1; i*i<=N; ++i) {
			if (N % i == 0) {
				tot = (tot + euler(N/i) * f(N, i-1, P)) % P;
				if (i * i != N) tot = (tot + euler(i) * f(N, N/i-1, P)) % P;
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}