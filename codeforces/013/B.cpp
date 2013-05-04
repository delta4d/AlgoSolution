#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	long long x, y;
	point(long long _x=0, long long _y=0):x(_x), y(_y) {}
	void read() { cin >> x >> y; }
	void out() { cout << x << ' ' << y << endl; }
	point operator-(const point &a) { return point(x-a.x, y-a.y); }
	bool operator==(const point &a) { return x == a.x && y == a.y; }
	bool operator!=(const point &a) { return !(*this == a); }
	long long operator*(const point &a) { return x * a.x + y * a.y; }
	long long operator^(const point &a) { return x * a.y - y * a.x; }
	long long sqr() { return x * x + y * y; }
};

struct segment {
	point a, b;
	segment() {}
	segment(point _a, point _b):a(_a), b(_b) {}
	void read() { a.read(); b.read(); }
	void out() { a.out(); b.out(); }
	segment swap() { return segment(b, a); }
} t[3];

bool acute(point &a, point &b, point &c) {
	return (b - a) * (c - a) >= 0 && ((b - a) ^ (c - a));	
}

double dis2(point &a, point &b) {
	return (a - b).sqr();
}

bool on(point &a, segment &s) {
	return !((s.a - a) ^ (a - s.b)) && (s.a.x - a.x) * (s.b.x - a.x) <= 0;
}

bool ok(segment a, segment b, segment c) {
	if (a.a != b.a && a.a != b.b && a.b != b.a && a.b != b.b) return false;
	if (a.a == b.b || a.b == b.b) b = b.swap();
	if (a.b == b.a || a.b == b.b) a = a.swap();
	if (!acute(a.a, a.b, b.b)) return false;
	if (on(c.a, a) && on(c.b, b)) {}
	else if (on(c.a, b) && on(c.b, a)) c = c.swap();
	else return false;
	long long x1 = dis2(a.a, c.a), y1 = dis2(a.b, c.a), x2 = dis2(b.a, c.b), y2 = dis2(b.b, c.b);
	if (x1 > y1) swap(x1, y1); if (x2 > y2) swap(x2, y2);
	return x1 * 16 >= y1 && x2 * 16 >= y2;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		for (int i=0; i<3; ++i) t[i].read();
		bool A = false;
		for (int i=0; i<3; ++i) {
			int j = i == 2 ? 0 : i + 1, k = j == 2 ? 0 : j + 1;
			if (ok(t[i], t[j], t[k])) { A = true; break; }
		}
		printf("%s\n", A?"YES":"NO");
	}
	return 0;
}

// 3664626	 May 3, 2013 4:31:35 PM	delta_4d	 B - Letter A	 MS C++	Accepted	 171 ms	 0 KB
