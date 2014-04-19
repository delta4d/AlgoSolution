#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[111];

int gao(char s1[], int n1, char s2[], int n2) {
	if (n1 == 0 || n2 == 0) return n1 + n2;
	int f[2][111]={0}, cur = 0, nxt = 1;
	for (int i=0; i<n1; ++i) {
		nxt = cur ^ 1;
		for (int j=0; j<n2; ++j) {
			if (*(s1 + i) == *(s2 - j)) {
				f[cur][j] = (i > 0 && j > 0) * f[nxt][j-1] + 1;
			} else {
				if (i) f[cur][j] = max(f[cur][j], f[nxt][j]);
				if (j) f[cur][j] = max(f[cur][j], f[cur][j-1]);
			}
		}
		cur = nxt;
		fill(f[cur], f[cur]+n2, 0);
	}
	return n1 + n2 - 2 * f[cur^1][n2-1];
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", s);
		int n = strlen(s), mn = n - 1;
		for (int i=0; i<n; ++i) {
			mn = min(mn, gao(s, i, s+n-1, n-i));
			mn = min(mn, gao(s, i, s+n-1, n-i-1));
			if (!mn) break;
		}
		printf("Case %d: %d\n", ++cn, mn);
	}
	return 0;
}

// 289732	2013-11-21 20:30:26	 1033 - Generating Palindromes	 C++	 0.108	 1088	Accepted
