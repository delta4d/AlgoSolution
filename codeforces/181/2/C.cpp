#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;
const int MAXN = 1000000 + 86;

LL C[MAXN];

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

template <class T> T modInv(T a, T n) {
	T x, y;
	extGcd(a, n, x, y);
	x %= n;
	if (x < 0) x += n;
	return x;
}

void init(const int n) {
	C[0] = 1;
	for (LL i=1; i<=n; ++i) {
		LL r = modInv(i, MOD) * (n - i + 1) % MOD;
		C[i] = r * C[i-1] % MOD; 
	}
//	for (int i=0; i<=n; ++i) cout << C[i] << ' '; cout << endl;
}

bool ok(LL x, LL a, LL y, LL b) {
	LL n = x * a + y * b;
	for (; n; n/=10) if (n % 10 != a && n % 10 != b) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL a, b, n;
	LL tot = 0;

	cin >> a >> b >> n;
	init(n);
	for (int i=0; i<=n; ++i) if (ok(i, a, n-i, b)) {
		tot = (tot + C[i]) % MOD;	
	}
	cout << tot << endl;

	return 0;
}

// 3643955	 Apr 27, 2013 6:30:03 PM	delta_4d	 300C - Beautiful Numbers	 GNU C++	Accepted	578 ms	7800 KB
