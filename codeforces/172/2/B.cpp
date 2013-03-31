#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	LL x, y, n;

	cin >> x >> y >> n;
	LL d = __gcd(x, y);
	x /= d, y /= d;

	if (y <= n) {
		cout << x << '/' << y << endl;
		return 0;
	}
	LL aa = 0, bb = 1;
	for (LL b=1; b<=n; ++b) {
		LL a = x * b / y;
		for (LL s=-10; s<=10; ++s) if (s + a >= 0) {
			if (abs(bb * (x * b - y * (s + a))) < abs(b * (x * bb - y * aa))) {
				aa = s + a, bb = b;
			}
		} 
	}
	cout << aa << '/' << bb << endl;

	return 0;
}

// 3427744	 Mar 31, 2013 6:25:02 PM	delta_4d	 281B - Nearest Fraction	 GNU C++	Accepted	46 ms	0 KB
