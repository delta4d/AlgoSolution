#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int a[100000 + 86];

int main() {
	ios_base::sync_with_stdio(false);
	int tc, cn = 0, n, k, c;
	for (cin>>tc; tc--; ) {
		cin >> k >> c >> n >> a[0];
		for (int i=1; i<n; ++i) a[i] = ((ll)k * a[i-1] + c) % 1000007;
		sort(a, a+n);
		ll tot = 0, s = 0;
		for (int i=0; i<n; ++i) tot += (ll)i * a[i] - s, s += a[i];
		cout << "Case " << ++cn << ": " << tot << endl;
	}
	return 0;
}

// 276336	2013-10-21 14:12:06	 1328 - A Gift from the Setter	 C++	 0.492	 2068	Accepted
