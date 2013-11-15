#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

inline int abs(const int x) {
	return x > 0 ? x : -x;
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

inline int f(int x, int y) {
	if (x > 0 && x + y == 0) return ((x << 1) + 1) * ((x << 1) + 1);
	if (x > 0 && x == y) return ((x << 1) - 1) * ((x << 1) - 1) + (x << 1);
	if (x < 0 && x + y == 0) return ((y << 1) - 1) * ((y << 1) - 1) + (y << 2);
	if (x < 0 && x == y) return (((-x) << 1) - 1) * (((-x) << 1) - 1) + ((-x) * 6);
	if (abs(y) < x) return f(x, x) + y - x;
	if (abs(y) < -x) return f(x, -x) - x - y;
	if (abs(x) < y) return f(y, y) + y - x;
	if (abs(x) < -y) return f(y, y) + x - y;
}

inline void rf(int n, int &x, int &y) {
	int i, j, k;
	int a;
	k = int(sqrt(n));
	for (i=1; i>=-1; --i) if ((k + i) * (k + i) <= n) {k += i; break;}
	if (!(k & 1)) --k;
	a = n - k * k;
	k = (k + 1) >> 1;
	if (a <= 2 * k) x = k, y = a + 1 - k;
	else if (a <= 4 * k) x = 3 * k - a, y = k;
	else if (a <= 6 * k) x = -k, y = 5 * k - a;
	else x = 5 * k + a, y = -k;
}

int main() {
	int tc;
	int n;
	int x, y;
	int out[4];
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		rf(n, x, y);
		for (i=0; i<4; ++i) out[i] = f(x+dx[i], y+dy[i]);
		sort(out, out+4);
		for (i=0; i<4; ++i) printf("%d%s", out[i], i==3?"\n":" ");
	}
	return 0;
}