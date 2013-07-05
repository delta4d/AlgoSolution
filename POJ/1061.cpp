#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3fll;

inline LL ABS(const LL x) {return x >= 0 ? x : -x; }

LL gao(LL x, LL y, LL &a, LL &b) {
	LL ret, tt;
	if (ABS(x) >= ABS(y)) {
		 if (y == 0) {
		 	a = 1;
		 	b = 0;
		 	return x;
		 }
		 ret = gao(y, x%y, a, b);
		 tt = b;
		 b = a - (x / y) * b;
		 a = tt;
		 return ret;
	} else {
		if (x == 0) {
		 	b = 1;
		 	a = 0;
		 	return y;
		 }
		 ret = gao(y%x, x, a, b);
		 tt = a;
		 a = b - (y / x) * a;
		 b = tt;
		 return ret;
	}
}

int main() {
	LL x, y, m, n, L;
	LL a, b, c, d;
	LL i, j, k;
	LL xx, yy;
	LL res;
	
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	
	while (5 == scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &L)) {
		xx = m - n, yy = L, c = y - x;
		d = gao(xx, yy, a, b);
		if (c % d) {
			puts("Impossible");
		} else {
			res = INF;
			a *= c / d, b *= c / d;
			k = - a * d / yy;
			for (i=-10; i<=10; ++i) {
				if ((a + yy / d * (k + i)) >= 0) {
					res = min(res, (a + yy / d * (k + i)));
				}
			}
			printf("%lld\n", res);
		}
	}
	
	return 0;
}