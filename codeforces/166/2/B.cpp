#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 512;
const int MAXL = 200000 + 86;
const int INF = 0x3f3f3f3f;

bool is_p[MAXL];
vector <int> p;
int r[MAXN], c[MAXN];

void init() {
	for (int i=2; i<MAXL; ++i) if (!is_p[i]) {
		p.push_back(i);
		for (int j=i<<1; j<MAXL; j+=i) is_p[j] = true;
	}
}

int main() {
	int m, n;
	
	init();
	scanf("%d%d", &m, &n);
	for (int i=0,k; i<m; ++i) for (int j=0; j<n; ++j) {
		scanf("%d", &k);
		k = *lower_bound(p.begin(), p.end(), k) - k;
		r[i] += k;
		c[j] += k;
	}
	int mn = INF;
	for (int i=0; i<m; ++i) mn = min(mn, r[i]);
	for (int i=0; i<n; ++i) mn = min(mn, c[i]);
	printf("%d\n", mn);

	return 0;
}

// 3475403	 Apr 5, 2013 9:37:39 AM	delta_4d	 271B - Prime Matrix	 GNU C++	Accepted	93 ms	500 KB
