#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100086;

int x[MAXN];

int gao(int s, int t, const int T) {
	int OFF = s ? x[s-1] : 0;	
	int left = s, right = t, mid, ret = 0;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (x[mid] <= T + OFF) ret = mid - s + 1, left = mid + 1;
		else right = mid - 1;
	}
	return ret;
}

int main() {
	int n, T;
	int mx(0);

	scanf("%d%d", &n, &T);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	for (int i=1; i<n; ++i) x[i] += x[i-1];
	for (int i=0; i<n; ++i) mx = max(mx, gao(i, n-1, T));
	printf("%d\n", mx);

	return 0;
}

// 3265146	 Mar 8, 2013 1:51:00 PM	delta_4d	 279B - Books	 GNU C++	Accepted	 62 ms	 400 KB
