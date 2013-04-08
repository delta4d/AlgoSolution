#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 1000000009;
const int H = 32;

int f[2][2][H][H][H];
int n, h, tot;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

inline int next(int x) {
	if (x == 0 || x + 1 >= h) return 0;
	return x + 1;	
}

inline bool ok(int hh, int cc) {
	if (hh == 0) return cc < h;
	return true;
}

int main() {
	scanf("%d%d", &n, &h);	
	
	int c = 0, p = 0;

	f[0][1][0][0][0] = 4;
	for (int i=1; i<n; ++i, c=p) {
		p = c ^ 1;
		for (int j=0; j<2; ++j) {
			for (int h1=0; h1<h; ++h1) for (int h2=0; h2<h; ++h2) for (int h3=0; h3<h; ++h3) {
				int cc = f[c][j][h1][h2][h3];
				if (!cc) continue;
				f[c][j][h1][h2][h3] = 0;
				int t1 = next(h1), t2 = next(h2), t3 = next(h3);
				add(f[p][j][t1][t2][t3], cc);
				add(f[p][ok(h1, i)][j][t2][t3], cc);
				add(f[p][ok(h2, i)][t1][j][t3], cc);
				add(f[p][ok(h3, i)][t1][t2][j], cc);
			}
		}
	}
	for (int i=0; i<h; ++i) for (int j=0; j<h; ++j) for (int k=0; k<h; ++k) {
		add(tot, f[p][1][i][j][k]);
		if (i || j || k) add(tot, f[p][0][i][j][k]);
	}

	printf("%d\n", tot);

	return 0;
}

// 3493029	 Apr 8, 2013 4:09:25 PM	delta_4d	 D - Wall Bars	 GNU C++	Accepted	1279 ms	488 KB
