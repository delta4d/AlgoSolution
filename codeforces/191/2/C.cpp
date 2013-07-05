#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100000 + 86;
const int MOD = 1000000007;

char s[MAXN];

ll power_mod(ll x, ll e) {
	ll r = 1;
	for (x%=MOD; e; e>>=1,x=x*x%MOD) if (e & 1) r = r * x % MOD;
	return r;
}

ll extGcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}	
	ll ret = extGcd(b, a%b, x, y);
	ll t = x;
	x = y, y = t - a / b * y;
	return ret;
}

ll modInv(ll a, ll n) {
	ll x, y;
	extGcd(a, n, x, y);
	x %= n;
	if (x < 0) x += n;
	return x;
}

int main() {
	ll n, k;
	cin >> s >> k;

	n = (ll)strlen(s);
	ll p2 = power_mod(2, n) - 1;
	if (p2 < 0) p2 += MOD;
	ll ip2 = modInv(p2, MOD);
	ll x = power_mod(2, n*k) - 1;
	if (x < 0) x += MOD;
	ll t = x * ip2 % MOD;
	ll tot = 0;
	for (int i=n-1; i>=0; --i) if (s[i] == '0' || s[i] == '5') {
		tot = (tot + power_mod(2, i)) % MOD;
	}
	tot = tot * t % MOD;
	if (tot < 0) tot += MOD;
	cout << tot << endl;
	return 0;
}

// 4014307	 Jul 4, 2013 4:58:28 PM	* delta_4d	 C - Magic Five	 GNU C++	Accepted	 62 ms	 100 KB
