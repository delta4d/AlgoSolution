/*
ID: delta 4d
PROG: transform
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 11;
char s1[MAXN][MAXN], s2[MAXN][MAXN], s[MAXN][MAXN];

inline bool gao1(const int n, char s1[][MAXN], char s2[][MAXN]) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) {
			if (s1[i][j] != s2[j][n-1-i]) return false;
		}
	}
	return true;
}

inline bool gao2(const int n, char s1[][MAXN], char s2[][MAXN]) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) {
			if (s1[i][j] != s2[n-1-i][n-1-j]) return false;
		}
	}
	return true;
}

inline bool gao3(const int n, char s1[][MAXN], char s2[][MAXN]) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) {
			if (s1[i][j] != s2[n-1-j][i]) return false;
		}
	}
	return true;
}

inline bool gao4(const int n, char s1[][MAXN], char s2[][MAXN]) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) {
			if (s1[i][j] != s2[i][n-1-j]) return false;
		}
	}
	return true;
}

inline bool gao5(const int n, char s1[][MAXN], char s2[][MAXN]) {
	int i, j, k;
	for (i=0; i<n; ++i) for (j=0; j<n; ++j) s[i][j] = s1[i][n-1-j];
	if (gao1(n, s, s2)) return true;
	if (gao2(n, s, s2)) return true;
	if (gao3(n, s, s2)) return true;
	return false;
}

inline bool gao6(const int n, char s1[][MAXN], char s2[][MAXN]) {
	int i, j, k;
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) {
			if (s1[i][j] != s2[i][j]) return false;
		}
	}
	return true;
}

inline int gao(const int n) {
	if (gao1(n, s1, s2)) return 1;
	if (gao2(n, s1, s2)) return 2;
	if (gao3(n, s1, s2)) return 3;
	if (gao4(n, s1, s2)) return 4;
	if (gao5(n, s1, s2)) return 5;
	if (gao6(n, s1, s2)) return 6;
	return 7;
}

int main() {
	int i, j, k;
	int m, n;
	//freopen("f:\\in.txt", "r", stdin);
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) scanf("%s", s1[i]);
		for (i=0; i<n; ++i) scanf("%s", s2[i]);
		printf("%d\n", gao(n));
	}
	return 0;
}