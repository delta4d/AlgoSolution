#include <cstdio>
#include <vector>
using namespace std;

vector <int> x, y;

int main() {
	int n, xx, yy;
	int sx = 0, sy = 0;
	int a, b;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d%d", &xx, &yy);
		x.push_back(xx); sx += xx;
		y.push_back(yy); sy += yy;
	}
	a = (sx - 500 + 1000 - 1) / 1000, b = (sx + 500) / 1000;
	if (b >= a) {
		for (int i=0; i<b; ++i) printf("G");
		for (int i=b; i<n; ++i) printf("A");
		puts("");
	} else {
		puts("-1");
	}

	return 0;
}

// 3317116	 Mar 14, 2013 7:58:55 PM	delta_4d	 282B - Painting Eggs	 GNU C++	Accepted	500 ms	10300 KB
