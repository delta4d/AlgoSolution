/*
ID: delta 4d
PROG: friday
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 400;
int cnt[MAXN][7];
int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int leap(int x) {
	x += 1900;
	return (x % 400 == 0) || (x % 100 != 0 && x % 4 == 0);
}

inline int gao(const int k) {
	return (k + 6) % 7 == 0 ? 7 : (k + 6) % 7;
}

inline void gen() {
	int i, j, k(0);
	int off;
	//printf("%d\n\n", leap(2));
	//freopen("f:\\out.txt", "w", stdout);
	cnt[0][0] = 1;
	//printf("%d ", gao(k));
	for (i=1; i<12; ++i) {
		k += day[i-1];
		k %= 7;
		//printf("%d ", gao(k));
		++cnt[0][k];
	}
	//puts("");
	//for (i=0; i<7; ++i) printf("%d ", cnt[0][i]);
	for (i=1; i<MAXN; ++i) {
		for (j=0; j<7; ++j) cnt[i][j] = cnt[i-1][j];
		k += day[11];
		k %= 7;
		//printf("%d ", gao(k));
		++cnt[i][k];
		off = leap(i);
		for (j=1; j<12; ++j) {
			k += day[j-1] + (j == 2 ? off : 0);
			k %= 7;
			//printf("%d ", gao(k));
			++cnt[i][k];
		}
		//puts("");
	}
}

int main() {
	int i, j, k;
	int m, n;
	gen();
	//freopen("f:\\in.txt", "r", stdin);
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<6; ++i) printf("%d ", cnt[n-1][i]);
		printf("%d\n", cnt[n-1][i]);
	}
	return 0;
}