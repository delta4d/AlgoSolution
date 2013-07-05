#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1001;
const int prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int f[MAXN];

inline int gao(int n) {
	int x, y, z;
	int m;
	int res(INF);
	for (x=1; x*x*x<=n; ++x) {
		if (n % x == 0) {
			m = n / x;
			for (y=x; y*y<=m; ++y) {
				if (m % y == 0) {
					z = m / y;
					res = min(res, (x*y+y*z+z*x)<<1);
				}
			}
		}
	}
	return res;
}

inline void gao() {
	int n;
	for (n=1; n<MAXN; ++n) {
		f[n] = gao(n);
	}
}

int main() {
	int i, j, k;
	int n, x;
	//freopen("f:\\in.txt", "r", stdin);
	gao();
	scanf("%d", &n);
	for (i=0; i<n; ++i) {
		scanf("%d", &x);
		printf("%d\n", f[x]);
	}
	return 0;
}