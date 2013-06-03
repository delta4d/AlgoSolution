#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 500000 + 86;

int f[MAXN], g[MAXN];

int gao(int f[], int x, const int t, const int k) {
	if (f[x] != -1) return f[x];
	if (x == t) return f[x] = 0;
	int ret = gao(f, x-1, t, k);
	for (int i=2; i<=k; ++i) if (x % i && x / i * i >= t) ret = min(ret, gao(f, x/i*i, t, k));
	return f[x] = ret + 1;
}

int main() {
	ios_base::sync_with_stdio(false);

	LL a, b, k;
	cin >> a >> b >> k;

	LL t = 1;
	for (LL i=2; i<=k; ++i) t = t * i / __gcd(t, i);
	memset(f, -1, sizeof(f)); memset(g, -1, sizeof(g));
	gao(f, t, 0, k); gao(g, t, b%t, k);

	LL tot = 0;
	LL pa = a / t, pb = (b + t - 1) / t;
	if (pa < pb) tot = g[a%t?a%t:t];
	else tot = (pb * t == b ? 0 : g[t]) + max(0ll, pa - pb) * f[t] + (pa * t == a ? 0 : f[a%t]);
	cout << tot << endl;

	return 0;
}

// 3818339	 Jun 3, 2013 2:32:20 PM	delta_4d	 C - Number Transformation	 GNU C++	Accepted	203 ms	26428 KB
