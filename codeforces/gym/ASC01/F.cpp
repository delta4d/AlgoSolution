#include <bits/stdc++.h>
using namespace std;

int const N = 310;
double const eps = 1e-6;
char const R[][5] = {"YES", "NO"};

struct edge {
	int x, y;
	double w;
};

double x[N], y[N], r[N], d[N];
vector <edge> e;

inline int sgn(double x) {
//	return x <= -eps ? -1 : (x >= eps ? 1 : 0);
	return x >= 0 ? 1 : -1;
}

inline double xmult(int i, int j) {
	return x[i] * y[j] - x[j] * y[i];
}

inline double dmult(int i, int j) {
	return x[i] * x[j] + y[i] * y[j];
}

inline double dis(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

bool cycle(int n) {
	for (int t=0; t<n; ++t) for (auto &c: e) {
		if (d[c.x] + c.w + eps <= d[c.y]) {
			d[c.y] = d[c.x] + c.w;
			if (t == n - 1) return true;
		}
	}
	return false;
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("out.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i=0; i<=n; ++i) scanf("%lf%lf%lf", x+i, y+i, r+i);
	for (int i=0; i<n; ++i) x[i] -= x[n], y[i] -= y[n], r[i] += r[n];
	x[n] = y[n] = 0;
	for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
		if (dis(i, j) + eps <= r[i] + r[j]) {
			double x = xmult(i, j), delta = acos(dmult(i,j)/dis(i,n)/dis(j,n));
			e.push_back((edge){i, j, sgn(x)*delta});
			e.push_back((edge){j, i, -sgn(x)*delta});
		}
	}
	puts(R[cycle(n)]);
	return 0;
}

// 6964180	 2014-06-26 18:41:12	delta_4d	 F - Get Out!	 GNU C++0x	Accepted	62 ms	268 KB
