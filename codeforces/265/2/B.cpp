#include <bits/stdc++.h>
using namespace std;
int a[1002];
int main() {
	int n, t = -2;
	scanf("%d", &n);
	for (int i=1; i<=n; scanf("%d",a+(i++)));
	for (int i=1; i<=n; ++i) t += a[i]*(4-a[i-1]-a[i+1]);
	printf("%d\n", max(0,t>>1));
	return 0;
}

// 7715808	2014-09-08 00:11:48	delta_4d	B - Inbox (100500)	GNU C++0x	Accepted	15 ms	0 KB
