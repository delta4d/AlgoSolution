#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 60;

int f[N][N][N];
char s1[N], s2[N], s3[N];

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s%s", s1+1, s2+1, s3+1);
		int l1 = strlen(s1+1), l2 = strlen(s2+1), l3 = strlen(s3+1);
		memset(f, 0, sizeof(f));
		for (int i=1; i<=l1; ++i) for (int j=1; j<=l2; ++j) for (int k=1; k<=l3; ++k) {
			if (s1[i] == s2[j] && s2[j] == s3[k]) f[i][j][k] = f[i-1][j-1][k-1] + 1;
			f[i][j][k] = max(f[i-1][j][k], f[i][j][k]);
			f[i][j][k] = max(f[i][j-1][k], f[i][j][k]);
			f[i][j][k] = max(f[i][j][k-1], f[i][j][k]);
		}
		printf("Case %d: %d\n", ++cn, f[l1][l2][l3]);
	}
	return 0;
}

// 291111	2013-11-25 00:38:12	 1159 - Batman	 C++	 0.036	 1932	Accepted
