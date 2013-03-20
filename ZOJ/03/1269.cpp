#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 16;

LL pp[MAXN];

void gen() {
	int i, j, k;
	for (i=1; i<MAXN; ++i) {
		pp[i] = 1;
		for (j=0; j<i; ++j) pp[i] *= i;
	}	
}

int main() {
	LL i, j, k;
	LL m, n;
	LL tot, t;
	gen();
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%lld", &tot)	;
	while (tot != -1) {
		for (n=MAXN-1; n>=2; --n) {
			t = tot + n - 1;
			if (n & 1) {
				if (t % pp[n] == 0) break;
			} else {
				if (t % (pp[n] * (n - 1)) == 0) break;
			}
		}
		if (n >= 2) printf("%lld coconuts, %lld people and 1 monkey\n", tot, n);
		else printf("%lld coconuts, no solution\n", tot);
		scanf("%lld", &tot);	
	}
	return 0;
}