#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 86;

int n;
long long tot;
vector <int> e[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int gao(int r, int d) {
	int chi = 1;
	for (int i=0; i<(int)e[r].size(); ++i) {
		int c = e[r][i];
		chi += gao(c, d+1);
	}
	tot += n - d - chi;
	return chi;
}

int main() {
	int tc, cn = 0;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=1,a,b; i<n; ++i) {
			a = fastin<int>() - 1, b = fastin<int>() - 1;
			e[a].push_back(b);
		}
		tot = 0;
		gao(0, 0);
		printf("Case %d: %d %lld\n", ++cn, n-1, tot>>1);
	}
	return 0;
}

// 309206	2014-01-08 21:33:38	 1357 - Corrupted Friendship	 C++	 0.104	 11868	Accepted
