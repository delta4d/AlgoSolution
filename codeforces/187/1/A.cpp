#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 200000 + 86;

LL a[MAXN], d[MAXN], T[MAXN];

int main() {
	ios_base::sync_with_stdio(false);

	LL n, k;
	cin >> n >> k;
	for (int i=1; i<=n; ++i) cin >> a[i];
	for (LL i=1,j=0; i<=n; ++i) {
		d[i] = j - (i - 1) * (n - i) * a[i];
		j += (i - 1) * a[i];
		T[i] = T[i-1] + a[i];
	}
	LL ST = 0, SA = 0, t = 0, p = -1;
	for (LL i=1,j; i<=n; ++i) {
		j = p == -1 ? 0 : t * (T[i-1] - T[p]);
		if (d[i] - ST + t * (n - i) * a[i] - SA - j < k) {
			cout << i << endl;
			if (p != -1) ST += t * (T[i-1] - T[p]);
			SA += (i - 1) * a[i];
			++t, p = i;
		}
	}

	return 0;
}

// 3845277	 Jun 8, 2013 8:45:17 AM	delta_4d	 A - Sereja and Contest	 GNU C++	Accepted	281 ms	
