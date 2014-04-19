#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1 << 10;

vector <int> e[N];
int f[N][2];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int gao(int x) {
	f[x][0] = 0, f[x][1] = 1;
	for (int i=0; i<(int)e[x].size(); ++i) {
		int y = e[x][i];
		if (f[y][0] >= 0 || f[y][1] >= 0) continue;
		f[x][0] += gao(y);
		f[x][1] += f[y][0];
	}
	return max(f[x][0], f[x][1]);
}

int main() {
	int tc, cn = 0, n, m;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), m = fastin<int>();
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,u,v; i<m; ++i) {
			u = fastin<int>() - 1, v = fastin<int>() - 1;
			e[u].push_back(v), e[v].push_back(u);
		}
		int tot = 0;
		memset(f, -1, sizeof(f));
		for (int i=0; i<n; ++i) if (f[i][0] < 0 && f[i][1] < 0) tot += gao(i);
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 293002	2013-11-29 22:28:16	 1201 - A Perfect Murder	 C++	 0.008	 1244	Accepted
