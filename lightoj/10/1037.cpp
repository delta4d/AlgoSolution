#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 15;

int f[1<<N], mx[1<<N][N], hp[N];
char d[N][N+1];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", hp+i);
		for (int i=0; i<n; ++i) scanf("%s", d[i]);
		int m = 1 << n;
		memset(mx, 0, sizeof(mx));
		for (int k=1; k<m; ++k) for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) if (k & 1 << j) {
				mx[k][i] = max(mx[k][i], d[j][i]-'0');
			}
		}
		for (int k=1; k<m; ++k) {
			f[k] = INF;
			for (int i=0; i<n; ++i) if (k & 1 << i) {
				int dm = max(1, mx[k^1<<i][i]);
				f[k] = min(f[k], f[k^1<<i] + (hp[i] + dm - 1) / dm);
			}
		}
		printf("Case %d: %d\n", ++cn, f[m-1]);
	}
	return 0;
}

// 290979	2013-11-24 20:22:39	 1037 - Agent 47	 C++	 0.176	 3136	Accepted
