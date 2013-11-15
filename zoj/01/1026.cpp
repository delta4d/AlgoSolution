#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 1001;

int f[MAXL], g[MAXL], h[MAXL], fg[MAXL<<1];

inline void read(int &n, int f[]) {
	scanf("%d", &n);
	for (int i=--n; i>=0; --i) scanf("%d", f+i);
	//for (int i=n; i>=0; --i) printf("%d ", f[i]); puts("");
}

void mul(const int fn, int f[], const int gn, int g[], int &fgn, int fg[]) {
	int i, j, k;
	for (i=0; i<=fn+gn; fg[i++]=0);
	//printf("fn:%d gn:%d\n", fn, gn);
	for (i=0; i<=fn; ++i) for (j=0; j<=gn; ++j) fg[i+j] += f[i] * g[j];
	for (i=fn+gn; i>=0; --i) fg[i] &= 1;
	for (fgn=fn+gn; fg[fgn]==0; --fgn);
	//for (i=fgn; i>=0; --i) printf("%d ", fg[i]); puts("");
}

void mod(const int fn, int f[], const int gn, int g[]) {
	int i, j, k;
	int start(fn);
	while (start >= gn) {
		for (i=0; i<=gn; ++i) f[start+i-gn] ^= g[i];
		for (i=0; i<start-gn; ++i) f[i] ^= 0;
		for (; f[start]==0; --start);
	}
	printf("%d ", start+1);
	for (i=start; i>=0; --i) printf("%d%s", f[i], i?" ":"\n");
}

int main() {
	int i, j, k;
	int m, n, fn, gn, hn, fgn;
	int tc;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\res.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		read(fn, f);
		read(gn, g);
		read(hn, h);
		mul(fn, f, gn, g, fgn, fg);
		mod(fgn, fg, hn, h);
	}
	return 0;
}