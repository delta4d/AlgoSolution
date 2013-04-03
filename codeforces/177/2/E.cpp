#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;

bool v[MAXN];
long long x[MAXN];

inline long long gao(long long n) {
	for (long long i=31; i>=0; --i) if (n & (1 << i)) return (1 << (i + 1)) - n - 1;
	return 0;
}

int main() {
	long long n, tot = 0;

	cin >> n;

	for (long long i=n; i>=0; --i) if (!v[i]) {
		long long j = gao(i);
		v[i] = v[j] = true;
		tot += (i ^ j) * 2;
		x[i] = j, x[j] = i;
//		cout << i << '^' << j << ' ' << (i^j) << endl;
	}
	cout << tot << endl;
	for (int i=0; i<=n; ++i) cout << x[i] << (i == n ? "\n" : " ");

	return 0;
}

// 3459882	 Apr 2, 2013 8:31:18 PM	delta_4d	 C - Polo the Penguin and XOR operation	 GNU C++	Accepted	 468 ms	 8800 KB
