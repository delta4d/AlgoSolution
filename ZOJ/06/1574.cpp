#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100001;

struct node {
	int x[3];
	void print() {
		printf("%d %d %d\n", x[0], x[1], x[2]);
	}
} f[MAXN];

inline int gcd(int x, int y) {
	int t;
	if (x < y) t = x, x = y, y = t;
	do {
		t = x % y;
		x = y;
		y = t;
	} while (y != 0);
	return x;
}

inline void gao() {
	int i, j, k;
	int s, t;
	int a, b;
	int temp;
	int n(1);
	for (i=3; n<MAXN; ++i) {
		if (i % 2 == 1) {
			k = sqrt(i);
			for (a=k; a>=1; --a) {
				if (i % a == 0) {
					b = i / a;
					if ((a - b) % 2 == 0) {
						s = (a + b) >> 1;
						t = (b - a) >> 1;
						if (s == 0 || t == 0) continue;
						if ((s - t) % 2 == 0) continue;
						if (gcd(s, t) != 1) continue;
						j = s * (t << 1);
						if (j > i && gcd(j, i) == 1) {
							f[n].x[0] = i;
							f[n].x[1] = j;
							f[n].x[2] = s * s + t * t;
							++n;
						}
					}
				}
			}
		} else {
			temp = i >> 1;
			k = sqrt(temp);
			for (t=k; t>=1; --t) {
				if (temp % t == 0) {
					s = temp / t;
					if (s == 0 || t == 0) continue;
					if ((s - t) % 2 == 0) continue;
					if (gcd(s, t) != 1) continue;
					j = s * s - t * t;
					if (j > i && gcd(j, i) == 1) {
						f[n].x[0] = i;
						f[n].x[1] = j;
						f[n].x[2] = s * s + t * t;
						++n;
					}
				}
			}
		}
	}
}

int main() {
	int n;
	gao();
	while (scanf("%d", &n) != EOF) f[n].print();
	return 0;
}