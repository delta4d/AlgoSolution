#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;
const int MAXL = 81;

int n;
char f[MAXN][MAXL], r[MAXN][MAXL];
char buff[300], temp[300];

inline bool gao(const int s, const int k) {
	int i, j;
	for (i=0; f[k][i]&&temp[s+i]; ++i) if (temp[s+i] != f[k][i]) return false;
	return f[k][i] == '\0';
}

inline bool gao(const int k) {
	int i, j;
	int p(0);
	int lr(strlen(r[k])), lf(strlen(f[k]));
	for (i=0; temp[i]; ++i) {
		if (gao(i, k)) {
			for (j=0; j<lr; ++j) buff[p++] = r[k][j];
			i += lf;
			for (; temp[i]; ++i) buff[p++] = temp[i];
			buff[p] = '\0';
			return true;
		} else {
			buff[p++] = temp[i];
		}
	}
	return false;
}

inline void gao() {
	int i, j, k;
	int lf, lr;
	int p;
	for (k=0; k<n; ++k) {
		if (strcmp(f[k], r[k]) == 0) continue;
		while (gao(k)) {
			strcpy(temp, buff);
		}
	}
}

int main() {
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		getchar();
		for (i=0; i<n; ++i) gets(f[i]), gets(r[i]);
		gets(temp);
		gao();
		puts(buff);
		scanf("%d", &n);
	}
	return 0;
}