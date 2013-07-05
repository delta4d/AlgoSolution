#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 2000000 + 86;

bool v[MAXN];
vector <int> p;
int a, b, k, l = -1;

void init() {
	for (int i=2; i<MAXN; ++i) if (!v[i]) {
		p.push_back(i);
		for (int j=i<<1; j<MAXN; j+=i) v[j] = true;
	}
}

bool ok(int m) {
	for (int x=a; x<=b-m+1; ++x) {
		int s = lower_bound(p.begin(), p.end(), x) - p.begin();
		int t = upper_bound(p.begin(), p.end(), x+m-1) - p.begin();
		if (t - s < k) return false;
	}
	return true;
}

int main() {
	init();

	scanf("%d%d%d", &a, &b, &k);
	int left = 1, right = b - a + 1, mid;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (ok(mid)) l = mid, right = mid - 1;
		else left = mid + 1;
	}
	printf("%d\n", l);

	return 0;
}

// 4002888	 Jul 2, 2013 3:54:28 PM	delta_4d	 C - Primes on Interval	 GNU C++	Accepted	 1281 ms	 4000 KB
