#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	int tc, t, s;
	int p, q;
	int x, y, z;
	int i, j, k;
	int n, m;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		if (n == m + 1) {
			k = 0;
		} else if (n <= m) {
			k = -1;
		} else {
			k = INF;
			t = ((n - m) << 1) - 1;
			for (y=1; y*y<=t; y+=2) {
				if (t % y == 0) {
					s = t / y;
					p = (y + 1) >> 1, q = (s - 1) >> 1;
					if (p + q <= m) {
						k = min(k, m-p-q);
					}
					p = (y - 1) >> 1, q = (s + 1) >> 1;
					if (p + q <= m) {
						k = min(k, m-p-q);
					}
				}
			}
		}
		if (k == INF) puts("-1");
		else printf("%d\n", k);
	}
	return 0;
}