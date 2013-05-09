#include <cstdio>
using namespace std;

const int MAXN = 128;

int x[MAXN];

int main() {
	int m, n;
	int a, b;

	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", x+i);
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		x[a-1] += b - 1;
		x[a+1] += x[a] - b;
		x[a] = 0;
	}
	for (int i=1; i<=n; ++i) printf("%d\n", x[i]);

	return 0;
}

// 3496596	 Apr 9, 2013 5:16:18 PM	delta_4d	 294A - Shaass and Oskols	 GNU C++	Accepted	15 ms	0 KB
