#include <bits/stdc++.h>
using namespace std;

int a[200];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	int mx = a[0];
	for (int l=0; l<n; ++l) {
		for (int r=l; r<n; ++r) {
			int sum = 0;
			vector <int> cur, rem;
			for (int i=0; i<n; ++i) {
				if (i < l || i > r) rem.push_back(a[i]);
				else sum += a[i], cur.push_back(a[i]);
			}
			sort(begin(cur), end(cur));
			sort(begin(rem), end(rem), greater<int>());
			mx = max(mx, sum);
			for (int i=0; i<k&&i<(int)rem.size()&&i<(int)cur.size(); ++i) {
				sum += rem[i] - cur[i];
				mx = max(mx, sum);
			}
		}
	}
	printf("%d\n", mx);
	return 0;
}

// 7293775	2014-07-30 18:57:25	delta_4d	A - Sereja and Swaps	GNU C++0x	Accepted	140 ms	220 KB
