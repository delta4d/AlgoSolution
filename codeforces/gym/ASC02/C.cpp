#include <bits/stdc++.h>
using namespace std;

using ll = long long;
priority_queue <ll> q;

int main() {
#ifdef ONLINE_JUDGE
	freopen("huffman.in", "r", stdin);
	freopen("huffman.out", "w", stdout);
#endif
	ll tot = 0, n;
	scanf("%I64d", &n);
	for (ll i=0,p; i<n; ++i) scanf("%I64d", &p), q.push(-p);
	for (ll c; (int)q.size()>1; ) {
		c = q.top(); q.pop();
		c += q.top(); q.pop();
		tot += c, q.push(c);
	}
	printf("%I64d\n", -tot);
	return 0;
}

// 6973075	 2014-06-28 08:25:47	delta_4d	 C - Hyperhuffman	 GNU C++0x	Accepted	404 ms	6860 KB

