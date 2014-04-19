#include <cstdio>
using namespace std;

typedef long long ll;
ll T, C, N;

ll f(ll T) {
	if (T < 0 || C < T * N) return 0;
	return T * (C - T * N);
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%lld%lld", &N, &C);
		if (N) {
			T = C / (N + N);
			ll f1 = f(T), f2 = f(T+1);
			printf("Case %d: %lld\n", ++cn, f1>=f2?T:T+1);
		}  else {
			printf("Case %d: 0\n", ++cn);
		}
	}
	return 0;
}

// 253255	2013-08-19 16:33:52	 1275 - Internet Service Providers	 C++	 0.000	 1088	Accepted
