#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;

int f[MAXN][MAXN];
int b[MAXN][MAXN];
int out1[MAXN], out2[MAXN];
char s1[MAXN], s2[MAXN];

void trace_back(int i, int j, int p) {
	if (i == 0 || j == 0) return;
	if (b[i][j] == 1) {
		out1[p] = i - 1, out2[p] = j - 1;
		trace_back(i-1, j-1, p-1);
	} else if (b[i][j] == 2) {
		trace_back(i-1, j, p);
	} else {
		trace_back(i, j-1, p);
	}
}

void process() {
	int i, j, k;
	int len;
	int l1(strlen(s1)), l2(strlen(s2));
	for (i=0; i<=l1; ++i) f[i][0] = 0;
	for (i=0; i<=l2; ++i) f[0][i] = 0;
	for (i=1; i<=l1; ++i) {
		for (j=1; j<=l2; ++j) {
			if (s1[i-1] == s2[j-1]) f[i][j] = f[i-1][j-1] + 1, b[i][j] = 1;
			else if (f[i-1][j] > f[i][j-1]) f[i][j] = f[i-1][j], b[i][j] = 2;
			else f[i][j] = f[i][j-1], b[i][j] = 3;
		}
	}
	/*freopen("f:\\out.txt", "w", stdout);
	for (i=0; i<=l1; ++i) {
		for (j=0; j<=l2; ++j) printf("%d ", f[i][j]);
		puts("");
	}*/
	len = f[l1][l2];
	out1[0] = out2[0] = -1;
	trace_back(l1, l2, len);
	out1[len+1] = l1, out2[len+1] = l2;
	++len;
	for (i=0; i<len; ++i) {
		for (k=out1[i]+1; k<out1[i+1]; ++k) printf("%c", s1[k]);
		for (k=out2[i]+1; k<out2[i+1]; ++k) printf("%c", s2[k]);
		if (i < len - 1) printf("%c", s1[out1[i+1]]);
	}
	puts("");
}

int main() {
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (scanf("%s %s", s1, s2) == 2) process();
	return 0;
}