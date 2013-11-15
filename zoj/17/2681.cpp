#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

inline void sim(int &a, int &b) {
	int x(max(a, b)), y(a+b-x);
	int t;
	while (y != 0) {
		t = x % y;
		x = y;
		y = t;
	}
	a /= x, b /= x;
}

int main() {
	int i, j, k;
	int tc;
	int dx, dy;
	int x, y;
	int we, ns;
	int xc, xn, yc, yn;
	int p;
	vector<char> res;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &dy, &dx);
		sim(dy, dx);
		res.clear();
		x = y = 0;
		xc = xn = 0;
		yc = yn = 0;
		we = ns = 0;
		if ((dy&1)&&(dx&1)) p = 3;
		else if (!(dy&1)&&(dx&1)) p = 2;
		else if ((dy&1)&&!(dx&1)) p = 4;
		else p = 1;
		if (dy == dx) {
			printf("0\n3\n");
		} else if (dy < dx) {
			for (x=1; x<dx; ++x) {
				yc = x * dy / dx;
				yn = (x - 1) * dy / dx;
				if (yc != yn) {
					res.push_back(ns?'S':'N');
					ns ^= 1;
				}
				res.push_back(we?'W':'E');
				we ^= 1;
			}
			printf("%d\n", res.size());
			for (i=0; i!=res.size(); ++i) printf("%c ", res[i]);
			printf("%d\n", p);
		} else if (dy > dx) {
			for (y=1; y<dy; ++y) {
				xc = y * dx / dy;
				xn = (y - 1) * dx / dy;
				if (xc != xn) {
					res.push_back(we?'W':'E');
					we ^= 1;
				}
				res.push_back(ns?'S':'N');
				ns ^= 1;
			}
			printf("%d\n", res.size());
			for (i=0; i!=res.size(); ++i) printf("%c ", res[i]);
			printf("%d\n", p);
		}
	}
	return 0;
}