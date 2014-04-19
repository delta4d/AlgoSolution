#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

char s[20][21];
int f[16][1<<16], d[16][16];
int gx[16], gy[16];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

inline int dis(int a, int b) {
	int x = abs(gx[a] - gx[b]), y = abs(gy[a] - gy[b]);
	return max(x, y);
}

int gao(int g) {
	int all = 1 << (g + 1), ret = INF;
	for (int i=0; i<=g; ++i) fill(f[i], f[i]+all, INF);
	f[g][1<<g] = 0;
	for (int i=0; i<=g; ++i) for (int j=i; j<=g; ++j) d[i][j] = d[j][i] = dis(i, j);
	for (int s=0; s<all; ++s) for (int i=0; i<=g; ++i) if (s & 1 << i) {
		for (int j=0; j<=g; ++j) if (s & 1 << j) {
			f[i][s] = min(f[i][s], f[j][s^(1<<i)]+d[i][j]);
		}
	}
	for (int i=0; i<=g; ++i) ret = min(ret, f[i][all-1]+d[i][g]);
	return ret;
}

int main() {
	int tc, cn = 0, m, n;
	for (tc=fastin<int>(); tc--; ) {
		int x, y, g = 0;
		m = fastin<int>(), n = fastin<int>();
		for (int i=0; i<m; ++i) {
			scanf("%s", s[i]);
			for (int j=0; j<n; ++j) {
				if (s[i][j] == 'g') gx[g] = i, gy[g] = j, s[i][j] = g++;
				else if (s[i][j] == 'x') x = i, y = j;
			}
		}
		gx[g] = x, gy[g] = y;
		printf("Case %d: %d\n", ++cn, gao(g));
	}
	return 0;
}

// 289827	2013-11-22 00:03:49	 1057 - Collecting Gold	 C++	 0.216	 5184	Accepted
