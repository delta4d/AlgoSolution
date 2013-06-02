#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long LL;

const int MAXN = 2000000 + 86;

LL x[MAXN];

inline bool p4(int x) {
	for (; x>1; x>>=2) if (x % 4) return false;	
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i=0; i<n; ++i) cin >> x[i];
	sort(x, x+n, greater<LL>());
	int m = (__builtin_ctz(n) >> 1) + 1;
	LL tot = 0;
	for (int i=0; i<n; ++i) {
		tot += m * x[i];
//		cout << m << ' ' << x[i] << endl;
		if (p4(i+1)) --m;
	}
	cout << tot << endl;

	return 0;
}

// 3798729	 May 30, 2013 8:04:59 PM	* delta_4d	 C - Ilya and Matrix	 GNU C++	Accepted	 406 ms	 15700 KB
