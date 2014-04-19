#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const ll N = 1 << 10;

char s[N];
int f[N][N];

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		scanf("%s", s+1);
		int n = strlen(s+1);
		for (ll i=0; i<n; ++i) for (ll j=0; j<=i; ++j) {
			if (s[i+1] == 'E') {
				add(f[i+1][j], f[i][j]);
			} else if (s[i+1] == 'D') {
				add(f[i+1][j], j*f[i][j]%MOD);
				if (j) add(f[i+1][j-1], (j*j%MOD)*f[i][j]%MOD);
			} else {
				add(f[i+1][j+1], f[i][j]);
				add(f[i+1][j], j*f[i][j]%MOD);
			}
		}
		printf("Case %d: %d\n", ++cn, f[n][0]);
	}
	return 0;
}

// 274941	2013-10-17 23:22:43	 1299 - Fantasy Cricket	 C++	 0.752	 5184	Accepted
