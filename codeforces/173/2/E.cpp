#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 100000 + 86;
const int MBIT = 63;

struct Trie {
	map <int, Trie> node;
	int ok(const int x) { return node.count(1 - x); }
} T;

LL a[MAXN];

inline int P(const LL x, const int p) { return (x >> p) & 1; }

void insert(Trie &T, const LL x, int p) {
	if (p >= 0) insert(T.node[P(x, p)], x, p-1);	
}

LL cmax(Trie &T, const LL x, int p) {
	if (p < 0) return 0;
	if (T.ok(P(x, p))) return (1ll << p) + cmax(T.node[1 - P(x, p)], x, p-1);
	return cmax(T.node[P(x, p)], x, p-1);
}

int main() {
	int n;
	LL mx, cc = 0, u = 0;

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i], cc ^= a[i];
	insert(T, 0, MBIT);
	mx = cc;
	for (int i=0; i<n; ++i) {
		u ^= a[i], cc ^= a[i];
		insert(T, u, MBIT);	
		mx = max(mx, cmax(T, cc, MBIT));
	}
	cout << mx << endl;

	return 0;
}

// 3323711	 Mar 16, 2013 8:50:15 AM	delta_4d	 282E - Sausage Maximization	 GNU C++	Accepted	1359 ms	134800 KB
