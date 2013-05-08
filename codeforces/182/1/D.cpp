#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 200000 + 86;

struct BIT {
	int n;
	int x[MAXN + 10];

	void init(int _n=MAXN) {
		n = _n;		
		memset(x, 0, sizeof(x));
	}

	int add(const int p, const int k) {
		for (int i=p; i<=n; i+=i&-i) x[i] += k;	
		return true;
	}

	int sum(const int p) {
		int tot = 0;
		for (int i=p; i>0; i-=i&-i) tot += x[i];
		return tot;
	}
} T;

int x[MAXN], p[MAXN];
int tot[MAXN];
vector <int> L[MAXN];
vector <pair<int, int> > Q[MAXN];

int main() {
	int n, m;	

	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) scanf("%d", p+i), x[p[i]] = i;
	for (int i=1; i<=n; ++i) for (int j=p[i]; j<=n; j+=p[i]) {
		int k = x[j];
		if (i < k) L[k].push_back(i);
		else L[i].push_back(k);
	}
	for (int i=0,l,r; i<m; ++i) {
		scanf("%d%d", &l, &r);	
		Q[r].push_back(make_pair(l, i));
	}
	T.init(n+10);
	for (int i=1; i<=n; ++i) {
		for (int j=0; j<(int)L[i].size(); ++j) T.add(1, 1), T.add(L[i][j]+1, -1);
		for (int j=0; j<(int)Q[i].size(); ++j) tot[Q[i][j].second] = T.sum(Q[i][j].first);
	}
	for (int i=0; i<m; ++i) printf("%d\n", tot[i]);

	return 0;
}

// 3686770	 May 6, 2013 5:24:42 PM	delta_4d	 D - Yaroslav and Divisors	 GNU C++	Accepted	937 ms	29112 KB
