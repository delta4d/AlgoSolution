#include <cstdio>
using namespace std;

typedef long long LL;

bool isp(const int x) {
	if (x <= 1) return false;
	for (int i=2; i*i<=x; ++i) if (x % i == 0) return false;
	return true;
}

int pow(int x, int e, const int MOD) {
	int r = 1;
	for (; e; e>>=1, x=(LL)x*x%MOD) if (e & 1) r = (LL)r * x % MOD;
	return r;
}

bool isr(int n, int p) {
	for (int i=2,q=p-1; i*i<=q; ++i) if (q % i == 0) {
		if (pow(n, i, p) == 1 || pow(n, q/i, p) == 1) return false;
	}	
	return true;
}

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	if (!isp(n+1)) return puts("-1"), 0;
	for (--x; x>1; --x) if (isr(x, n+1)) return printf("%d\n", x), 0;
	return puts("-1"), 0;
}

// 3720493	 May 14, 2013 6:21:09 PM	delta_4d	 D - Rotatable Number	 GNU C++	Accepted	15 ms	0 KB
