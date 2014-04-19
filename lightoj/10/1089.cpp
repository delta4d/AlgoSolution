#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 50000 + 86;
#define pos(x) (lower_bound(d.begin(), d.end(), (x))-d.begin() + 1)

int x[N], y[N], p[N];
vector <int> d;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

struct BIT {
	int x[3*N+10], n;

	void init(int _n=3*N) {
		n = _n;
		fill(x, x+n, 0);
	}

	void add(int p, int off) {
		for (; p<=n; p+=p&-p) x[p] += off;
	}

	int sum(int p) {
		int ret = 0;
		for (; p>0; p-=p&-p) ret += x[p];
		return ret;
	}
} T;

int main() {
	int tc, cn = 0, n, q;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), q = fastin<int>();
		d.clear();
		for (int i=0; i<n; ++i) {
			x[i] = fastin<int>(), y[i] = fastin<int>();
			d.push_back(x[i]), d.push_back(y[i]);
		}
		for (int i=0; i<q; ++i) p[i] = fastin<int>(), d.push_back(p[i]);
		sort(d.begin(), d.end());
		d.erase(unique(d.begin(), d.end()), d.end());
		T.init((int)d.size()+2);
		printf("Case %d:\n", ++cn);
		for (int i=0; i<n; ++i) {
			T.add(pos(x[i]), 1);
			T.add(pos(y[i])+1, -1);
		}
		for (int i=0; i<q; ++i) {
			printf("%d\n", T.sum(pos(p[i])));
		}
	}
	return 0;
}

// 293789	2013-12-01 12:32:56	 1089 - Points in Segments (II)	 C++	 0.300	 3932	Accepted
