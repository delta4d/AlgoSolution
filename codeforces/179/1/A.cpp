#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 100000 + 86;

inline int lowbit(const int x) {
	return x & -x;
}

template <class T>
struct BIT {
	int n;
	T x[MAXN + 1];

	void init(LL _n=MAXN) {
		n = _n;
		memset(x, 0, sizeof(x));
	}
	void add(int p, T off) {
		for (; p<=n; p+=lowbit(p)) x[p] += off;
	}
	void add_interval(int l, int r, T off) {
		add(l, off);
		add(r+1, -off);
	}
	T sum(int p) {
		T tot = 0;
		for (; p>=1; p-=lowbit(p)) tot += x[p];
		return tot;
	}
};

BIT <LL> op, a;
LL l[MAXN], r[MAXN], d[MAXN];

int main() {
	ios_base::sync_with_stdio(false);

	int n, m, k;
	int x, y;

	cin >> n >> m >> k;	

	op.init(m+10);
	a.init(n+10);

	for (int i=1; i<=n; ++i) {
		cin >> x;
		a.add_interval(i, i, x);
	}
	for (int i=1; i<=m; ++i) cin >> l[i] >> r[i] >> d[i];
	for (int i=0; i<k; ++i) {
		cin >> x >> y;	
		op.add_interval(x, y, 1);
	}
	for (int i=1; i<=m; ++i) a.add_interval(l[i], r[i], op.sum(i)*d[i]);
	for (int i=1; i<=n; ++i) cout << a.sum(i) << (i < n ? " " : "\n");

	return 0;
}

// 3516084	 Apr 12, 2013 10:08:47 AM	delta_4d	 295A - Greg and Array	 GNU C++	Accepted	 234 ms	 3900 KB
