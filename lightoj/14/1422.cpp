#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int> x;
int f[101][101];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		x.resize(n);
		for (int i=0; i<n; ++i) x[i] = fastin<int>();
		x.erase(unique(x.begin(), x.end()), x.end());
		n = (int)x.size();
		memset(f, 0, sizeof(f));
		for (int i=0; i<n; ++i) f[i][i] = 1;
		for (int k=1; k<n; ++k) for (int i=0; i+k<n; ++i) {
			int j = i + k;
			f[i][j] = f[i+1][j] + 1;
			for (int c=i+1; c<=j; ++c) if (x[i] == x[c]) {
				f[i][j] = min(f[i][j], f[i+1][c-1]+f[c][j]);
			}
		}
		printf("Case %d: %d\n", ++cn, f[0][n-1]);
	}
	return 0;
}

// 303321	2013-12-23 22:50:14	 1422 - Halloween Costumes	 C++	 0.040	 1284	Accepted
