#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50000 + 86;

char s[MAXN], rs[MAXN], p[MAXN], rp[MAXN];
int pre[MAXN], suf[MAXN];
int cnt[MAXN], pi[MAXN];

void gao(char p[], int lp, char s[], int ls, int ret[]) {
	int i, k;
	for (pi[0]=-1,i=1; i<lp; ++i) {
		for (k=pi[i-1],cnt[i]=0; k>=0&&p[k+1]!=p[i]; k=pi[k]);
		pi[i] = p[k+1] == p[i] ? k + 1 : -1;
	}
	for (cnt[0]=1,i=1; i<lp; ++i) cnt[i] = pi[i] >= 0 ? cnt[pi[i]] + 1 : 1;
	for (k=-1,i=0; i<ls; ++i) {
		for (; k>=0&&p[k+1]!=s[i]; k=pi[k]);
		if (p[k+1] == s[i]) ++k;
		if (k == lp - 1) k = pi[k];
		ret[i] = k >= 0 ? cnt[k] : 0;
	}
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s", s, p);
		int ls = strlen(s), lp = strlen(p);
		for (int i=0; i<ls; ++i) rs[i] = s[ls-1-i];
		for (int i=0; i<lp; ++i) rp[i] = p[lp-1-i];
		gao(p, lp, s, ls, pre);
		gao(rp, lp, rs, ls, suf);
		for (int i=0; i+i<ls; ++i) swap(suf[i], suf[ls-1-i]);
		long long tot = 0;
		for (int i=0; i+1<ls; ++i) tot += 1ll * pre[i] * suf[i+1];
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 319139	2014-01-31 19:58:58	 1334 - Genes in DNA	 C++	 0.036	 2064	Accepted
