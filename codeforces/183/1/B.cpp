#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
	LL n, m, x, y, a, b;
	LL x1, y1, x2, y2;

	cin >> n >> m >> x >> y >> a >> b;

	LL d = __gcd(a, b);
	a /= d, b /= d;

	LL k = min(n / a, m / b);

	if ((a * k + 1) / 2 <= x && x + a * k / 2 <= n &&
			(b * k + 1) / 2 <= y && y + b * k / 2 <= m) {
		x1 = x - (a * k + 1) / 2, x2 = x + a * k / 2;
		y1 = y - (b * k + 1) / 2, y2 = y + b * k / 2;
	} else {
		if (x < (a * k + 1) / 2) x1 = 0, x2 = a * k;
		else if (x + a * k / 2 > n) x1 = n - a * k, x2 = n;
		else x1 = x - (a * k + 1) / 2, x2 = x + a * k / 2;

		if (y < (b * k + 1) / 2) y1 = 0, y2 = b * k;
		else if (y + b * k / 2 > m) y1 = m - b * k, y2 = m;
		else y1 = y - (b * k + 1) / 2, y2 = y + b * k / 2;
	}

	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

	return 0;
}

// 3710797	 May 12, 2013 6:36:53 PM	delta_4d	 B - Rectangle Puzzle II	 GNU C++	Accepted	 15 ms	 0 KB
