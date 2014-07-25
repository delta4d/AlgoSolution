#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[101], g[101];

int main() {
	int i, j, k;
	int m, n;
	bool change;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &k) == 2) {
		for (i=0; i<n; ++i) scanf("%d", f+i);
		f[n] = 0x3f3f3f3f;
		sort(f, f+n);
		m = 0;
		while (true) {
			change = false;
			//for (i=0; i<n; ++i) printf("%d ", f[i]); puts("");
			for (i=0; i<=n; ++i) g[i] = f[i];
			for (i=1; i<=n; ++i) {
				if (f[i] != f[i-1] && f[i-1] < k) {
					change = true;
					++g[i-1];
				}
			}
			++m;
			if (!change) break;
			for (i=0; i<=n; ++i) f[i] = g[i];
			sort(f, f+n);
		}
		printf("%d\n", m-1);
	}
	return 0;
}

// 310927	2011-02-28 19:37:20	delta_4d	B - Settlers' Training	GNU C++	Accepted	30 ms	1300 KB
