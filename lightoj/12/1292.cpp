#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 701;
const double INF = 1e100;
const double eps = 1e-8;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	T sgn = 1;
	while (c < '0' || c > '9') {
		c = getchar();
		if (c == '-') sgn = -1;
	}
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return sgn * a;
}

inline bool zero(const double x) { return fabs(x) < eps; }

struct line {
	double k, b;

	void init(int x1, int y1, int x2, int y2) {
		if (x1 == x2) k = INF, b = x1;
		else k = 1.0 * (y2 - y1) / (x2 - x1), b = 1.0 * (1.0 * x1 * y2 - 1.0 * x2 * y1) / (x1 - x2);
	}
	bool operator<(const line &a) const { return !zero(k - a.k) ? k < a.k : b < a.b; }
	bool oneline(const line &a) const { return zero(k - a.k) && zero(b - a.b); }
} p[MAXN*MAXN];

int x[MAXN], y[MAXN];

int f(int cc) {
	int left = 1, right = MAXN, mid;
	cc <<= 1;
	while (left <= right) {
		mid = (left + right) >> 1;
		int cur = (mid - 1) * mid;
		if (cur == cc) return mid;
		if (cur < cc) left = mid + 1;
		else right = mid - 1;
	}
}

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) x[i] = fastin<int>(), y[i] = fastin<int>();
		int c = 0, tot = min(n, 2);
		if (n > 2) {
			for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) p[c++].init(x[i], y[i], x[j], y[j]);
			sort(p, p+c);
			int cc = 1;
			for (int i=0; i+1<c; ++i) {
				if (p[i].oneline(p[i+1])) ++cc;
				else tot = max(tot, f(cc)), cc = 1;
			}
			tot = max(tot, f(cc));
		}
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 260890	2013-09-09 23:26:10	 1292 - Laser Shot	 C++	 0.964	 8776	Accepted
