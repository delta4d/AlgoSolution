#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct fraction {
	int x, y;

	fraction(int x=0, int y=1):x(x), y(y) {}
	void sim() {
		int d = __gcd(x, y);
		x /= d, y /= d;
	}
	bool operator<(const fraction &a) const {
		return x * a.y < y * a.x;
	}
	bool operator<=(const fraction &a) const {
		return x * a.y <= y * a.x;
	}
	bool operator==(const fraction &a) const {
		return x * a.y == y * a.x;
	}
	bool operator>(const fraction &a) const {
		return x * a.y > y * a.x;
	}
	bool operator>=(const fraction &a) const {
		return x * a.y >= y * a.x;
	}
	fraction operator+(const fraction &a) {
		fraction ret(x * a.y + y * a.x, y * a.y);
		ret.sim();
		return ret;
	}
	fraction operator-(const fraction &a) {
		fraction ret(x * a.y - y * a.x, y * a.y);
		ret.sim();
		return ret;
	}
	fraction operator*(const fraction &a) {
		fraction ret(x * a.x, y * a.y);
		ret.sim();
		return ret;
	}
	fraction operator/(const fraction &a) {
		fraction ret(x * a.y, a.x * y);
		ret.sim();
		return ret;
	}
};

struct timer {
	int h, m, s;

	void read() {
		scanf("%d:%d:%d", &h, &m, &s);
	}
	fraction to_h() {
		int t = (h * 60 + m) * 60 + s;
		fraction ret(t, 120);
		ret.sim();
		return ret;
	}
	fraction to_s() {
		int t = (h * 60 + m) * 60 + s;
		return fraction(t);
	}
	void to_clock_time(const fraction &a) {
		int x = a.x, y = a.y, z = x / y;
		x %= y;
		int h = z / 3600, m = (z - h * 3600) / 60, s = z % 60;
		if (x) printf("%02d:%02d:%02d %d/%d\n", h, m, s, x, y);
		else printf("%02d:%02d:%02d\n", h, m, s);
	}
} T;

int main() {
	int tc, cn = 0;
	fraction t, t1, t2, d360(360), d2(2), d(120, 13);
	for (scanf("%d", &tc); tc--; ) {
		T.read(); t = T.to_h();
		T.read(); t1 = T.to_s();
		T.read(); t2 = T.to_s();
		vector <fraction> out;
		for (int n=-1; n<=12; ++n) {
			fraction dn(n);
			fraction x = d * (d2 * t + d360 * dn);
			if (t1 <= x && x <= t2) out.push_back(x);
		}
		sort(out.begin(), out.end());
		out.erase(unique(out.begin(), out.end()), out.end());
		printf("Case %d: %d\n", ++cn, (int)out.size());
		for (int i=0; i<(int)out.size(); ++i) T.to_clock_time(out[i]);
	}
	return 0;
}

// 317812	2014-01-27 23:52:56	 1430 - A Question of Time	 C++	 0.260	 1216	Accepted
