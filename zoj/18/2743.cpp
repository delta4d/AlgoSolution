#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;
const int oddx[] = {0, -1, -1, 0, 1, 1};
const int oddy[] = {-1, 0, 1, 1, 1, 0};
const int evenx[] = {0, -1, -1, 0, 1, 1};
const int eveny[] = {-1, -1, 0, 1, 0, -1};

char f[MAXN][MAXN];
int w, h;
int tot;

inline bool in(int x, int y) {
	if (x & 1) return x >= 0 && x < h && y >= 0 && y < w - 1;
	return x >= 0 && x < h && y >= 0 && y < w;
}

void explode(int x, int y, const char tt) {
	int i, j, k;
	int tx, ty;
	for (i=0; i<6; ++i) {
		if (x & 1) {
			tx = x + oddx[i], ty = y + oddy[i];
			if (in(tx, ty) && f[tx][ty] == tt) {
				++tot;
				f[tx][ty] = 'E';
				explode(tx, ty, tt);
			}
		} else {
			tx = x + evenx[i], ty = y + eveny[i];
			if (in(tx, ty) && f[tx][ty] == tt) {
				++tot;
				f[tx][ty] = 'E';
				explode(tx, ty, tt);
			}
		}
	}
}

void floodfill(int x, int y) {
	int i, j, k;
	int tx, ty;
	for (i=0; i<6; ++i) {
		if (x & 1) {
			tx = x + oddx[i], ty = y + oddy[i];
			if (in(tx, ty) && f[tx][ty] != 'E') {
				++tot;
				f[tx][ty] = 'E';
				floodfill(tx, ty);
			}
		} else {
			tx = x + evenx[i], ty = y + eveny[i];
			if (in(tx, ty) && f[tx][ty] != 'E') {
				++tot;
				f[tx][ty] = 'E';
				floodfill(tx, ty);
			}
		}
	}
}

int check() {
	int i, j, k;
	int res(0);
	int cnt(0);
	char tt;
	for (int i=0; i<h; ++i) {
		for (j=0; f[i][j]; ++j) {
			res += (f[i][j] != 'E');
		}
	}
	for (i=0; f[0][i]; ++i) {
		if (f[0][i] != 'E') {
			tot = 1;
			f[0][i] = 'E';
			floodfill(0, i);
			cnt += tot;
		}
	}
	return res - cnt;
}

int main() {
	int i, j, k;
	int x, y;
	int cnt;
	char tt;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d %d %d", &h, &w, &x, &y) == 4) {
		for (i=0; i<h; ++i) scanf("%s", f[i]);
		tot = 1;
		tt = f[--x][--y];
		f[x][y] = 'E';
		explode(x, y, tt);
		if (tot >= 3) {
			cnt = tot;
			printf("%d\n", cnt+check());
		} else {
			puts("0");
		}
	}
	return 0;
}