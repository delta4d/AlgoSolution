#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

int a[MAXN];

int main() {
	int n, d;

	scanf("%d%d", &n, &d);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	long long tot = 0;
	for (int i=0; i<n; ++i) {
		int j = upper_bound(a, a+n, a[i]+d) - a - 1;
		if (j > i) tot += (long long)(j - i - 1) * (j - i) / 2;
	}
	printf("%I64d\n", tot);

	return 0;
}

// 3817799	 Jun 3, 2013 10:36:20 AM	delta_4d#	 A - Points on Line	 GNU C++	Accepted	 46 ms	 400 KB
