#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 100000 + 86;
const int M = 1000000007;

map <int, int> mp;
int x[N], y[N];

struct BIT {
	ll x[N+10];
	int n;

	void init(int _n=N) {
		n = _n;
		fill(x, x+n, 0);
	}

	void add(int p, ll k) {
		for (int i=p; i<n; i+=i&-i) x[i] = (x[i] + k) % M;
	}

	ll sum(int p) {
		ll ret = 0;
		for (int i=p; i>0; i-=i&-i) ret = (ret + x[i]) % M;
		return ret;
	}
} T;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	T sgn = 1;
	while (c < '0' || c > '9') {
		c = getchar();
		if (c == '-') sgn = -1;
	}
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return sgn * a;
}

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		mp.clear();
		T.init(n+5);
		for (int i=0; i<n; ++i) x[i] = y[i] = fastin<int>();
		sort(y, y+n);
		int m = unique(y, y+n) - y;
		for (int i=0; i<m; ++i) mp[y[i]] = i + 1;
		ll tot = 0;
		for (int i=0; i<n; ++i) {
			int p = mp[x[i]];
			ll cc = T.sum(p - 1);
			T.add(p, cc + 1);
			tot = (tot + cc + 1) % M;
		}
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 259330	2013-09-03 22:40:28	 1085 - All Possible Increasing Subsequences	 C++	 0.784	 7396	Accepted
