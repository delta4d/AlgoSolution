#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int out[5000];
int cnt;
bool f[2][64];

struct node {
	int s, r;
} g[5000];

inline bool cmp(const node &a, const node &b) {
	return a.s < b.s;
}

inline int d(int x) {
	int ret(0);
	while (x) ret += x % 10, x /= 10;
	return ret;
}

int gao(const int n, const int m) {
	int i, j, k(1);
	int s(0), tot(0);
	
	memset(f, true, sizeof(f));
	while (k <= n) {
		for (i=0; i<64; ++i) f[1^s][i] = true;
		for (i=0; i<64&&k+i<=n; ++i) {
			if (f[s][i]) {
				if (tot < m && cnt + 1 == g[tot].s) {
					out[g[tot].r] = k + i;
					for (++tot; tot < m && g[tot].s==g[tot-1].s; ++tot) out[g[tot].r] = k + i;
				}
				++cnt;
			}
			j = d(k + i);
			if (j + i >= 64) f[1^s][(j+i)%64] = false;
			else f[s][j+i] = false;
		}
		k += 64;
		s ^= 1;
	}
	return cnt;
}

int main() {
	int i, j, k;
	int m, n;
	
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (i=0; i<m; ++i) scanf("%d", &g[i].s), g[i].r = i;
	sort(g, g+m, cmp);
	printf("%d\n", gao(n, m));
	for (i=0; i<m; ++i) printf("%d%s", out[i], i==m-1?"\n":" ");

	return 0;
}