#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 64;

long long f[MAXN][2][2];
char s[MAXN];
long long n, k;

long long gao(int p, bool inv, bool rev) {
	if (f[p][inv][rev] != -1) return f[p][inv][rev];	
	f[p][inv][rev] = 0;
	int q = n - p - 1;
	if (p > q) return ++f[p][inv][rev];
	for (int i=0; i<2; ++i) if (s[p] == 0 || s[p] == i + '0') {
		for (int j=0; j<2; ++j) if (s[q] == 0 || s[q] == j + '0') {
			if ((p < q || i == j) && (inv || i <= j) && (rev || !i || !j)) {
				f[p][inv][rev] += gao(p+1, inv || i < j, rev || !i && !j);
			}
		}
	}
	return f[p][inv][rev];
}

int main() {
	cin >> n >> k;
	memset(f, -1, sizeof(f));
	if (gao(0, 0, 0) <= k) { puts("-1"); return 0; }
	for (int i=0; i<n; ++i) {
		memset(f, -1, sizeof(f));
		s[i] = '0';
		long long cc = gao(0, 0, 0);
//		cout << i << ' ' << cc << endl;
		if (cc <= k) k -= cc, ++s[i];
	}	
	puts(s);

	return 0;
}

// 3636419	 Apr 26, 2013 6:35:21 PM	delta_4d	 E - Beads	 GNU C++	Accepted	31 ms	8 KB
