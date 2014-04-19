#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("%d %d\n", min(n, 10), n-min(n, 10));
	}
	return 0;
}

// 252014	2013-08-15 19:57:35	 1001 - Opposite Task	 C++	 0.000	 1088	Accepted
