#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
int const INF = 0x3f3f3f3f;

struct triple {
	int s, b, id;
	bool operator<(const triple &rhs) const {
		if (s != rhs.s) return s < rhs.s;
		return b >= rhs.b;
	}
} f[N];
int len[N], idx[N], pre[N];

int main() {
#ifdef ONLINE_JUDGE
	freopen("people.in", "r", stdin);
	freopen("people.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d%d", &f[i].s, &f[i].b), f[i].id = i + 1;
	sort(f, f+n);
	memset(len, 0x3f, sizeof(len));
	for (int i=0; i<n; ++i) {
		int j = lower_bound(len, len+n, f[i].b) - len;
		if (f[i].b == len[j]) continue;
		len[j] = f[i].b, idx[j] = i, pre[i] = j > 0 ? idx[j-1] : -1;
	}
	int m = lower_bound(len, len+n, INF) - len;
	printf("%d\n", m);
	for (int i=idx[m-1]; i>=0; i=pre[i]) printf("%d ", f[i].id);
	return 0;
}

// 6961959	 2014-06-26 12:06:15	delta_4d	 G - Beautiful People	 GNU C++0x	Accepted	 156 ms	 2500 KB
