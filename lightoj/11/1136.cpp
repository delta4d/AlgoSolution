#include <cstdio>
using namespace std;

typedef long long ll;

ll f(ll n) {
	return n / 3 * 2 + (n % 3 == 2);
}

int main() {
	ll tc, cn = 0, a, b;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld", &a, &b);
		printf("Case %lld: %lld\n", ++cn, f(b) - f(a-1));
	}
	return 0;
}

// 252018	2013-08-15 20:14:35	 1136 - Division by 3	 C++	 0.008	 1088	Accepted
