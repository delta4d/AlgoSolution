#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000 + 86;
#define LS(x) ((x)<<1)
#define RS(x) (LS(x)^1)

vector <int> x, s, t;
map <int, int> mp;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

struct BIT {
	int x[N+10], n;

	void init(int _n=N+5) {
		n = _n;
		fill(x, x+n, 0);
	}

	void add(int p, int off) {
		for (int i=p; i<n; i+=i&-i) x[i] += off;
	}

	int sum(int p) {
		int tot = 0;
		for (int i=p; i>0; i-=i&-i) tot += x[i];
		return tot;
	}
} T;

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		x.clear(), s.clear(), t.clear(), mp.clear();
		n = fastin<int>();
		for (int i=0,a,b; i<n; ++i) {
			a = fastin<int>(), b = fastin<int>();
			x.push_back(a), x.push_back(b);
			s.push_back(a), t.push_back(b);
		}
		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());
		int m = (int)x.size();
		for (int i=0; i<m; ++i) mp[x[i]] = i + 1;
		T.init(m+5);
		for (int i=0; i<(int)s.size(); ++i) {
			T.add(mp[s[i]], 1);
			T.add(mp[t[i]]+1, -1);
		}
		int mx = 0;
		for (int i=0; i<m; ++i) mx = max(mx, T.sum(i+1));
		printf("Case %d: %d\n", ++cn, mx);
	}
	return 0;
}

// 280156	2013-10-28 20:17:12	 1301 - Monitoring Processes	 C++	 0.756	 6988	Accepted
