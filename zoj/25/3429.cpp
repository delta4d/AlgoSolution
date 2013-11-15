#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int xx, yy, zz;
int fx[MAXN], fy[MAXN], fz[MAXN];
int gx[MAXN], gy[MAXN], gz[MAXN];
char op[16];

inline void FILL(const int x, const int y, const int z) {
	for (int i=0; i<x; ++i) fx[i] = gx[i] = i;
	for (int i=0; i<y; ++i) fy[i] = gy[i] = i;
	for (int i=0; i<z; ++i) fz[i] = gz[i] = i;
}

inline void FIND(int a) {
	int x0, y0, z0;
	if (a > xx * yy * zz || a <= 0) return;
	--a;
	x0 = a / (yy * zz);
	a -= x0 * yy * zz;
	y0 = a / zz;
	z0 = a - y0 * zz;
	printf("%d %d %d\n", gx[x0], gy[y0], gz[z0]);
}

inline void QUERY(int x, int y, int z) {
	printf("%d\n", yy*zz*fx[x]+zz*fy[y]+fz[z]+1);
}

int main() {
	int i, j, k;
	int x, y, z;
	int s, t;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", op) != EOF) {
		if (op[3] == 'L') {
			scanf("%d %d %d", &xx, &yy, &zz);
			puts("START");
			FILL(xx, yy, zz);
		} else if (op[2] == 'N') {
			scanf("%d", &k);
			FIND(k);
		} else if (op[0] == 'Q') {
			scanf("%d %d %d", &x, &y, &z);
			QUERY(x, y, z);
		} else if (op[4] == '1') {
			scanf("%d %d", &s, &t);
			gx[fx[s]] = t, gx[fx[t]] = s;
			swap(fx[s], fx[t]);
		} else if (op[4] == '2') {
			scanf("%d %d", &s, &t);
			gy[fy[s]] = t, gy[fy[t]] = s;
			swap(fy[s], fy[t]);
		} else if (op[4] == '3') {
			scanf("%d %d", &s, &t);
			gz[fz[s]] = t, gz[fz[t]] = s;
			swap(fz[s], fz[t]);
		}
	}
	return 0;
}