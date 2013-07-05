#include <cstdio>
#include <algorithm>
using namespace std;

#define C(x) max(0, (x) * ((x) - 1) / 2)
#define F(x) (x + ((x) >= v))

int main() {
	int n, m, v;

	scanf("%d%d%d", &n, &m, &v);
	int x = 1, mx = C(x) + C(n-1-x) + n - 1;
	if (m > mx || m < n - 1) return puts("-1"), 0;
	for (int i=1; i<x; ++i,--m) printf("%d %d\n", F(i), F(i+1));
	if (0 < x && x < n) {
		printf("%d %d\n", F(x), v);
		--m;
	}
	if (0 < x + 1 && x + 1 < n) {
		printf("%d %d\n", v, F(x+1));
		--m;
	}
	for (int i=x+1; i+1<n; ++i,--m) printf("%d %d\n", F(i), F(i+1));
	for (int i=1; i<=x; ++i) for (int j=i+2; j<=x; ++j) {
		if (!m) return 0;
		printf("%d %d\n", F(i), F(j));
		--m;
	}
	for (int i=x+1; i<n; ++i) for (int j=i+2; j<n; ++j) {
		if (!m) return 0;
		printf("%d %d\n", F(i), F(j));
		--m;
	}
	for (int i=1; i<x; ++i) {
		if (!m) return 0;
		printf("%d %d\n", F(i), v);
		--m;
	}
	for (int i=x+2; i<n; ++i) {
		if (!m) return 0;
		printf("%d %d\n", v, F(i));
		--m;
	}

	return 0;
}

// 4026073	 Jul 5, 2013 1:31:47 PM	delta_4d	 C - System Administrator	 GNU C++0x	Accepted	 78 ms	 0 KB
