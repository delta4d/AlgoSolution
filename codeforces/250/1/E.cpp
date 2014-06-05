#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
using vl = vector <ll>;

ll const M = (1 << 23) * 7 * 17 + 1;

vl c;

ll power_mod(ll x, ll e) {
	ll r = 1;
	for (x%=M; e; x=x*x%M,e>>=1) if (e & 1) r = r * x % M;
	return r;
}

ll mod_inv(ll a) {
	return power_mod(a, M-2);
}

void fft(vl &a, bool inv) {
	int n = (int)a.size(), nb = __builtin_ctz(n);
	if (n & (n-1)) {
		cout << "-- " << n << endl;
		throw "n should be power of 2";
	}
	for (int i=0,j,k; i<n; ++i) {
		for (j=k=0; k<nb; ++k) if (i & 1 << k) j |= 1 << (nb - k - 1);
		if (i < j) swap(a[i], a[j]);
	}
	for (int step=2; step<=n; step<<=1) {
		if ((M - 1) % step) throw "step | M - 1";
		ll r = power_mod(3, (M-1)/step);
		if (inv) r = mod_inv(r);
		for (int i=0,step2=step>>1; i<n; i+=step) {
			ll w = 1;
			for (int j=0; j<step2; ++j) {
				ll x = a[i+j], y = w * a[i+j+step2] % M;
				a[i+j] = (x + y) % M, a[i+j+step2] = (M + x - y) % M;
				w = w * r % M;
			}
		}
	}
	if (inv) for (int i=0,iv=mod_inv(n); i<n; ++i) a[i] = a[i] * iv % M;
}

void poly_mul(vl &a, vl b) {
	int n = max((int)a.size(), (int)b.size()) << 1;
	a.resize(n), b.resize(n);
	fft(a, false), fft(b, false);
	for (int i=0; i<(int)a.size(); ++i) a[i] = a[i] * b[i] % M;
	fft(a, true);
}

void poly_inv(vl &a) {
	int n = (int)a.size();
	vl ret;
	ret.push_back(mod_inv(a[0]));
	for (int i=2; i<=n; i<<=1) {
		vl f(a.begin(), a.begin()+i), tmp(ret);
		poly_mul(tmp, tmp);
		poly_mul(tmp, f);
		ret.resize(i, 0);
		for (int j=0; j<i; ++j) {
			ret[j] = (2 * ret[j] - tmp[j]) % M;
			if (ret[j] < 0) ret[j] += M;
		}
	}
	a = ret;
}

void poly_sqrt(vl &a) {
	int n = (int)a.size();
	vl ret;
	ret.push_back(1);
	ll i2 = mod_inv(2);
	for (int i=2; i<=n; i<<=1) {
		vl tmp(ret), f(a.begin(), a.begin()+i);
		poly_inv(tmp);
		poly_mul(f, tmp);
		ret.resize(i, 0);
		for (int j=0; j<i; ++j) {
			ret[j] = (ret[j] + f[j]) % M;
			ret[j] = ret[j] * i2 % M;
		}
	}
	a = ret;
}

void test() {
	int n = 8;
	cout << mod_inv(n) << endl;
	vl a, b;
	a.resize(n, 0), b.resize(n, 0);
	a[0] = 1, a[1] = 2;
	b[0] = 3, b[1] = 4;
	poly_mul(a, b);
	for (int i=0; i<n; ++i) cout << a[i] << " "; cout << endl;

	a.clear(), b.clear();
	a.resize(n, 0);
	a[0] = 1, a[1] = 2;
	b = a;
	poly_inv(b);
	for (int i=0; i<n; ++i) cout << b[i] << " "; cout << endl;
	poly_mul(a, b);
	for (int i=0; i<n; ++i) cout << a[i] << " "; cout << endl;
}

int main() {
//	test();
	ios_base::sync_with_stdio(false);
	ll n, m, sz=1;
	cin >> n >> m;
	for (; sz<=2*m; sz<<=1);
	c.resize(sz, 0);
	for (ll i=0,x; i<n; ++i) {
		cin >> x;
		if (x >= sz) continue;
		c[x] = M - 4;
	}
	c[0] = 1;
	poly_sqrt(c);
	c[0] = (c[0] + 1) % M;
	poly_inv(c);
	for (int i=1; i<=m; ++i) {
		c[i] = 2 * c[i] % M;
		if (c[i] < 0) c[i] += M;
		cout << c[i] << endl;
	}
	return 0;
}

// 6817033	 2014-06-05 09:31:30	delta_4d	 E - The Child and Binary Tree	 GNU C++0x	Accepted	 4617 ms	 16900 KB
