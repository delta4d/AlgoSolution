#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

char s[222];

int main() {
	int tc;
	ll a, b;
	scanf("%d", &tc);
	for (int cn=1; cn<=tc; ++cn) {
		scanf("%s%lld", s, &b);
		a = 0, b = abs(b);
		int i = 0;
		if (s[i] == '-') ++i;
		for (; s[i]; ++i) a = (a * 10 + s[i] - '0') % b;
		printf("Case %d: ", cn);
		if (a) printf("not ");
		puts("divisible");
	}
	return 0;
}

// 249391	2013-08-08 22:44:12	 1214 - Large Division	 C++	 0.004	 1088	Accepted
