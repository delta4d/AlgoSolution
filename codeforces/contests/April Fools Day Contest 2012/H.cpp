#include <cstdio>
#include <algorithm>
using namespace std;

void rot(int n, int &x, int &y, int rx, int ry) {
	if (ry == 0) {
		if (rx == 1) {
			x = n - 1 - x;
			y = n - 1 - y;
		}
		swap(x, y);
	}
}

void d2xy(int n, int d, int &x, int &y) {
	int rx, ry, s, t=d;
	x = y = 0;
	for (s=1; s<n; s*=2) {
		rx = 1 & (t/2);
		ry = 1 & (t ^ rx);
		rot(s, x, y, rx, ry);
		x += s * rx;
		y += s * ry;
		t /= 4;
	}
}

int main() {
	int n, d;
	int x, y;

	scanf("%d%d", &n, &d);
	d2xy(1<<n, d, x, y);
	printf("%d %d\n", x, y);

	return 0;
}

// 3419805	 Mar 29, 2013 7:30:25 PM	delta_4d	 H - A polyline	 GNU C++	Accepted	 15 ms	 0 KB
