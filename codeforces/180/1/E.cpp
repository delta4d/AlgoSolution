#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;
typedef long long LL;
typedef pair <int, int> PII;

vector <PII> e;
int x[MAXN], y[MAXN];
int mp[MAXN<<1];

inline int lowbit(const int x) { return x & -x; }

template <typename T>
struct BIT {
	int n;
	T x[MAXN << 2];

	void init(int _n=MAXN) {
		n = _n;
		memset(x, 0, n*sizeof(T));
	}

	void add(int p, T off) {
		for (; p<=n; p+=lowbit(p)) x[p] += off;
	}

	T sum(int p) {
		T tot = T();
		for (; p>=1; p-=lowbit(p)) tot += x[p];
		return tot;
	}
};

BIT <int> T;

int main() {
	ios_base::sync_with_stdio(false);

	int n, m, a, b;
	cin >> n; m = n << 1;
	T.init(m+m+10);
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		e.push_back(make_pair(b, a));
		e.push_back(make_pair(a+m, b));
		e.push_back(make_pair(b+m, a+m));
		mp[b] = i;
	}
	sort(e.begin(), e.end());
	for (int i=0,t=m+n; i<t; ++i) {
		a = e[i].first, b = e[i].second;
		int c = T.sum(a) - T.sum(b-1);
		if (a <= m && b <= m) x[mp[a]] = c;
		else if (a > m && b <= m) y[mp[b]] = c;
		T.add(b, 1);
	}
//	cout << "x: "; for (int i=0; i<n; ++i) cout << x[i] << ' '; cout << endl;
//	cout << "y: "; for (int i=0; i<n; ++i) cout << y[i] << ' '; cout << endl;
	LL c0 = LL(n) * (n - 1LL) * (n - 2LL) / 6LL, c1 = 0, c2 = 0;
	for (int i=0; i<n; ++i) {
		c1 += (LL)x[i] * y[i];	
		c2 += (LL)(x[i] + y[i]) * (LL)(n - x[i] - y[i] - 1LL);
	}
	c2 >>= 1LL;
	cout << c0 - c1 - c2 << endl;

	return 0;
}

// 3585424	 Apr 21, 2013 6:19:12 PM	delta_4d	 E - Mystic Carvings	 GNU C++	Accepted	125 ms	
