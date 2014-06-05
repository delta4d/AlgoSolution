#include <cstdio>
#include <algorithm>
using namespace std;

int const N = 1 << 10;

int v[N];

int main() {
	int n, m, tot = 0;
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) scanf("%d", v+i);
	for (int i=0,a,b; i<m; ++i) {
		scanf("%d%d", &a, &b), --a, --b;
		tot += min(v[a], v[b]);
	}
	printf("%d\n", tot);
	return 0;
}

// 6766989	 2014-06-01 17:16:32	delta_4d	 A - The Child and Toy	 GNU C++0x	Accepted	 31 ms	 0 KB
