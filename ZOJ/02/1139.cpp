#include <cstdio>
using namespace std;

struct rectangle {
	int xmin;
	int xmax;
	int ymin;
	int ymax;
	bool in(const rectangle &a) {
		return xmin >= a.xmin && xmax <= a.xmax && ymin >= a.ymin && ymax <= a.ymax;
	}
};

int main() {
	int n;
	int cnt;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		rectangle *r = new rectangle[n];
		for (i=0; i<n; ++i) scanf("%d %d %d %d", &r[i].xmin, &r[i].xmax, &r[i].ymin, &r[i].ymax);
		cnt = 0;
		for (i=0; i<n; ++i) {
			for (j=0; j<n; ++j) {
				if (i == j) continue;
				if (r[i].in(r[j])) {
					++cnt;
					break;
				}
			}
		}
		delete []r;
		printf("%d\n", cnt);
	}
	return 0;
}
