#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3fll;

inline LL ABS(const LL x) {return x >= 0 ? x : -x;}

LL gao(LL x, LL y, LL &a, LL &b) {
	LL ret, tt;
	if (ABS(x) >= ABS(y)) {
		 if (y == 0) {
		 	a = 1;
		 	b = 0;
		 	return x;
		 }
		 ret = gao(y, x%y, a, b);
		 tt = b;
		 b = a - (x / y) * b;
		 a = tt;
		 return ret;
	} else {
		if (x == 0) {
		 	b = 1;
		 	a = 0;
		 	return y;
		 }
		 ret = gao(y%x, x, a, b);
		 tt = a;
		 a = b - (y / x) * a;
		 b = tt;
		 return ret;
	}
}

int main() {
	int i, j, k;
	LL a, b, c, d, x1, x2, y1, y2;
	LL x0, y0;
	LL sum;
	LL lx, hx;
	LL ly, hy;
	LL l, h;
	
	//freopen("in.txt", "r", stdin);
	
	scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d", &a, &b, &c, &x1, &x2, &y1, &y2);
	if (a == 0 && b == 0) {
		if (c == 0) sum = (x2 - x1 + 1) * (y2 - y1 + 1);
		else sum = 0;
	} else {
		c = -c;
		d = gao(a, b, x0, y0);
		if (c % d == 0) {
			lx = (x1 - c / d * x0) / (b / d);
			hx = (x2 - c / d * x0) / (b / d);
			if (lx > hx) swap(lx, hx);
			for (k=-3; k<=3; ++k) if (c / d * x0 + b / d * (lx + k) >= x1 && c / d * x0 + b / d * (lx + k) <= x2) break;
			lx += k;
			for (k=3; k>=-3; --k) if (c / d * x0 + b / d * (hx + k) >= x1 && c / d * x0 + b / d * (hx + k) <= x2) break;
			hx += k;
			
			ly = (y1 - c / d * y0) / (-a / d);
			hy = (y2 - c / d * y0) / (-a / d);
			if (ly > hy) swap(ly, hy);
			for (k=-3; k<=3; ++k) if (c / d * y0 - a / d * (ly + k) >= y1 && c / d * y0 - a / d * (ly + k) <= y2) break;
			ly += k;
			for (k=3; k>=-3; --k) if (c / d * y0 - a / d * (hy + k) >= y1 && c / d * y0 - a / d * (hy + k) <= y2) break;
			hy += k;
			
			l = max(lx, ly), h = min(hx, hy);
			sum = max(h - l + 1, 0ll);
		} else {
			sum = 0;
		}
	}
	printf("%I64d\n", sum);
	
	return 0;
}