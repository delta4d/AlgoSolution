#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10000000 + 86;

int d[MAXN], p[MAXN], np;
long long f[MAXN];

void init() {
	for (int i=2; i<MAXN; ++i) {
		if (!d[i]) d[i] = i, p[np++] = i;
		for (int j=0; i*p[j]<MAXN&&j<np; ++j) {
			d[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
}

bool ok(long long mid, const int n) {
	for (int i=0; i<n; ++i) {
		long long x = mid, y = 0;
		for (; x; y+=x/=p[i]);
		if (y < f[i]) return false;
	}
	return true;
}

int main() {
	init();

	int n, x, mx = 0;
	long long left = 1, right = 0, mid;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", &x), ++f[x], mx = max(mx, x), right += x;
	for (int i=mx; i>1; --i) f[i-1] += f[i];
	for (int i=mx; i>1; --i) f[i / d[i]] += f[i], (i != d[i]) && (f[d[i]] += f[i]);
	for (int i=0; i<np; ++i) f[i] = f[p[i]];
	for (x=np-1; !f[x]; --x); ++x;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (ok(mid, x)) right = mid - 1;
		else left = mid + 1;
	}
	printf("%I64d\n", right + 1);

	return 0;
}

// 3650817	 Apr 29, 2013 2:14:26 PM	delta_4d	 E - Empire Strikes Back	 GNU C++	Accepted	1234 ms	156532 KB
