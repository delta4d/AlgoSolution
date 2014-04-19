#include <cstdio>
using namespace std;

int main() {
	int tc, cn = 0, N, M, K; double P;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d%lf", &N, &M, &K, &P);
		double S = N * P * K;
		printf("Case %d: %.10lf\n", ++cn, S);
	}
	return 0;
}

// 255138	2013-08-24 16:01:42	 1317 - Throwing Balls into the Baskets	 C++	 0.000	 1088	Accepted
