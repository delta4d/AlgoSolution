#include <cstdio>
#include <memory>
using namespace std;

#define NOT_COLORED 0
const int MAXN = 202;
int graph[MAXN][MAXN];
inline void deal(int &x, int &y) {
	if (x > y) x ^= y ^= x ^= y;
	x += 100; y += 100;
}

int main() {
	int n, c;
	int cc;
	int xmin, xmax, ymin, ymax;
	int i, j, k;
	int area;
	int dn(0);
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &n, &c);
	while (n != 0) {
		area = 0;
		memset(graph, NOT_COLORED, sizeof(graph));
		for (k=0; k<n; ++k) {
			scanf("%d %d %d %d %d", &cc, &xmin, &ymin, &xmax, &ymax);
			deal(xmin, xmax);
			deal(ymin, ymax);
			for (i=xmin; i<xmax; ++i) {
				for (j=ymin; j<ymax; ++j) {
					if (cc == c && graph[i][j] != c) ++area;
					else if (cc != c && graph[i][j] == c) --area;
					graph[i][j] = cc;
				}
			}
		}
		printf("The area of color %d in dataset %d is: %d\n", c, ++dn, area);
		scanf("%d %d", &n, &c);
	}
	return 0;
}
