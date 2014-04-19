#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

char s[111];
int f[111][2];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%s", &n, s);
		memset(f, 0, sizeof(f));
		f[0][1] = 1;
		if (s[0] == '.') f[0][0] = INF;
		for (int i=1; i<n; ++i) {
			if (s[i] == '#') {
				f[i][0] = min(f[i-1][0], f[i-1][1]);
			} else {
				f[i][0] = f[i-1][1];
			}
			f[i][1] = (i >= 2) * min(f[i-2][0], f[i-2][1]) + 1;
		}
		printf("Case %d: %d\n", ++cn, min(f[n-1][0], f[n-1][1]));
	}
	return 0;
}

// 277372	2013-10-23 19:30:26	 1389 - Scarecrow	 C++	 0.000	 1088	Accepted
