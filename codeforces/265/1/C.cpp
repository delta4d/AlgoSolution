#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int const N = 2e5 + 10;
ll const M = 1e9 + 7;

ll v[26], l[26];
char s[N], buf[N];
vector <pair<int,string>> tran;

ll powM(ll x, ll e) {
	ll r = 1;
	for (; e; e>>=1,x=x*x%M) if (e&1) r=r*x%M;
	return r;
}

int main() {
	for (int i=0; i<10; ++i) v[i] = i, l[i] = 1;
	int n;
	scanf("%s%d", s, &n), gets(buf);
	for (int i=0; i<n; ++i) {
		gets(buf);
		int len = (int)strlen(buf);
		if (buf[len-1] == '>') {
			tran.push_back({buf[0]-'0', ""});
		} else {
			tran.push_back({buf[0]-'0', string(buf+3)});
		}
	}
	reverse(begin(tran), end(tran));
	for (auto &p: tran) {
		int d = p.first;
		if (p.second.empty()) {
			v[d] = 0, l[d] = 0;
		} else {
			strcpy(buf, p.second.c_str());
			ll cc = 0, le = 0;
			for (int i=0; buf[i]; ++i) {
				int k = buf[i] - '0';
				if (!l[k]) continue;
				ll b = powM(10, l[k]);
				cc = (cc * b + v[k]) % M;
				le = (le + l[k]) % (M - 1);
			}
			v[d] = cc, l[d] = le;
		}
	}
	ll sum = 0;
	for (int i=0; s[i]; ++i) {
		int k = s[i] - '0';
		if (!l[k]) continue;
		ll b = powM(10, l[k]);
		sum = (sum * b + v[k]) % M;
	}
	printf("%d\n", (int)sum);
	return 0;
}

// 7716917	2014-09-08 04:42:38	delta_4d	C - Substitutes in Number	GNU C++0x	Accepted	124 ms	4000 KB
