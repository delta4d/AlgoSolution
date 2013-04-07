nclude <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

template <class T> T extGcd(T a, T b, T &x, T &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}	
	T ret = extGcd(b, a%b, x, y);
	T t = x;
	x = y, y = t - a / b * y;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	LL A, B, C;

	cin >> A >> B >> C;

	if (A == 0) {
		if (C % B == 0) cout << 0 << ' ' << -C/B << endl;
		else cout << -1 << endl;
	} else if (B == 0) {
		if (C % A == 0) cout << -C/A << ' ' << 0 << endl;	
		else cout << -1 << endl;
	} else {
		LL X, Y, D;
		D = extGcd(A, B, X, Y);
		if (C % D) {
			cout << -1 << endl;
		} else {
			X *= -C / D, Y *= -C / D;
			cout << X << ' ' << Y << endl;
		}
	}

	return 0;
}

// 3480480	 Apr 6, 2013 8:12:37 PM	delta_4d	 C - Line	 GNU C++	Accepted	 15 ms	 0 KB
