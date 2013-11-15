#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

const char tok[] = " \n";
char s[MAXN];

int gao(char s[]) {
	int i, j, k;
	int ret(0), f(1);
	for (i=0; s[i]; ++i) if (s[i] == '-') {f = -1; break; }
	if (strcmp(s, "x") == 0 || strcmp(s, "-x") == 0 || strcmp(s, "y") == 0 || strcmp(s, "-y") == 0) return f;
	sscanf(s, "%d", &ret);
	return ret;
}

int id(char s[]) {
	for (int i=0; s[i]; ++i) {
		if (s[i] == 'x') return 0;
		if (s[i] == 'y') return 1;
	}
	return 2;
}

void gao(int &x, int &y, int &z) {
	int i, j, k(1), kk(1);
	char *cp;
	bool mm;
	
	x = y = z = 0;
	cp = strtok(s, tok);
	while (cp != NULL) {
		//puts(cp);
		mm = false;
		if (cp[0] != '\0') {
			if (strcmp(cp, "=") == 0) {
				k = -1;
			} else if (strcmp(cp, "-") == 0) {
				mm = true;	
			} else {
				j = id(cp);
				if (j == 0) x += kk * k * gao(cp);
				else if (j == 1) y += kk * k * gao(cp);
				else z += kk * k * gao(cp);
			}
		}
		cp = strtok(NULL, tok);
		if (mm) kk = -1;
		else kk = 1;
	}
	z = -z;
}

inline int gcd(int x, int y) {
	x = x < 0 ? -x : x;
	y = y < 0 ? -y : y;
	if (x < y) swap(x, y);
	int t;
	while (y) t = x % y, x = y, y = t;
	return x;
}

inline void sim(int &x, int &y) {
	int t(gcd(x, y));
	if (t == 0) return;
	x /= t, y /= t;
	if (x > 0 && y < 0 || x < 0 && y > 0) {
		x = x < 0 ? x : -x;
		y = y < 0 ? -y : y;
	} else {
		x = x < 0 ? -x : x;
		y = y < 0 ? -y : y;
	}
}

inline int xmult(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}

void out(int rx, int sx) {
	sim(rx, sx);
	printf("%d", rx); if (sx == 1) puts(""); else printf("/%d\n", sx);
}

void gao(int x1, int y1, int z1, int x2, int y2, int z2) {
	int rx, sx, ry, sy;
	if (x1 == 0 && y1 == 0 && z1 != 0 || x2 == 0 && y2 == 0 && z2 != 0) {
 		puts("don't know"); puts("don't know");
		return;
	}
	bool px1(false), px2(false), py1(false), py2(false);
	bool x(false), y(false);
	if (xmult(x1, y1, x2, y2) == 0) {
		if (x1 != 0 && y1 == 0) px1 = true;
		if (x1 == 0 && y1 != 0) py1 = true;
		if (x2 != 0 && y2 == 0) px2 = true;
		if (x2 == 0 && y2 != 0) py2 = true;
		if (px1) {
			if (px2) {
				if (z1 * x2 == x1 * z2) rx = z1, sx = x1, x = true;	
			} else {
				rx = z1, sx = x1, x = true;
			}
		} else {
			if (px2) {
				rx = z2, sx = x2, x = true;
			}
		}
		if (py1) {
			if (py2) {
				if (z1 * y2 == y1 * z2) ry = z1, sy = y1, y = true;	
			} else {
				ry = z1, sy = y1, y = true;
			}
		} else {
			if (py2) {
				ry = z2, sy = y2, y = true;
			}
		}
		if (!x && !y) {
			puts("don't know"); puts("don't know");
			return;
		}
		if (x && y) {
			out(rx, sx);
			out(ry, sy);
			return;
		}
		if (x) {
			out(rx, sx);
			if (y1 != 0) ry = sx * z1 - x1 * rx, sy = sx * y1;
			else ry = sx * z2 - x2 * rx, sy = sx * y2;
			if (sy == 0) puts("don't know");
			else out(ry, sy);
		} else {
			if (x1 != 0) rx = sy * z1 - y1 * ry, sx = sy * x1;
			else rx = sy * z2 - y2 * ry, sx = sy * x2;
			if (sx == 0) puts("don't know");
			else out(rx, sx);
			out(ry, sy);
		}
	} else {
		rx = xmult(z1, y1, z2, y2), sx = xmult(x1, y1, x2, y2);
		ry = xmult(x1, z1, x2, z2), sy = xmult(x1, y1, x2, y2);
		out(rx, sx);
		out(ry, sy);
	}
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int x1, y1, z1, x2, y2, z2;

	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\A.1.dat", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		gets(s);
		gets(s);
		gao(x1, y1, z1);
		gets(s);
		gao(x2, y2, z2);
		//printf("%d %d %d %d %d %d\n", x1, y1, z1, x2, y2, z2);
		gao(x1, y1, z1, x2, y2, z2);
		if (tc) puts("");
	}
	return 0;
}