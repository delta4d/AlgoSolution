#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

int a[MAXN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	sort(a, a+n);
	int mn = 0x3f3f3f3f;
	for (int i=0; i<n; ++i) {
		int k = upper_bound(a, a+n, 2*a[i]) - a;
		mn = min(mn, i+n-k);
	}
	printf("%d\n", mn);

	return 0;
}

// 3823632	 Jun 5, 2013 8:50:11 AM	delta_4d	 B - Physics Practical	 GNU C++	Accepted	 46 ms	 500 KB
