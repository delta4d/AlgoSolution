#include <cstdio>
using namespace std;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("Case %d: %s\n", ++cn, __builtin_popcount(n)%2==0?"even":"odd");
	}
	return 0;
}

// 252024	2013-08-15 20:34:07	 1182 - Parity	 C++	 0.000	 1088	Accepted
