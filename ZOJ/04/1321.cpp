#include <cstdio>
#include <algorithm>
using namespace std;

int res;

inline int dis(const int x1, const int y1, const int x2, const int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void gao(int dx, int dy, int x1, int y1, int x2, int y2, int z2, int x, int y, int z) {
	if (z2 == 0) {
		res = min(res, dis(x1, y1, x2, y2));
		return;
	}
	if (-1 <= dx && dx <= 0) gao(dx - 1, dy, x1 + z, y1, z - z2, y2, x2, z, y, x);
	if (-0 <= dx && dx <= 1) gao(dx + 1, dy, x1 - x, y1, z2, y2, x - x2, z, y, x);
	if (-1 <= dy && dy <= 0) gao(dx, dy - 1, x1, y1 + z, x2, z - z2, y2, x, z, y);
	if (-0 <= dy && dy <= 1) gao(dx, dy + 1, x1, y1 - y, x2, z2, y - y2, x, z, y);
}

int main() {
	int x, y, z;
	int x1, y1, z1;
	int x2, y2, z2;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d %d %d %d %d %d %d %d", &x, &y, &z, &x1, &y1, &z1, &x2, &y2, &z2) != EOF) {
		if (z1 != 0 && z1 != z) {
			if (x1 == 0 || x1 == x) {
				swap(x, z);
				swap(x1, z1);
				swap(x2, z2);
			} else {
				swap(y, z);
				swap(y1, z1);
				swap(y2, z2);			
			}
		}
		if (z1 != 0) {
			z1 = z - z1;
			z2 = z - z2;
		}
		res = 0x7fffffff;
		gao(0, 0, x1, y1, x2, y2, z2, x, y, z);
		printf("%d\n", res);
	}
	return 0;
}