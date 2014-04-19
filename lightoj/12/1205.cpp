#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll s[20], p10[20];
char t[20];

void init() {
	s[1] = s[2] = 9;
	for (int i=3; i<20; i+=2) s[i] = s[i+1] = s[i-2] * 10;
	++s[1];
	for (int i=1; i<20; ++i) s[i] += s[i-1];
	p10[0] = 1;
	for (int i=1; i<20; ++i) p10[i] = p10[i-1] * 10;
}

ll to_s(ll n) {
	sprintf(t, "%lld", n);
	return (ll)strlen(t);
}

ll rev(ll n) {
	ll ret = 0;
	for (; n; ret=ret*10+n%10,n/=10);
	return ret;
}

ll gao(ll n) {
	if (n < 0) return 0ll;
	if (n < 10) return n + 1;
	ll len = to_s(n), tot = s[len - 1], pre = 0, sur = 0;
	for (ll i=0; i+i<len; ++i) pre = pre * 10 + t[i] - '0';
	for (ll i=len>>1; i<len; ++i) sur = sur * 10 + t[i] - '0';
	tot += pre - p10[(len-1)>>1] + 1;
	if (rev(pre) > sur) --tot;
	return tot;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if (a > b) swap(a, b);
		printf("Case %d: %lld\n", ++cn, gao(b)-gao(a-1));
	}
	return 0;
}

// 305024	2013-12-27 22:02:42	 1205 - Palindromic Numbers	 C++	 0.000	 1088	Accepted
