#include <cstdio>
using namespace std;

int f(int n, int x) {
	int t = 0;
	for (; n; t+=n/=x);
	return t;
}

int main() {
	int tc, cn = 0, n, r, p, q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d%d", &n, &r, &p, &q);
		int c2 = f(n, 2) - f(r, 2) - f(n-r, 2);
		int c5 = f(n, 5) - f(r, 5) - f(n-r, 5);
		for (; p%2==0; p/=2,c2+=q);
		for (; p%5==0; p/=5,c5+=q);
		int c = c2 < c5 ? c2 : c5;
		printf("Case %d: %d\n", ++cn, c);
	}
	return 0;
}

// 249492	2013-08-09 10:11:34	 1090 - Trailing Zeroes (II)	 C++	 0.016	 1088	Accepted
