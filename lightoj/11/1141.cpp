#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int f[1 << 10];

int main() {
	int tc, cn = 0, s, t;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &s, &t);
		fill(f+s, f+t+1, INF);
		f[s] = 0;
		for (int i=s; i<=t; ++i) {
			int cc = i;
			for (int j=2; j*j<=cc; ++j) if (cc % j == 0) {
				if (i + j <= t) f[i + j] = min(f[i + j], f[i] + 1);
				for (cc/=j; cc%j==0; cc/=j);
			}
			if (cc != i && cc != 1 && i + cc <= t) f[i + cc] = min(f[i + cc], f[i] + 1);
		}
		printf("Case %d: %d\n", ++cn, f[t]==INF?-1:f[t]);
	}
	return 0;
}

// 297241	2013-12-09 21:12:55	 1141 - Number Transformation	 C++	 0.024	 1092	Accepted
