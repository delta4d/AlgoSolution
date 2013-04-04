#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 80000 + 86;

#define SZ(x) (int)x.size()

vector <int> T[MAXN];
LL s[MAXN], tot;
LL n;

inline LL sqr(const LL x) { return x * x; }

void dfs(int r, int p) {
	for (int i=0; i<SZ(T[r]); ++i) {
		int c = T[r][i];
		if (c == p) continue;
		dfs(c, r);
		s[r] += s[c];
	}	
	LL cc = s[r]++;
	for (int i=0; i<SZ(T[r]); ++i) {
		int c = T[r][i];
		if (c == p) continue;
		cc += (s[r] - s[c]) * s[c];	
	}
	cc >>= 1;
	tot -= cc * cc + cc * s[r] * (n - s[r]) * 2;
}

int main() {
	ios_base::sync_with_stdio(false);

	int x, y;

	cin >> n;
	for (int i=1; i<n; ++i) {
		cin >> x >> y;
		--x, --y;
		T[x].push_back(y);
		T[y].push_back(x);
	}
	
	tot = sqr(n * (n - 1) >> 1);
	dfs(0, -1);
//	for (int i=0; i<n; ++i) cout << s[i] << ' '; cout << endl;
	cout << tot << endl;

	return 0;
}

// 3470030	 Apr 3, 2013 8:49:52 PM	delta_4d	 288D - Polo the Penguin and Trees	 GNU C++	Accepted	93 ms	8700 KB
