#include <bits/stdc++.h>
using namespace std;

int a[1<<11], b[1<<11];

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", a+i), a[i] = abs(a[i]);
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (a[i] > a[j]) b[i] += 2 * (i < j) - 1;
	for (int i=0; i<n; ++i) if (b[i] > 0) a[i] = -a[i];
	int tot = 0;
	for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) tot += a[i] > a[j];
	printf("%d\n", tot);
	return 0;
}

// 7357477	2014-08-06 08:53:21	delta_4d	E - Jeff and Permutation	GNU C++0x	Accepted	30 ms	0 KB
