#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}	
	ll ret = ext_gcd(b, a%b, x, y);
	ll t = x;
	x = y, y = t - a / b * y;
	return ret;
}

int main() {
	int tc, cn = 0;
	for (cin>>tc; tc--; ) {
		cout << "Case " << ++cn << ": ";
		ll a, b, c, x1, x2, y1, y2;

		cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
		c = -c;

		if (a == 0 && b == 0) {
			if (c) cout << 0 << endl;
			else cout << (x2 - x1 + 1) * (y2 - y1 + 1) << endl;
		} else if (a == 0) {
			if (c % b) cout << 0 << endl;
			else if (c / b < y1 || c / b > y2) cout << 0 << endl;
			else cout << x2 - x1 + 1 << endl;
		} else if (b == 0) {
			if (c % a) cout << 0 << endl;
			else if (c / a < x1 || c / a > x2) cout << 0 << endl;
			else cout << y2 - y1 + 1 << endl;
		} else {
			ll x, y;
			ll d = ext_gcd(a, b, x, y);
			if (c % d) {
				cout << 0 << endl;
			} else {
				double lx = 1.0 * (c * x - d * x1) / b, rx = 1.0 * (c * x - d * x2) / b;
				double ly = 1.0 * (d * y1 - c * y) / a, ry = 1.0 * (d * y2 - c * y) / a;
				if (lx > rx) swap(lx, rx);
				if (ly > ry) swap(ly, ry);
				ll l = (ll)ceil(max(lx, ly)), r = (ll)floor(min(rx, ry));
				cout << max(0ll, r - l + 1) << endl;
			}
		}
	}
	return 0;
}

// 253387	2013-08-19 21:52:08	 1306 - Solutions to an Equation	 C++	 0.624	 1672	Accepted
