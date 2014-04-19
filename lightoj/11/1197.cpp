#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 100;

bool v[MAXN];
long long p[MAXN/10], c;

void init() {
	for (long long i=2; i<MAXN; ++i) if (!v[i]) {
		p[c++] = i;
		for (long long j=i*i; j<MAXN; j+=i) v[j] = true;
	}
}

int main() {
	init();
	long long tc, cn = 0, a, b;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld", &a, &b);
		memset(v, false, sizeof(v));
		for (long long i=0; p[i]*p[i]<=b; ++i) {
			long long d = max((a+p[i]-1)/p[i], 2ll);
			for (long long j=d*p[i]; j<=b; j+=p[i]) v[j-a] = true;
		}
		long long c = 0;
		for (long long i=a; i<=b; ++i) if (i > 1 && !v[i-a]) ++c;
		printf("Case %lld: %lld\n", ++cn, c);
	}
	return 0;
}

// 249550	2013-08-09 11:16:42	 1197 - Help Hanzo	 C++	 0.112	 2844	Accepted
