#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	char s[101], t[101];
	scanf("%d%s", &n, s);
	for (int i=0; i<n; ++i) t[i] = (s[i] -= '0');
	++t[0];
	for (int i=0; i<n; ++i) t[i+1] += t[i] >> 1, t[i] &= 1;
	int tot = 0;
	for (int i=0; i<n; ++i) tot += s[i] ^ t[i];
	printf("%d\n", tot);
	return 0;
}

// 7715666	2014-09-07 23:55:35	delta_4d	A - inc ARG	GNU C++0x	Accepted	15 ms	0 KB
