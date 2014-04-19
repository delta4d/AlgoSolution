#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;
const double eps = 1e-7;

ll leading(ll x, ll e) {
	double t = e * log10(x * 1.0);
	t = t - (ll)floor(t);
	double xt = pow(10.0, t);
	ll xx = xt * 1000;// + eps;
	while (xx >= 1000) xx /= 10;
	return xx;
}

ll trailing(ll x, ll e) {
	ll r = 1, m = 1000;
	for (x%=m; e; e>>=1,x=x*x%m) if (e & 1) r = r * x % m;
	return r;
}

int main() {
	ll tc, cn = 0, n, k;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld", &n, &k);
		printf("Case %lld: %03lld %03lld\n", ++cn, leading(n, k), trailing(n, k));
	}
	return 0;
}

// 250052	2013-08-10 15:50:25	 1282 - Leading and Trailing	 C++	 0.004	 1328	Accepted
