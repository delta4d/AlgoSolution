#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef map <ll, ll> MP;
typedef MP::iterator MPI;

MP f[2];
vector <ll> a, sa, b, sb;
ll x[32];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

void gao(int l, int r, vector <ll> &a, vector <ll> &sa) {
	f[0].clear(); f[1].clear(); a.clear(); sa.clear();
	f[0][0] = 1;
	int c = 0, p = 1;
	for (int k=l; k<=r; ++k) {
		ll cc = x[k];
		p = c ^ 1;
		f[p] = f[c];
		for (MPI it=f[c].begin(); it!=f[c].end(); ++it) {
			ll x = it->first, y = it->second;
			f[p][x+cc] += y;
		}
		c = p;
	}
	for (MPI it=f[c].begin(); it!=f[c].end(); ++it) {
		ll x = it->first, y = it->second;
		a.push_back(x);
		if (l) sa.push_back(y+(sa.empty()?0:sa.back()));
		else sa.push_back(y);
	}
}

int main() {
	int tc, cn = 0, n, w;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), w = fastin<int>();
		for (int i=0; i<n; ++i) x[i] = fastin<int>();
		gao(0, n/2, a, sa);
		gao(n/2+1, n-1, b, sb);
		ll tot = 0;
		int sz = (int)b.size();
		for (int i=0; i<(int)a.size(); ++i) {
			ll cc = a[i];
			if (cc > w) break;
			int j = upper_bound(b.begin(), b.end(), w-cc) - b.begin() - 1;
			if (j >= 0 && j < b.size()) tot += sa[i] * sb[j];
//			printf("%d -- %d == %lld -- %lld\n", i, j, sa[i], sb[j]);
		}
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 259709	2013-09-04 23:10:37	 1127 - Funny Knapsack	 C++	 0.392	 8784	Accepted
