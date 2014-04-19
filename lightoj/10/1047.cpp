#include <cstdio>
#include <algorithm>
using namespace std;

int w[20][3];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) for (int j=0; j<3; ++j) scanf("%d", w[i]+j);
		int f[20][3]={0};
		for (int i=0; i<3; ++i) f[0][i] = w[0][i];
		for (int i=1; i<n; ++i) {
			f[i][0] = w[i][0] + min(f[i-1][1], f[i-1][2]);
			f[i][1] = w[i][1] + min(f[i-1][2], f[i-1][0]);
			f[i][2] = w[i][2] + min(f[i-1][0], f[i-1][1]);
		}
		printf("Case %d: %d\n", ++cn, min(f[n-1][0], min(f[n-1][1], f[n-1][2])));
	}
	return 0;
}

// 289735	2013-11-21 20:39:08	 1047 - Neighbor House	 C++	 0.000	 1088	Accepted
