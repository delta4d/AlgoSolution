#include <cstdio>
using namespace std;
typedef long long LL;

inline LL odd(LL x) {
	return x >= 0 ? (x + 1) / 2 : x / 2;
}

inline LL even(LL x) {
	return x - odd(x);
}

inline LL calc(LL x1, LL x2, LL y) {
	return (odd(x2) - odd(x1)) * odd(y) + (even(x2) - even(x1)) * even(y);
}

int main() {
	LL x0, y0, x1, y1, x2, y2;
	LL i, j, k;
	LL n;
	LL b;
	LL w;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%lld", &n) != EOF) {
		b = w = 0;
		scanf("%lld %lld", &x0, &y0);
		x1 = x0; y1 = y0;
		for (i=1; i<n; ++i) {
			scanf("%lld %lld", &x2, &y2);
			if (y2 == y1) {
				b += (x2 - x1) * y1;
				w += calc(x1, x2, y1);
			}
			x1 = x2;
			y1 = y2;
		}
		x2 = x0; y2 = y0;
		if (y2 == y1) {
			b += (x2 - x1) * y1;
			w += calc(x1, x2, y1);
		}
		b = b < 0 ? -b : b;
		w = w < 0 ? -w : w;
		b -= w;
		printf("%lld %lld\n", w, b);
	}

	return 0;
}
