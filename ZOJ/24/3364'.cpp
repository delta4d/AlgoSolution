#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long b, w;

inline int odd(int x) {
	return x >= 0 ? (x + 1) / 2 : x / 2;
}

inline int even(int x) {
	return x - odd(x);
}

#define GAO() do {\
	if (y1 == y2) {\
		w += (long long)x2 * y2;\
		b += (long long)odd(x2) * odd(y2) + (long long)even(x2) * even(y2);\
		w -= (long long)x1 * y1;\
		b -= (long long)odd(x1) * odd(y1) + (long long)even(x1) * even(y1);\
	}\
} while (false)

int main() {
	int n, x0, y0, x1, y1, x2, y2;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		b = w = 0;
		scanf("%d%d", &x0, &y0);
		x1 = x0;
		y1 = y0;
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &x2, &y2);
			GAO();
			x1 = x2;
			y1 = y2;
		}
		x2 = x0;
		y2 = y0;
		GAO();
		w -= b;
		printf("%lld %lld\n", (long long )fabs(b), (long long)fabs(w));
	}

	return 0;
}
