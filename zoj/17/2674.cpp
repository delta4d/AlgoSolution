#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
LL p[] = {2, 3, 5, 7, 11};
LL res[13][13];

LL phi(LL x) {
	LL i, j, k;
	LL ret(x);
	for (i=2; i*i<=x; ++i) {
		if (x % i == 0) {
			ret = ret / i * (i - 1);
			while (x % i == 0) {
				x /= i;
			} 
		}
	}
	if (x > 1) ret = ret / x * (x - 1);
	return ret;
}

LL gao(LL x, LL y, LL m) {
	LL ret(1);
	while (y != 0) {
		if (y & 1) ret = ret * x % m;
		x = x * x % m;
		y >>= 1;
	}
	return ret;
}

LL gao(LL a, LL b) {
	if (b == 1) return 0;
	LL t(phi(b));
	return gao(a, t+gao(a, t), b);
}

void gen() {
	for (int i=0; i<5; ++i) for (int j=2; j<13; ++j) res[p[i]][j] = gao(p[i], f[j]);
}

int main() {
	int i, j, k;
	int m, n;
	
	//freopen("f:\\in.txt", "r", stdin);
	gen();
	scanf("%d %d", &m, &n);
	while (true) {
		printf("%lld\n", res[m][n]);
		if (scanf("%d %d", &m, &n) == EOF) break;
		puts("");
	}
	return 0;
}