#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 128;

int x[MAXN];

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	int mx = 0;
	for (int i=0; i<n; ++i) {
		for (int j=i; j<n; ++j) {
			int cc = 0;
			for (int k=0; k<n; ++k) {
				if (i <= k && k <= j) {
					if (x[k] == 0) ++cc;
				} else {
					if (x[k] == 1) ++cc;
				}
			}
			mx = max(mx, cc);
		}
	}
	printf("%d\n", mx);

	return 0;
}

// 4011312	 Jul 4, 2013 4:33:23 PM	* delta_4d	 A - Flipping Game	 GNU C++	Accepted	 15 ms	 0 KB
