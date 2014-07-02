#include <bits/stdc++.h>
using namespace std;

int const N = 1 << 10;

pair<int,int> f[N];
int w[N];

int main() {
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, y, tot = 0;
	scanf("%d%d%d", &n, &m, &y);
	for (int i=0,x; i<n; ++i) {
		scanf("%d", &x);
		int k = x * m / y;
		int r = (k + 1) * y - m * x, l = m * x - k * y;
		f[i] = {r-l, i};
		tot += k, w[i] = k;
	}
	sort(f, f+n);
	for (int i=0; i+tot<m; ++i) ++w[f[i].second];
	for (int i=0; i<n; ++i) printf("%d ", w[i]);
	return 0;
}

// 6970952	 2014-06-27 20:48:26	delta_4d	 G - Robbers	 GNU C++0x	Accepted	62 ms	192 KB
