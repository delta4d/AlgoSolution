#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define OK 0
#define PROB 1
#define BROK 2

const int MAXL = 10;
const int MAXN = 11;
const char led[10][MAXL] = {
	"YYYYYYN",
	"NYYNNNN",
	"YYNYYNY",
	"YYYYNNY",
	"NYYNNYY",
	"YNYYNYY",
	"YNYYYYY",
	"YYYNNNN",
	"YYYYYYY",
	"YYYYNYY"	
};

char s[MAXN][MAXL];

bool judge_suc(const int src, const int n) {
	int i, j, k;
	int sta[MAXL];
	for (i=0; i<MAXL; sta[i++]=OK);
	for (i=0; i<n; ++i) {
		for (j=0; j<7; ++j) {
			k = src - i;
			if (led[k][j] == 'N' && s[i][j] == 'Y') return false;
			if (s[i][j] == 'Y' && sta[j] == BROK) return false;
			if (led[k][j] == 'Y' && s[i][j] == 'N') sta[j] = BROK;
		}
	}
	return true;
}

bool gao(const int n) {
	int i, j, k;
	if (n > 10) return false;
	for (i=9; i+1>=n; --i) {
		if (judge_suc(i, n)) return true;
	}
	return false;
}

int main() {
	int i, j, k;
	int m, n;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) scanf("%s", s[i]);
		puts(gao(n)?"MATCH":"MISMATCH");
		scanf("%d", &n);
	}
	return 0;
}