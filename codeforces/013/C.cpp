#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 86;

long long a[MAXN], b[MAXN];
long long f[2][MAXN];

inline long long D(int i, int j) { return abs(a[i] - b[j]); }

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i], b[i] = a[i];
	sort(b, b+n);
	k = unique(b, b+n) - b;
	int cc = 0, nt = cc ^ 1;
	f[cc][0] = D(0, 0);
	for (int i=1; i<k; ++i) f[cc][i] = min(f[cc][i-1], D(0, i)); 
	for (int i=1; i<n; ++i,cc=nt) {
		nt = cc ^ 1;
		f[nt][0] = f[cc][0] + D(i, 0);
		for (int j=1; j<k; ++j) f[nt][j] = min(f[nt][j-1], f[cc][j]+D(i, j));
	}
	cout << f[cc][k-1] << endl;

	return 0;
}

// 3665042	 May 3, 2013 6:49:30 PM	delta_4d	 C - Sequence	 GNU C++	Accepted	140 ms	160 KB
