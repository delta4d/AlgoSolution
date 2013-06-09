#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 100000 + 86;
const int MAXA = 10000000 + 86;
const LL MOD = 1000000007;

LL a[MAXN];
set <LL> b;
set <LL>::iterator it;

struct BIT {
	LL x[MAXA+10], a[MAXA+10], n;

	void init(int _n=MAXA) { n = _n; }
	LL sum(int p) {
		LL r = 0;
		for (int i=p; i>0; i-=i&-i) r = (r + x[i]) % MOD;
		return r < 0 ? r + MOD : r;
	}
	void add(int p, const LL off) {
		a[p] = (a[p] + off) % MOD;
		for (int i=p; i<=n; i+=i&-i) x[i] = (x[i] + off) % MOD;
	}
} p;

int main() {
	ios_base::sync_with_stdio(false);
	p.init();

	int n;

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	LL tot = 0;
	for (int i=0; i<n; ++i) {
		LL k = -1;
		if (!b.empty()) {
			it = b.upper_bound(a[i]);
			if (it != b.begin()) --it; 
			if (*it <= a[i]) k = *it;
		}
		LL x = 0, y;
		if (k != -1) {
			x = (p.sum(k) * a[i] + a[i]) % MOD, y = p.a[a[i]];
			p.add(a[i], x - y);
			if (k == a[i]) x = (x - y) % MOD;
		} else {
			x = a[i];
			p.add(a[i], a[i]);
		}
		tot = (tot + x) % MOD;
		b.insert(a[i]);
	}
	cout << (tot < 0 ? tot + MOD : tot) << endl;

	return 0;
}

// 3845380	 Jun 8, 2013 9:21:46 AM	delta_4d	 C - Sereja and Subsequences	 GNU C++	Accepted	109 ms	160600 KB
