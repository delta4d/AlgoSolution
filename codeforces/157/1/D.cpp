#include <cstdio>
using namespace std;

const int MAXN = 1024;

double p[MAXN][MAXN];
int a[MAXN];

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) {
		scanf("%d", a+i);
		for (int j=0; j<i; ++j) p[i][j] = a[i] > a[j], p[j][i] = 1 - p[i][j];
	}
	for (int x,y; m--; ) {
		scanf("%d%d", &x, &y), --x, --y;
		for (int i=0; i<n; ++i) if (i != x && i != y) {
			p[i][x] = p[i][y] = (p[i][x] + p[i][y]) / 2;
			p[x][i] = p[y][i] = 1 - p[i][x];
		}
		p[x][y] = (p[x][y] + p[y][x]) / 2, p[y][x] = 1 - p[x][y];
	}
	double e = 0;
	for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) e += p[i][j];
	printf("%.16lf\n", e);

	return 0;
}

// 3769498	 May 25, 2013 7:27:11 PM	delta_4d	 D - Little Elephant and Broken Sorting	 GNU C++	Accepted	93 ms	
