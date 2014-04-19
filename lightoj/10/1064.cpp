#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 151;

long long f[N][N];

int main() {
	int tc, cn = 0, n, x;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &x);
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i=0; i<n; ++i) for (int j=1; j<=6; ++j) {
			for (int k=0,t=6*i; k<=t; ++k) f[i+1][j+k] += f[i][k];
		}
		for (int i=1; i<N; ++i) f[n][i] += f[n][i-1]; 
		long long B = f[n][N-1], A = B - f[n][x-1], C = __gcd(A, B);
		A /= C, B /= C;
		printf("Case %d: ", ++cn);
		if (A % B == 0) printf("%lld\n", A/B);
		else printf("%lld/%lld\n", A, B);
	}
	return 0;
}

// 290320	2013-11-22 23:07:00	 1064 - Throwing Dice	 C++	 0.004	 1264	Accepted
