#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	ll tc, cn = 0, a, b, c;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld%lld", &a, &b, &c);
		a *= a, b *= b, c *= c;
		if (a + b == c || a + c == b || b + c == a) printf("Case %lld: yes\n", ++cn);
		else printf("Case %lld: no\n", ++cn);
	}
	return 0;
}

// 252021	2013-08-15 20:23:25	 1053 - Higher Math	 C++	 0.000	 1088	Accepted
