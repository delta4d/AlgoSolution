#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

ll ten[20], f[20];
char s[20];

void init() {
	ten[0] = 1;
	for (int i=1; i<20; ++i) ten[i] = 10 * ten[i-1];
	f[0] = f[1] = 1;
	for (int i=2; i<20; ++i) f[i] = f[i-1] + 9 * (i - 1) * ten[i - 2];
}

ll gao(ll c) {
	if (c < 0) return 0;
	sprintf(s, "%lld", c);
	int len = strlen(s);
	ll tot = 0, pre = 0, suf = c;
	for (int i=1; i<len; ++i) {
		suf = c % ten[len-i-1] + 1;
		pre = pre * 10 + s[i - 1] - '0';
		tot += (pre - ten[i-1]) * ten[len-i-1];
		if (s[i] == '0') tot += suf;
		else tot += ten[len-i-1];
	}
	return tot + f[len - 1];
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll cc, c1, c2;
		scanf("%lld", &cc), c1 = gao(cc-1);
		scanf("%lld", &cc), c2 = gao(cc);
		printf("Case %d: %lld\n", ++cn, c2 - c1);
	}
	return 0;
}

// 256995	2013-08-28 23:36:25	 1140 - How Many Zeroes?	 C++	 0.016	 1088	Accepted
