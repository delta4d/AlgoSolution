#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL INF = 5000000;

struct fraction {
	LL z;
	LL m;
	
	fraction(LL _z=0, LL _m=1):z(_z), m(_m) {}
	bool input() {
		return scanf("%lld %lld", &z, &m) == 2;
	}
	void output() {
		printf("%lld/%lld\n", z, m);
	}
	void set_inf() {
		z = INF;
		m = 1;
	}
	void sett(const LL _z, const LL _m) {
		z = _z, m = _m;
	}
	void sim() {
		LL t;
		LL x(max(z, m)), y(min(z, m));
		if (x == 0 || y == 0) return;
		do {
			t = x % y;
			x = y;
			y = t;
		} while (y != 0);
		z /= x, m /= x;
	}
	void sub(const fraction &a, fraction &r) {
		r.m = m * a.m;
		r.z = z * a.m - m * a.z;
		if (r.z < 0) r.z *= -1;
		r.sim();
	}
	bool lower(const fraction &a) {
		return z * a.m < m * a.z;
	}
};

int main() {
	LL i, j, k;
	LL z, m;
	LL rz, rm;
	fraction r, c, cerr, err, out;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	r.input();
	while (true) {
		err.set_inf();
		for (m=1; m<=r.m; ++m) {
			out.set_inf();
			z = r.z * m / r.m;
			for (i=1; i>=-1; --i) {
				c.sett(z+i, m);
				c.sub(r, cerr);
				if (cerr.lower(err)) {
					err = cerr;
					out = c;
				}
			}
			if (out.z != INF) out.output();
		}
		if (!r.input()) break;
		puts("");
	}
	return 0;
}