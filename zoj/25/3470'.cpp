#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

inline LL _abs(const LL x) {
	return x > 0 ? x : -x;
}

const LL dx[4] = {0, 1, 0, -1};
const LL dy[4] = {-1, 0, 1, 0};

inline LL f(LL x, LL y) {
	if (x >= 0 && x + y == 0) return ((x << 1) + 1) * ((x << 1) + 1);
	if (x >= 0 && x == y) return ((x << 1) - 1) * ((x << 1) - 1) + (x << 1);
	if (x <= 0 && x + y == 0) return ((y << 1) - 1) * ((y << 1) - 1) + (y << 2);
	if (x <= 0 && x == y) return (((-x) << 1) - 1) * (((-x) << 1) - 1) + ((-x) * 6);
	if (_abs(y) < x) return f(x, x) + y - x;
	if (_abs(y) < -x) return f(x, -x) - x - y;
	if (_abs(x) < y) return f(y, y) + y - x;
	if (_abs(x) < -y) return f(y, y) + x - y;
}

inline void rf(LL n, LL &x, LL &y) {
	LL i, j, k;
	LL a;
	k = LL(sqrt(n));
	for (i=1; i>=-1; --i) if ((k + i) * (k + i) <= n) {k += i; break;}
	if (!(k & 1)) --k;
	a = n - k * k;
	k = (k + 1) >> 1;
	if (a == 0) x = k - 1, y = -x;
	else if (a <= 2 * k) x = k, y = a - k;
	else if (a <= 4 * k) x = 3 * k - a, y = k;
	else if (a <= 6 * k) x = -k, y = 5 * k - a;
	else x = a - 7 * k, y = -k;
}

int main() {
	LL tc;
	LL n;
	LL x, y;
	LL out[4];
	LL i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%lld", &tc);
	while (tc--) {
		scanf("%lld", &n);
		rf(n, x, y);
		//printf("%lld\n", f(0, 0));
		for (i=0; i<4; ++i) 
			out[i] = f(x+dx[i], y+dy[i]);
		sort(out, out+4);
		for (i=0; i<4; ++i) printf("%lld%s", out[i], i==3?"\n":" ");
	}
	return 0;
}