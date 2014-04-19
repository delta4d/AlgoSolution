#include <map>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

map <string, int> mp;

struct date {
	ll y, m, d;
	
	date(ll _y=0, ll _m=0, ll _d=0):y(_y), m(_m), d(_d) {}
	void init() { y = m = d = 0; }
	void set(ll _y=0, ll _m=0, ll _d=0) { y = _y, m = _m, d = _d; }
	bool leap() { return y % 400 == 0 || y % 100 != 0 && y % 4 == 0; }
	void readin() {
		char mon[20];
		scanf("%s %lld, %lld", mon, &d, &y);
		m = mp[mon];
	}
	bool operator<(const date &a) const {
		if (y != a.y) return y < a.y;
		if (m != a.m) return m < a.m;
		return d < a.d;
	}
	bool before_leap() {
		if (!leap()) return false;
		return m < 2 || m == 2 && d < 29;
	}
	bool after_leap() {
		if (!leap()) return false;
		return m > 2;
	}
};

void init() {
	mp["January"] = 1;
	mp["February"] = 2;
	mp["March"] = 3;
	mp["April"] = 4;
	mp["May"] = 5;
	mp["June"] = 6;
	mp["July"] = 7;
	mp["August"] = 8;
	mp["September"] = 9;
	mp["October"] = 10;
	mp["November"] = 11;
	mp["December"] = 12;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		date a, b;
		a.readin(); b.readin();
		if (b < a) swap(a, b);
		ll tot = 0, y = b.y - a.y + 1;
		tot = y / 400 * 97;
		a.y += y / 400 * 400;
		date cc = a;
		for (; cc.y<=b.y; ++cc.y) tot += cc.leap();
		if (a.after_leap()) --tot;
		if (b.before_leap()) --tot;
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 255737	2013-08-25 16:56:59	 1414 - February 29	 C++	 0.000	 1248	Accepted
