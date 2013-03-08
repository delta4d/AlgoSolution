#include <cstdio>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
	int x, y;
	int cx(0), cy(0);
	int tx, ty;
	int k(0), tot(0);
	int cc(1);

	scanf("%d%d", &x, &y);

	while (true) {
		tx = cx + dx[k] * cc, ty = cy + dy[k] * cc;	
		if (dx[k] * (y - cy) == dy[k] * (x - cx) && (tx - x) * (x - cx) >= 0 && (ty - y) * (y - cy) >= 0) break;
		if (k ==1 || k == 3) ++cc;
		++tot;
		cx = tx, cy = ty;
		k = k == 3 ? 0 : k + 1;
	}
	printf("%d\n", tot);

	return 0;
}

// 3265084	 Mar 8, 2013 1:34:08 PM	delta_4d	 279A - The Point on the Spiral	 GNU C++	Accepted	 15 ms	 0 KB
