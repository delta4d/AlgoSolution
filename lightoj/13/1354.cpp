#include <cstdio>
using namespace std;

char s[100];

int t2(char buf[]) {
	int x = 0;
	for (int i=0; i<8; ++i) x = x * 2 + buf[i] - '0';
//	printf("%s %d\n", buf, x);
	return x;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		int a, b, c, d;
		scanf("%d.%d.%d.%d", &a, &b, &c, &d);
		scanf("%s", s);
		if (a == t2(s) && b == t2(s+9) && c == t2(s+18) && d == t2(s+27)) printf("Case %d: Yes\n", ++cn);
		else printf("Case %d: No\n", ++cn);
	}
	return 0;
}

// 252025	2013-08-15 20:55:37	 1354 - IP Checking	 C++	 0.000	 1088	Accepted
