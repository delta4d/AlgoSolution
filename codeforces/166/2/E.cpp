#include <iostream>
#include <algorithm>
using namespace std;

long long tot;

inline long long gao(long long x, long long m) {
	long long ret = 0;
	for (; x<=m; ret+=m-x,x<<=1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m, x;

	cin >> n >> m;
	for (int i=0,j; i<n; ++i) {
		cin >> j;
		if (i == 0) x = j - 1;
		else x = __gcd(x, j-1);
	}
	for (; !(x&1); x>>=1);
	for (int i=1; i*i<=x; ++i) if (x % i == 0) {
		tot += gao(i, m);
		if (i * i != x) tot += gao(x/i, m);
	}
	cout << tot << endl;

	return 0;
}

// 3475892	 Apr 5, 2013 12:55:27 PM	delta_4d	 271E - Three Horses	 GNU C++	Accepted	31 ms	0 KB
