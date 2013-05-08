#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

int x[MAXN];

int main() {
	int n, m;
	int c, t;
	int v;

	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) scanf("%d%d", &c, &t), x[i] = x[i-1] + c * t;
	while (m--) {
		scanf("%d", &v);
		printf("%d\n", lower_bound(x+1, x+n+1, v) - x);
	}

	return 0;
}

// 3684795	 May 6, 2013 10:14:35 AM	delta_4d	 B - Eugeny and Play List	 GNU C++	Accepted	109 ms	368 KB
