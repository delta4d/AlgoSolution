#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 86;
const int INF = 0x3f3f3f3f;

int f[MAXN];

int main() {
	int n, m, d;

	scanf("%d%d%d", &n, &m, &d);	
	n *= m;
	for (int i=1; i<=n; ++i) scanf("%d", f+i);
	sort(f+1, f+n+1);
	for (int i=2; i<=n; ++i) {
		if ((f[i] - f[1]) % d) {
			puts("-1");
			return 0;
		}
		f[i] = (f[i] - f[1]) / d;
	}
	f[1] = 0;
	for (int i=1; i<=n; ++i) f[i] += f[i-1];
	int mn = INF;
	for (int k=1; k<=n; ++k) {
		mn = min(mn, (2*k-n)*(f[k]-f[k-1])+f[n]-2*f[k]);
	}
	printf("%d\n", mn);

	return 0;
}

// 3467201	 Apr 3, 2013 9:54:37 AM	delta_4d	 289B - Polo the Penguin and Matrix	 GNU C++	Accepted	15 ms	0 KB
