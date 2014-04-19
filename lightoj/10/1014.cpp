#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long p[1000000], c;

int main() {
	long long T, L, P, cn = 0;
	for (scanf("%lld", &T); T--; ) {
		scanf("%lld%lld", &P, &L);
		c = 0, P -= L;
		for (long long Q=1; Q*Q<=P; ++Q) if (P % Q == 0) {
			if (Q > L) p[c++] = Q;
			if (P / Q <= L) break;
			if (Q * Q != P) p[c++] = P / Q;
		}
		sort(p, p+c);
		printf("Case %lld: ", ++cn);
		if (c == 0) puts("impossible");
		else for (int i=0; i<c; ++i) printf("%lld%s", p[i], i==c-1?"\n":" ");
	}
	return 0;
}

// 249384	2013-08-08 22:32:46	 1014 - Ifter Party	 C++	 0.060	 8900	Accepted 
