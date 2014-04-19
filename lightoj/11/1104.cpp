#include <cmath>
#include <cstdio>
using namespace std;

const int N = 100000 + 86;

double f[N], L[N];

void init() {
	for (int i=1; i<N; ++i) f[i] = f[i-1] + (L[i] = log(i));
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		int left = 1, right = n, mid = -1, res = 2;
		while (left <= right) {
			mid = (left + right) >> 1;
			double fx = f[n-mid] + mid * L[n] - f[n] - L[2];
			if (fx > 0) right = mid - 1, res = mid;
			else left = mid + 1;
		}
		--res;
		printf("Case %d: %d\n", ++cn, res);
	}
	return 0;
}

// 254639	2013-08-23 02:12:47	 1104 - Birthday Paradox	 C++	 0.032	 2748	Accepted
