#include <cmath>
#include <cstdio>
using namespace std;

int f[50001];

inline void gao(const int &n, const int &m) {
	int k((1+sqrt(1+8.0*m))/2.0);
	int bk(m-k*(k-1)/2);
	int i, j;
	f[n+1] = n + 1;
	for (i=1; i<=n-k; ++i) f[i] = i;
	for (i=n; i>n-k; --i) f[i] = n - i + n - k + 1;
	if (bk != 0) {
		f[n+1] = n - k;
		f[n-k] = n - k + bk;
	}
	for (i=1; i<=n-1; ++i) {
		if (f[i] == n - k + bk && i > n - k) continue;
		printf("%d ", f[i]);
	}
	if (f[n+1] != n + 1) printf("%d %d\n", f[n], f[n+1]);
	else printf("%d\n", f[n]);
}

int main() {
	int n, m;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	while (n != -1 || m != -1) {
		gao(n, m);
		scanf("%d %d", &n, &m);
	}
	return 0;
}
