#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;
const int MAXL = 32;

char buff[MAXL];
char word1[MAXN][MAXL], word2[MAXN][MAXL];
char out[MAXN][MAXL];
int f[MAXN][MAXN], b[MAXN][MAXN];

void trace_back(int i, int j, int rem) {
	if (rem == 0 || i == 0 || j == 0) return;
	if (b[i][j] == 1) {
		strcpy(out[rem-1], word1[i-1]);
		trace_back(i-1, j-1, rem-1);
	} else if (b[i][j] == 2) {
		trace_back(i-1, j, rem);
	} else if (b[i][j] == 3) {
		trace_back(i, j-1, rem);
	}
}

int main() {
	int i, j, k;
	int l1, l2;
	//freopen("f:\\in.txt", "r", stdin);
	while (true) {	
		if (scanf("%s", word1[0]) == EOF) break;
		l1 = l2 = 0;
		while (word1[l1][0] != '#') {
			scanf("%s", word1[++l1]);
		}
		scanf("%s", word2[0]);
		while (word2[l2][0] != '#') {
			scanf("%s", word2[++l2]);
		}
		//--l1, --l2;
		for (i=0; i<=l1; ++i) f[i][0] = 0;
		for (i=0; i<=l2; ++i) f[0][i] = 0;
		for (i=1; i<=l1; ++i) {
			for (j=1; j<=l2; ++j) {
				if (strcmp(word1[i-1], word2[j-1]) == 0) f[i][j] = f[i-1][j-1] + 1, b[i][j] = 1;
				else if (f[i-1][j] > f[i][j-1]) f[i][j] = f[i-1][j], b[i][j] = 2;
				else f[i][j] = f[i][j-1], b[i][j] = 3;
			}
		}
		//printf("%d\n", f[l1][l2]);
		trace_back(l1, l2, f[l1][l2]);
		for (i=0; i<f[l1][l2]; ++i) printf("%s%s", i?" ":"", out[i]);
		puts("");
	}
	return 0;
}