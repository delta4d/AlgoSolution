#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int f[1<<24], p[1<<24];
int x[24], y[24];
int d[24], a[24][24];
int sx, sy;
int n, t;

int main() {
	scanf("%d%d", &sx, &sy);
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d%d", x+i, y+i);
		d[i] = (sx - x[i]) * (sx - x[i]) + (sy - y[i]) * (sy - y[i]);
	}
	for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
		a[i][j] = a[j][i] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	}
	int m = 1 << n;
	fill(f, f+m, INF); f[0] = 0;
	for (int k=0; k<m; ++k) if (f[k] < INF) {
		for (int i=0; i<n; ++i) if (!(1 << i & k)) {
			for (int j=i; j<n; ++j) if (!(1 << j & k)) {
				int cc = d[i] + d[j] + a[i][j], kk = k | 1 << i | 1 << j;	
				if (f[k] + cc < f[kk]) f[kk] = f[k] + cc, p[kk] = k;
			}
			break;
		}
	}
	printf("%d\n", f[m-1]);
	for (int i=m-1; i; i=p[i]) {
		printf("0 ");		
		int j = p[i];
		for (int k=0; k<n; ++k) if ((i >> k & 1) && !(j >> k & 1)) printf("%d ", k+1);
	}
	puts("0");

	return 0;
}

// 3612207	 Apr 23, 2013 7:40:54 PM	delta_4d	 8C - Looking for Order	 GNU C++	Accepted	 125 ms	 131300 KB
