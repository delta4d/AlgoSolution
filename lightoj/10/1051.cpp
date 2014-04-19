#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100;

int v[N];
bool good[N][1<<5], bad[N][1<<5];
char s[N];

inline int t(const char x) {
	if (x == '?') return -1;
	if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') return 1;
	return 0;
}

inline bool valid(int n, int mask) {
	for (int i=0; i<5; ++i) {
		if (i < n && (mask & 1 << i) && v[n-i] == 0) return false;
		if (i < n && !(mask & 1 << i) && v[n-i] == 1) return false;
	}
	return true;
}

inline bool is_bad(int n, int mask) {
	if (n >= 3 && mask % 8 == 7) return true;
	if (n >= 5 && mask % 32 == 0) return true;
	return false;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", s);
		int n = strlen(s);
		for (int i=0; i<n; ++i) v[i+1] = t(s[i]);
		memset(good, false, sizeof(good));
		memset(bad, false, sizeof(bad));
		for (int i=0; i<32; ++i) good[0][i] = true;
		for (int i=1; i<=n; ++i) for (int j=0; j<32; ++j) if (valid(i, j)) {
			int j1 = j >> 1, j2 = j1 | 1 << 4;
			bool cur = is_bad(i, j);
			good[i][j] = (good[i-1][j1] || good[i-1][j2]) && !cur;
			bad[i][j] = bad[i-1][j1] || bad[i-1][j2] || cur;
		}
		printf("Case %d: ", ++cn);
		bool GOOD = false, BAD = false;
		for (int i=0; i<32; ++i) {
//			printf("%d: good=%d, bad=%d\n", i, valid(n,i)&&good[n][i], valid(n,i)&&bad[n][i]);
			GOOD = GOOD || valid(n, i) && good[n][i];
			BAD = BAD || valid(n, i) && bad[n][i];
		}
		if (GOOD && BAD) puts("MIXED");
		else if (GOOD) puts("GOOD");
		else puts("BAD");
	}
	return 0;
}

// 291873	2013-11-26 22:14:08	 1051 - Good or Bad	 C++	 0.004	 1092	Accepted
