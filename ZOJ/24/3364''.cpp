#include <cstdio>
using namespace std;
//typedef long long int;

inline int calc(int x1, int x2, int y) {
	int t1, t2;
	if (y % 2 == 0) return (x2 - x1) * y;
	if (y >= 0) {
		if (x2 >= 0) t2 = x2 / 2;
		else t2 = (x2 - 1) / 2;
		if (x1 >= 0) t1 = x1 / 1;
		else t1 = (x1 - 1) / 2;
		return (x2 - x1) * (y - 1) / 2 + t2 - t1;
	}
	if (x2 >= 0) t2 = (x2 + 1) / 2;
	else t2 = x2 / 2;
	if (x1 >= 0) t1 = (x1 + 1) / 2;
	else t1 = x1 / 2;
	return (x2 - x1) * (y - 1) / 2 + t2 - t1;
}

int main() {
	int x0, y0, x1, y1, x2, y2;
	int i, j, k;
	int n;
	int b;
	int w;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		b = w = 0;
		scanf("%d %d", &x0, &y0);
		x1 = x0; y1 = y0;
		for (i=1; i<n; ++i) {
			scanf("%d %d", &x2, &y2);
			if (y2 == y1) {
				b += (x2 - x1) * y1;
				w += calc(x1, x2, y1);
			}
			x1 = x2;
			y1 = y2;
		}
		x2 = x0; y2 = y0;
		if (y2 == y1) {
			b += (x2 - x1) * y1;
			w += calc(x1, x2, y1);
		}
		b = b < 0 ? -b : b;
		w = w < 0 ? -w : w;
		printf("%d %d\n", b, w);
	}

	return 0;
}
