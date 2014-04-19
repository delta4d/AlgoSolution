#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1000;

struct ChineseRemainderTh {
	ll b[MAXN], m[MAXN], c, r;

	void init() {
		c = 0;
	}

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

	ll mod_inv(ll a, ll n) {
		ll x, y;
		ext_gcd(a, n, x, y);
		x %= n;
		if (x < 0) x += n;
		return x;
	}
	
	// _x = _b (mod _m)
	void add(ll _b, ll _m) {
		b[c] = _b, m[c] = _m, ++c;
	}

	ll run() {
		ll M = 1, MR, re = 0;
		for (int i=0; i<c; ++i) M *= m[i];
		for (int i=0; i<c; ++i) {
			MR = M / m[i] * mod_inv(M/m[i], m[i]) % M;
			re = (re + b[i] * MR % M) % M;
//			printf("%lld %lld %lld\n", M/m[i], MR, M);
		}
		return r = (re + M) % M;
	}
} cr;

ll f(ll n, ll p) {
	ll r = 0;
	for (ll x=p; x<=n; x*=p) r += n / x;
	return r;
}

ll po(ll x, ll e, ll m) {
	ll r = 1;
	for (x%=m; e; e>>=1,x=x*x%m) if (e & 1) r = r * x % m;
	return r;
}

void sim(ll &x, ll p) {
	for (; x%p==0; x/=p);
}

ll C(ll L, ll M, ll p, ll e, ll x) {
	ll cp = f(L, p) - f(M, p) - f(L-M, p);
	if (cp >= e) return 0;
	ll r = 1;
	for (ll i=0; i<M; ++i) {
		ll a = L - i, b = i + 1;
		sim(a, p); sim(b, p);
		r = r * a % x;
		r = r * cr.mod_inv(b, x) % x;
	}
	r = r * po(p, cp, x) % x;
	return (r + x) % x;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		cr.init();
		ll N, K, L, M, R;
		scanf("%lld%lld%lld%lld", &N, &K, &L, &M);
		if (M > 0) {
			if (K & 1) {
				R = ((K - 1) / 2) * po(K-1, M-1, N) % N;
				R = R * po(K, L, N) % N;
			} else {
				R = K / 2 * po(K, L-1, N) % N;
				R = R * po(K-1, M, N) % N;
			}
			ll n = N;
			if (L - M < M) M = L - M;
			for (ll i=2; i*i<=n; ++i) if (n % i == 0) {
				ll c = 0, t = 1;
				for (; n%i==0; n/=i,t*=i,++c);
				ll r = C(L, M, i, c, t);
				cr.add(r, t);
			}
			if (n != 1) cr.add(C(L, M, n, 1, n), n);
			R = R * cr.run() % N;
		} else {
			R = po(K, L, N);
		}
		if (R < 0) R += N;
		printf("Case %d: %lld\n", ++cn, R+1);
	}
	return 0;
}

// 251671	2013-08-14 21:14:12	 1318 - Strange Game	 C++	 0.732	 1108	Accepted
