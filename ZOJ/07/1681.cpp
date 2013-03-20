#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 151200;

int f1[100], f2[100];

inline int cubic(const int x) {
	return x * x * x;
}

inline int tetrahedral(const int x) {
	return x * (x + 1) * (x + 2) / 6;
}

inline void gen() {
	int i, j, k;
	for (i=0; i<100; ++i) {
		f1[i] = cubic(i);
		f2[i] = tetrahedral(i);
	}
}

int main() {
	int i, j, k;
	int m, n;
	gen();
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		m = -INF;
		for (i=0; i<100; ++i) {
			if (f1[i] > n) break;
			for (j=0; j<100; ++j) {
				if (f1[i] + f2[j] > n) break;
					m = max(f1[i]+f2[j], m);
			}
		}
		printf("%d\n", m);
	}
	return 0;
}