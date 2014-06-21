#include <bits/stdc++.h>
using namespace std;

int const N = 5e5 + 100;

int a[N], L[N], R[N];
vector <pair<int,int>> s;

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	for (int i=0; i<n; ++i) L[i] = i - 1, R[i] = i + 1;
	for (int i=0; i<n; ++i) s.push_back(make_pair(a[i], i));
	sort(begin(s), end(s));
	int left = 0, right = n - 1;
	long long tot = 0;
	for (int i=0; i+2<n; ++i) {
		int k = s[i].second, l = L[k], r = R[k];
		if (k == left) tot += a[k], left = r;
		else if (k == right) tot += a[k], right = l;
		else tot += min(a[l], a[r]), R[l] = r, L[r] = l;
	}
	printf("%I64d\n", tot);
	return 0;
}

// 6927831	 2014-06-20 17:11:19	delta_4d	 C - Artem and Array	 GNU C++0x	Accepted	171 ms	12584 KB
