#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

int x[MAXN];
bool v[MAXN];
int n, k;

int in(int t) {
	if (t % k) return -1;
	t /= k;
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (x[mid] == t) return mid;
		if (x[mid] <= t) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int main() {
	int tot = 0;

	scanf("%d%d", &n, &k);
	if (k == 1) { printf("%d\n", n); return 0; }
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	sort(x, x+n);
	for (int i=n-1; i>=0; --i) if (!v[i]) {
		v[i] = true;
		int cc = 1;
		for (int j=i,p=-1; p=in(x[j]),p!=-1; v[j=p]=true,++cc);
		tot += (cc + 1) >> 1;
	}
	printf("%d\n", tot);

	return 0;
}

// 3323963	 Mar 16, 2013 10:12:44 AM	delta_4d	 274A - k-Multiple Free Set	 GNU C++	Accepted	62 ms	500 KB
