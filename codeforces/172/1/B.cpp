#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

int st[MAXN], p;

int main() {
	int n, x;
	int mx = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &x);
		while (p > 0) {
			int c = st[p-1];
			mx = max(mx, c ^ x);
			if (c > x) break;
			--p;
		}
		st[p++] = x;
	}
	printf("%d\n", mx);

	return 0;
}

// 3426735	 Mar 31, 2013 2:22:13 PM	delta_4d	 280B - Maximum Xor Secondary	 GNU C++	Accepted	46 ms	400 KB
