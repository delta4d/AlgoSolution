#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;

char s[MAXN], p[MAXN];
int pi[MAXN];

int kmp(char p[], int lp, char s[], int ls) {
	int i, k, cnt(0);
	for (pi[0]=-1,i=1; i<lp; ++i) {
		for (k=pi[i-1]; k>=0&&p[k+1]!=p[i]; k=pi[k]);
		pi[i] = p[k + 1] == p[i] ? k + 1 : -1;
	}
	for (k=-1,i=0; i<ls; ++i) {
		for (; k>=0&&p[k+1]!=s[i]; k=pi[k]);
		if (p[k+1] == s[i]) ++k;
		if (k == lp - 1) ++cnt, k = pi[k];
	}
	return cnt;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s", s, p);
		printf("Case %d: %d\n", ++cn, kmp(p, strlen(p), s, strlen(s)));
	}
	return 0;
}

// 319062	2014-01-31 13:34:46	 1255 - Substring Frequency	 C++	 0.080	 6948	Accepted
