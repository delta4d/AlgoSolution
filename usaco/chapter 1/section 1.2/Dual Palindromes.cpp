/*
ID: delta 4d
PROG: dualpal
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

inline bool gao(const int base, int x) {
	int i, j, k(0);
	int buff[32];
	do {
		buff[k] = x % base;
		x /= base;
		++k;
	} while (x != 0);
	for (i=0; i<k; ++i) if (buff[i] != buff[k-1-i]) return false;
	return true;
}

int main() {
	int i, j, k;
	int s, n;
	int base;
	int cnt;
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	while (scanf("%d %d", &n, &s) != EOF) {
		k = 0;
		for (i=s+1; k<n; ++i) {
			cnt = 0;
			for (base=2; base<=10; ++base) {
				if (gao(base, i)) ++cnt;
				if (cnt > 1) break;
			}
			if (cnt > 1) {
				++k;
				printf("%d\n", i);
			}
		}
	}
	return 0;
}