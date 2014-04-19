#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long f[1<<16][20];
int r[20][20][21], v[20];
char s[20];
int base, K, n, m;

void init() {
	for (int i=2; i<=16; ++i) for (int k=1; k<=20; ++k) {
		r[i][0][k] = 1;
		for (int j=1; j<16; ++j) r[i][j][k] = r[i][j-1][k] * i % k;
	}
}

long long gao(int mask, int rem) {
	if (f[mask][rem] >= 0) return f[mask][rem];
	f[mask][rem] = 0;
	int x = v[__builtin_popcount(mask) - 1];
	for (int i=0; i<n; ++i) if (mask & 1 << i) {
		int next_mask = mask ^ (1 << i), next_rem = (rem - x * r[base][i][K]) % K;
		if (next_rem < 0) next_rem += K;
		f[mask][rem] += gao(next_mask, next_rem);
	}
	return f[mask][rem];
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%s", &base, &K, s);
		n = strlen(s), m = 1 << n;
		for (int i=0; i<n; ++i) v[i] = s[i] <= '9' ? s[i] - '0' : s[i] - 'A' + 10;
		memset(f, -1, sizeof(f));
		f[0][0] = 1;
		printf("Case %d: %lld\n", ++cn, gao(m-1, 0));
	}
	return 0;
}

// 291669	2013-11-26 15:24:18	 1021 - Painful Bases	 C++	 0.376	 11360	Accepted
