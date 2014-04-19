#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll n, tot = 1, cc = 1;
		scanf("%lld", &n);
		for (ll i=0; i<n; ++i) {
			cc = cc * (n - i) % 10000;
			if (!cc) break;
			tot = (tot + cc) % 10000;
		}
		if (n < 7) printf("Case %d: %lld\n", ++cn, tot);
		else printf("Case %d: %04lld\n", ++cn, tot);
	}
	return 0;
}

// 256843	2013-08-28 15:51:21	 1322 - Worst Case Trie	 C++	 0.008	 1088	Accepted
