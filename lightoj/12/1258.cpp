#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;

char s[MAXN], p[MAXN];
int pi[MAXN];

int gao(char p[], int lp, char s[], int ls) {
	int i, k;
	for (pi[0]=-1,i=1; i<lp; ++i) {
		for (k=pi[i-1]; k>=0&&p[k+1]!=p[i]; k=pi[k]);
		pi[i] = p[k+1] == p[i] ? k + 1 : -1;
	}
	for (k=-1,i=0; i<lp; ++i) {
		for (; k>=0&&p[k+1]!=s[i]; k=pi[k]);
		if (p[k+1] == s[i]) ++k;
		if (k == lp - 1) {
			if (i == lp - 1) break;
			k = pi[k];
		}
	}
	return (lp << 1) - k - 1;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", s);
		int ls = strlen(s);
		for (int i=0; i<ls; ++i) p[i] = s[ls-1-i];
		printf("Case %d: %d\n", ++cn, gao(p, ls, s, ls));
	}
	return 0;
}

// 319077	2014-01-31 14:38:37	 1258 - Making Huge Palindromes	 C++	 0.168	 6948	Accepted
