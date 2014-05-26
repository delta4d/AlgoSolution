#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int m, n, x, y, z, p, mm, nn;
	scanf("%d%d%d%d%d%d", &m, &n, &x, &y, &z, &p);
	x &= 3, y &= 1, z &= 3;
	mm = m, nn = n;
	auto cw = [&](int &a, int &b) {int t=a;a=b,b=m+1-t;swap(m, n);};
	auto hr = [&](int &a, int &b) {b=n+1-b;};
	auto ccw = [&](int &a, int &b) {cw(a,b);cw(a,b);cw(a,b);};
	for (int xx,yy; p--; ) {
		m = mm, n = nn;
		scanf("%d%d", &xx, &yy);
		for (int i=0; i<x; ++i) cw(xx, yy);
		for (int i=0; i<y; ++i) hr(xx, yy);
		for (int i=0; i<z; ++i) ccw(xx, yy);
		printf("%d %d\n", xx, yy);
	}
	return 0;
}

// 6561542	 May 6, 2014 2:16:38 PM	delta_4d	 C - Inna and Huge Candy Matrix	 GNU C++0x	Accepted	 93 ms	 0 KB
