#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 100000 + 86;

int n, m;
int x[MAXN][2], y[MAXN][2];
LL mx;

int init(int x[][2], int dx, const int xs, const int n) {
	for (int i=0,cx=xs; i<2*n-2; ++i, cx+=dx) {
		x[cx][!!x[cx][0]] = i + 1;
		if (cx + dx < 1) dx = 1;
		else if (cx + dx > n) dx = -1;
	}
}

LL ex_gcd(LL a, LL b, LL &x, LL &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}	
	LL ret = ex_gcd(b, a%b, x, y);
	LL t = x;
	x = y, y = t - a / b * y;
	return ret;
}

// x = a1 (mod m1), x = a2 (mod m2)
LL gao(LL a1, LL m1, LL a2, LL m2) {
	a2 -= a1;	
	LL x, y, d = ex_gcd(m1, m2, x, y); // m1x + m2y = d
	if (a2 % d) return -1;
	m2 /= d, a2 /= d;
	x %= m2;
	x = x * a2 % (m1 * m2);
	x = (m1 * x + a1) % (m1 * m2);
	if (x < 0) x += m1 * m2;
	return x + 1;
}

LL gao(int a, int b) {
	LL cc = -1;
	for (int i=0; i<2; ++i) for (int j=0; j<2; ++j) {
		if (!x[a][i] || !y[b][j]) continue;
		LL k = gao(x[a][i]-1, 2*n-2, y[b][j]-1, 2*m-2);
		if (k != -1 && (k < cc || cc == -1)) cc = k;
	}	
	if (cc != -1 && mx < cc) mx = cc;
	return cc == -1 ? 0 : cc;
}

int main() {
	int xs, ys;
	int dx, dy;
	char d[4];

	scanf("%d%d%d%d%s", &n, &m, &xs, &ys, d);
	dx = d[0] == 'D' ? 1 : -1; dy = d[1] == 'R' ? 1 : -1;
	init(x, dx, xs, n); init(y, dy, ys, m);
	int k = (xs + ys) % 2;
	for (int i=1; i<=n; ++i) if ((i + 1) % 2 == k) if (!gao(i, 1)) return puts("-1"), 0;
	for (int i=1; i<=n; ++i) if ((i + m) % 2 == k) if (!gao(i, m)) return puts("-1"), 0;
	for (int i=1; i<=m; ++i) if ((i + 1) % 2 == k) if (!gao(1, i)) return puts("-1"), 0;
	for (int i=1; i<=m; ++i) if ((i + n) % 2 == k) if (!gao(n, i)) return puts("-1"), 0;
	printf("%I64d\n", mx);

	return 0;
}

// 3696549	 May 9, 2013 6:49:23 PM	delta_4d	 D - Shaass and Painter Robot	 GNU C++	Accepted	187 ms	1544 KB
