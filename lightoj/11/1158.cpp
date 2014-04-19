#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[1<<10][1001];
int r[11], fac[11];
int n, d;
char s[11];

int gao(int mask, int rem) {
	if (f[mask][rem] != -1) return f[mask][rem];
	int k = s[__builtin_popcount(mask) - 1] - '0';
	f[mask][rem] = 0;
	for (int i=0; i<n; ++i) if (mask & 1 << i) {
		int next_mask = mask ^ (1 << i);
		int next_rem = (rem - r[i] * k) % d;
		if (next_rem < 0) next_rem += d;
		f[mask][rem] += gao(next_mask, next_rem);
	}
	return f[mask][rem];
}

int main() {
	fac[0] = 1;
	for (int i=1; i<11; ++i) fac[i] = fac[i-1] * i;
	int tc, cn = 0, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%d", s, &d);
		n = strlen(s), m = 1 << n;
		r[0] = 1;
		for (int i=1; i<11; ++i) r[i] = r[i-1] * 10 % d;
		memset(f, -1, sizeof(f));
		f[0][0] = 1;
		int tot = gao(m-1, 0);
		int c[10] = {0};
		for (int i=0; i<n; ++i) ++c[s[i]-'0'];
		for (int i=0; i<10; ++i) tot /= fac[c[i]];
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 293017	2013-11-29 23:34:09	 1158 - Anagram Division	 C++	 1.728	 5092	Accepted
