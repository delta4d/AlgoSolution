#include <cstdio>
using namespace std;

int gao(int x, int e, const int MOD) {
	int ret = 1;
	while (e) {
		if (e & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		e >>= 1;
	}
	return ret;
}

int main() {
	int p, k=0;
	
	scanf("%d", &p);

	for (int i=1,j=0; i<p; ++i) {
		for (j=1; j<p-1; ++j) if (gao(i, j, p) == 1) break;
		k += j == p - 1;
	}
	printf("%d\n", k);

	return 0;
}

// 3359406	 Mar 20, 2013 9:31:06 AM	delta_4d	 284A - Cows and Primitive Roots	 GNU C++	Accepted	421 ms	0 KB
