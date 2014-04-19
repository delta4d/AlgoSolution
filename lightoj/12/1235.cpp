#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int x[20];
vector <int> f[2], a, b;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

void gao(int l, int r, vector<int>&a) {
	int c = 0, p = 1;
	f[0].clear(); f[1].clear();
	f[0].push_back(0);
	for (int i=l; i<=r; ++i) {
		int cc = x[i];
		p = c ^ 1;
		for (int j=0; j<(int)f[c].size(); ++j) {
			for (int k=0; k<3; ++k) f[p].push_back(f[c][j]+cc*k);
		}
		f[c].clear();
		c = p;
		sort(f[c].begin(), f[c].end());
		f[c].erase(unique(f[c].begin(), f[c].end()), f[c].end());
	}
	a = f[c];
}

int main() {
	int tc, cn = 0, n, k;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), k =fastin<int>();
		bool find_one = false;
		for (int i=0; i<n; ++i) x[i] = fastin<int>();
		gao(0, n/2, a);
		gao(n/2+1, n-1, b);
		for (int i=0; i<(int)a.size(); ++i) {
			int cc = a[i];
			if (cc > k) break;
			if (cc == k) { find_one = true; break; }
			if (*lower_bound(b.begin(), b.end(), k-cc) == k - cc) { find_one = true; break; }
		}
		printf("Case %d: %s\n", ++cn, find_one?"Yes":"No");
	}
	return 0;
}

// 259689	2013-09-04 22:13:30	 1235 - Coin Change (IV)	 C++	 0.348	 1916	Accepted
