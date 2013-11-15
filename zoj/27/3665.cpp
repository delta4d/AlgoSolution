#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
	LL n;

	while (1 == scanf("%lld", &n)) {
		LL k, r, kk=n-1, rr=1;
		for (r=2; r<=40; ++r) {
			k = pow(n, 1.0/r);
			LL sum = 0, cc = 1;
			for (int i=0; i<r; ++i) cc *= k, sum += cc;
			if (sum == n || sum == n - 1) {
				if (r * k < rr * kk) rr = r, kk = k;
			}
		}
		printf("%lld %lld\n", rr, kk);
	}

	return 0;
}
