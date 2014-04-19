#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long llu;

llu p[20], c;

int main() {
	llu tc, cn = 0, x;
	for (scanf("%llu", &tc); tc--; ) {
		scanf("%llu", &x), c = 0;
		for (llu d=0; d<10; ++d) if ((10 * x - d) % 9 == 0) {
			llu y = (10 * x - d) / 9;
			if (y % 10 == d) p[c++] = y;
		}
		sort(p, p+c);
		printf("Case %llu: ", ++cn);
		for (int i=0; i<c; ++i) printf("%llu%s", p[i], i==c-1?"\n":" ");
	}
	return 0;
}

// 251585	2013-08-14 18:15:44	 1163 - Bank Robbery	 C++	 0.000	 1088	Accepted
